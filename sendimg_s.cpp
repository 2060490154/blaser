#include "sendimg_s.h"
#include <QSqlQuery>
#include "opencv.hpp"
#include <QImage>
#include <QVariant>
#include <QBuffer>
#include <QThread>
#include <QSqlError>
#include <QTime>

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
    QSqlDatabase db = QSqlDatabase::addDatabase("QTDS",QString("connect%1").arg(j));
    db.setDatabaseName(dbname);
    db.setHostName(host);
    db.setPort(port);
    if(!db.open(user,passwd))
        qDebug()<<"connect sqlserver wrong";
}

void sendimg_s::send()
{
    QTime time1;
    time1.start();
    QSqlQuery query;
    QByteArray data;
    cvtColor(img_1,img_1,COLOR_BGR2RGB);

    QImage QImg = QImage((const unsigned char*)(img_1.data),img_1.cols,img_1.rows,QImage::Format_RGB888);
    QBuffer buffer(&data);
    buffer.open(QIODevice::WriteOnly);
    QImg.save(&buffer,"jpg");
    QVariant var(data);

    QString sql = QString("insert into %1 (ExpNo,pointNo,shotNo,imagedata,imagetype,defect,time) values(?,?,?,?,?,?,?)").arg(table);
    query.prepare(sql);
    query.addBindValue(testinfo);
    query.addBindValue(test_point);
    query.addBindValue(round_num);
    query.addBindValue(var);
    query.addBindValue(B_or_A);
    query.addBindValue(defect);
    query.addBindValue(time_str);
    if(query.exec())
        emit finish();
    else
    {
        qDebug()<<"trans defeat";
        qDebug()<<query.lastError().text();
        emit finish();
    }
    qDebug()<<time1.elapsed()<<"ms";
}
