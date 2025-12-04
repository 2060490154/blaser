#include "sendimg.h"
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QBuffer>
#include <QImage>
#include <QVariant>
#include <QDebug>
#include <QSqlError>
#include <QThread>
using namespace cv;

// Helper: get list of columns for a table (case-insensitive match)
static QStringList getTableColumns(QSqlDatabase &db, const QString &table)
{
    QStringList cols;
    QSqlQuery q(db);
    QString schemaSql = QString("SELECT COLUMN_NAME FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = '%1'").arg(table);
    if (!q.exec(schemaSql)) {
        qDebug() << "getTableColumns: failed to query INFORMATION_SCHEMA.COLUMNS:" << q.lastError().text();
        return cols;
    }
    while (q.next()) {
        cols << q.value(0).toString();
    }
    return cols;
}

/*
 * sendimg: constructs its own QODBC connection using a DSN-less connection string.
 * For MS SQL on ARM, FreeTDS ODBC is recommended. If system has "ODBC Driver 17 for SQL Server",
 * the driver string will be adapted accordingly.
 */

sendimg::sendimg(int db_n, QString db, QString hos, QString use, QString pwd, int por, QString tablename, QString info, int n, int p, QString time, int i, int d, Mat img, Mat img_d, QObject *parent)
    : QObject(parent)
{
    j = db_n;
    B_or_A = i;
    img_1 = img;
    img_1_d = img_d;
    table = tablename;
    testinfo = info;
    round_num = n;
    test_point = p;
    time_str = time;
    defect = d;

    addconnect(db, hos, use, pwd, por);
}

void sendimg::addconnect(const QString dbname, const QString host, const QString user, const QString passwd, int port)
{
    // Compose DSN-less ODBC connection string
    // Try to detect driver names: prefer "ODBC Driver 17 for SQL Server" if installed, else fall back to FreeTDS driver
    QString driverName;
    // We can't query installed drivers reliably here - the README instructs user to ensure driver is installed.
    // We'll try FreeTDS by default (common on ARM Debian). Users can change to "ODBC Driver 17 for SQL Server" if available.
    driverName = "FreeTDS";

    QString conn = QString("Driver={%1};Server=%2,%3;Database=%4;Uid=%5;Pwd=%6;TDS_Version=8.0;")
            .arg(driverName)
            .arg(host)
            .arg(port)
            .arg(dbname)
            .arg(user)
            .arg(passwd);

    this->connStr = conn;
    this->connName = QString("connect%1").arg(j);
    this->connDriver = driverName;
    this->dbHost = host;
    this->dbPort = port;
}

void sendimg::send()
{
    qDebug() << "sendimg::send called (j)" << j << "table=" << table;
    QString connNameLocal = QString("sendconn_%1_%2").arg((quintptr)QThread::currentThreadId()).arg(j);
    QString driverToUse = (this->connDriver == "QTDS" ? "QTDS" : "QODBC");
    bool qsuccess = false;
    QString qLastError;
    QString qLastQuery;
    {
            QSqlDatabase db = QSqlDatabase::addDatabase(driverToUse, connNameLocal);
            if (driverToUse == "QTDS") {
                db.setDatabaseName(this->connStr);
                db.setHostName(this->dbHost);
                db.setPort(this->dbPort);
            } else {
                db.setDatabaseName(this->connStr);
            }
            qDebug() << "sendimg: connStr=" << this->connStr;
            qDebug() << "sendimg::send available drivers:" << QSqlDatabase::drivers();
            if (!db.open())
            {
                qDebug() << "sendimg: DB open failed:" << db.lastError().text();
                QSqlDatabase::removeDatabase(connNameLocal);
                emit finish();
                return;
            }

            {
                QSqlQuery query(db);
                QByteArray data, data_d;

                if (!img_1.empty())
                    cvtColor(img_1, img_1, COLOR_BGR2RGB);
                if (!img_1_d.empty())
                    cvtColor(img_1_d, img_1_d, COLOR_BGR2RGB);

                if (!img_1_d.empty())
                {
                    QImage QImg_d((const unsigned char*)(img_1_d.data), img_1_d.cols, img_1_d.rows, QImage::Format_RGB888);
                    QBuffer buffer_d(&data_d);
                    buffer_d.open(QIODevice::WriteOnly);
                    QImg_d.save(&buffer_d, "jpg");
                }

                if (!img_1.empty())
                {
                    QImage QImg((const unsigned char*)(img_1.data), img_1.cols, img_1.rows, QImage::Format_RGB888);
                    QBuffer buffer(&data);
                    buffer.open(QIODevice::WriteOnly);
                    QImg.save(&buffer, "jpg");
                }

                // Build INSERT using only the columns that actually exist in the DB table
                QStringList cols = getTableColumns(db, table);
                qDebug() << "sendimg: table cols=" << cols;

                QStringList wantedCols;
                wantedCols << "ExpNo" << "pointNo" << "shotNo" << "imagedata" << "imagetype" << "defect" << "time" << "defectimage";
                QStringList actualCols;
                QList<QVariant> bindValues;
                for (const QString &c : wantedCols) {
                    bool found = false;
                    for (const QString &col : cols) {
                        if (QString::compare(col, c, Qt::CaseInsensitive) == 0) {
                            actualCols << col;
                            found = true;
                            break;
                        }
                    }
                    if (found) {
                        if (c == "ExpNo") bindValues << QVariant(testinfo);
                        else if (c == "pointNo") bindValues << QVariant(test_point);
                        else if (c == "shotNo") bindValues << QVariant(round_num);
                        else if (c == "imagedata") bindValues << QVariant(data);
                        else if (c == "imagetype") bindValues << QVariant(B_or_A);
                        else if (c == "defect") bindValues << QVariant(defect);
                        else if (c == "time") bindValues << QVariant(time_str);
                        else if (c == "defectimage") bindValues << QVariant(data_d);
                    }
                }

                if (actualCols.isEmpty()) {
                    qDebug() << "sendimg: none of the expected columns are present in" << table << ":" << wantedCols;
                } else {
                    QStringList actualColsEsc;
                    for (const QString &c : actualCols) actualColsEsc << QString("[%1]").arg(c);
                    QStringList placeholders;
                    for (int k = 0; k < actualCols.size(); ++k) placeholders << "?";
                    QString sql = QString("INSERT INTO %1 (%2) VALUES (%3)")
                            .arg(table)
                            .arg(actualColsEsc.join(","))
                            .arg(placeholders.join(","));
                    query.prepare(sql);
                    for (const QVariant &v : bindValues) query.addBindValue(v);
                    qDebug() << "sendimg::send SQL:" << sql;
                    if (query.exec()) {
                        qDebug() << "sendimg: upload success for table" << table;
                        qsuccess = true;
                    } else {
                        qLastError = query.lastError().text();
                        qLastQuery = query.lastQuery();
                        qDebug() << "trans defeat:" << qLastError;
                        qDebug() << "QSqlQuery last query:" << qLastQuery;
                        qsuccess = false;
                    }
                }

                // SQL executed above
            }

            db.close();
        }
        QSqlDatabase::removeDatabase(connNameLocal);
    qDebug() << "sendimg: connStr=" << this->connStr;
    qDebug() << "sendimg::send available drivers:" << QSqlDatabase::drivers();
    qDebug() << "sendimg: success=" << qsuccess << " lastErr=" << qLastError << " lastQuery=" << qLastQuery;
    emit finish();
}
