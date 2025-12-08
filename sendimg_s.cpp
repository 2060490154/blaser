#include "sendimg_s.h"
#include <QSqlQuery>
#include "opencv.hpp"
#include <QImage>
#include <QVariant>
#include <QBuffer>
#include <QThread>
#include <QSqlError>
#include <QElapsedTimer>

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

sendimg_s::sendimg_s(int db_n, QString db, QString hos, QString use, QString pwd, int por, QString tablename, QString info, int n, int p, QString time, int i, int d, Mat img, QObject *parent) : QObject(parent)
{
    addconnect(db,hos,use,pwd,por);
    j = db_n;
    B_or_A = i;
    img_1 = img;
    table = tablename;
    testinfo = info;
    round_num = n;
    test_point = p;
    time_str = time;
    defect = d;
}

void sendimg_s::addconnect(const QString dbname, const QString host, const QString user, const QString passwd, int port)
{
    QStringList drivers = QSqlDatabase::drivers();
    QString connName = QString("connect%1").arg(j);
    QString selectedDriver;

    if (drivers.contains("QTDS")) {
        selectedDriver = "QTDS";
    }
    else if (drivers.contains("QODBC")) {
        selectedDriver = "QODBC"; // use ODBC with FreeTDS
    }
    else {
        qDebug() << "sendimg_s: No suitable Qt SQL driver found";
        return;
    }

    // Store connection info; actual DB connection will be created inside send() worker thread
    this->connDriver = selectedDriver;
    this->connName = connName;
    this->dbHost = host;
    this->dbPort = port;
    if (selectedDriver == "QTDS") {
        this->connStr = dbname;
    } else {
        this->connStr = QString("Driver={FreeTDS};Server=%1,%2;Database=%3;Uid=%4;Pwd=%5;TDS_Version=7.4;")
                        .arg(host).arg(port).arg(dbname).arg(user).arg(passwd);
    }
}

void sendimg_s::send()
{
    QElapsedTimer time1;
    time1.start();
    qDebug() << "sendimg_s::send called j=" << j << "table=" << table;
    QString connNameLocal = QString("sendconn_s_%1_%2").arg((quintptr)QThread::currentThreadId()).arg(j);
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
        qDebug() << "sendimg_s: connStr=" << this->connStr;
        qDebug() << "sendimg_s::send available drivers:" << QSqlDatabase::drivers();
        if (!db.open()) {
            qDebug() << "sendimg_s: DB open failed:" << db.lastError().text();
            QSqlDatabase::removeDatabase(connNameLocal);
            emit finish();
            return;
        }

            {
                QSqlQuery query(db);
            QByteArray data;
            cvtColor(img_1,img_1,COLOR_BGR2RGB);

            QImage QImg = QImage((const unsigned char*)(img_1.data),img_1.cols,img_1.rows,QImage::Format_RGB888);
            QBuffer buffer(&data);
            buffer.open(QIODevice::WriteOnly);
            QImg.save(&buffer,"jpg");
            QVariant var(data);

            // Build INSERT using only the columns that actually exist in the DB table
            QStringList cols = getTableColumns(db, table);
            qDebug() << "sendimg_s: table cols=" << cols;

            QStringList wantedCols;
            wantedCols << "ExpNo" << "pointNo" << "shotNo" << "imagedata" << "imagetype" << "defect" << "time";
            QStringList actualCols;
            QList<QVariant> bindValues;
            for (const QString &c : wantedCols) {
                // find column in cols ignoring case
                bool found = false;
                for (const QString &col : cols) {
                    if (QString::compare(col, c, Qt::CaseInsensitive) == 0) {
                        actualCols << col; // preserve actual case
                        found = true;
                        break;
                    }
                }
                if (found) {
                    // push the corresponding bind value
                    if (c == "ExpNo") bindValues << QVariant(testinfo);
                    else if (c == "pointNo") bindValues << QVariant(test_point);
                    else if (c == "shotNo") bindValues << QVariant(round_num);
                    else if (c == "imagedata") bindValues << QVariant(var);
                    else if (c == "imagetype") bindValues << QVariant(B_or_A);
                    else if (c == "defect") bindValues << QVariant(defect);
                    else if (c == "time") bindValues << QVariant(time_str);
                }
            }

            if (actualCols.isEmpty()) {
                qDebug() << "sendimg_s: none of the expected columns are present in" << table << ":" << wantedCols;
            } else {
                // Escape column names to avoid reserved-word problems
                QStringList actualColsEsc;
                for (const QString &c : actualCols) actualColsEsc << QString("[%1]").arg(c);
                QStringList placeholders;
                for (int k = 0; k < actualCols.size(); ++k) placeholders << "?";
                QString sql = QString("INSERT INTO %1 (%2) VALUES (%3)")
                        .arg(table)
                        .arg(actualColsEsc.join(","))
                        .arg(placeholders.join(","));
                // Above repeated trick builds ?,?,? placeholders
                query.prepare(sql);
                for (const QVariant &v : bindValues) query.addBindValue(v);
            qDebug() << "sendimg_s::send SQL:" << sql;
            if (query.exec()) {
                qsuccess = true;
                qDebug() << "sendimg_s: upload success for table" << table;
            } else {
                qsuccess = false;
                qLastError = query.lastError().text();
                qLastQuery = query.lastQuery();
                qDebug() << "sendimg_s: trans defeat";
                qDebug() << "QSqlQuery last error:" << qLastError;
                qDebug() << "QSqlQuery last query:" << qLastQuery;
            }
        }

        db.close();
    }
    // Now that local QSqlQuery and QSqlDatabase objects are out of scope/destroyed, remove connection
    QSqlDatabase::removeDatabase(connNameLocal);
    qDebug() << "sendimg_s: connStr=" << this->connStr;
    qDebug() << "sendimg_s::send available drivers:" << QSqlDatabase::drivers();
    qDebug() << time1.elapsed() << "ms";
    qDebug() << "sendimg_s: success=" << qsuccess << " lastErr=" << qLastError << " lastQuery=" << qLastQuery;
    // Emit finish only after all DB handles are destroyed and removed
    emit finish();
}

// end sendimg_s.cpp
}
    
