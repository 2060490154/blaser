#include "sendimg.h"
#include <QDebug>
#include <QSqlQuery>
#include "opencv.hpp"
#include <QImage>
#include <QVariant>
#include <QBuffer>
#include <QThread>
#include <QSqlError>

using namespace cv;

sendimg::sendimg(int db_n,QString db, QString hos, QString use, QString pwd, int por, QString tablename, QString info, int n, int p, QString time, int i, int d, Mat img, Mat img_d, QObject *parent) : QObject(parent)
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
    img_1_d = img_d;

}

void sendimg::addconnect(const QString dbname, const QString host, const QString user, const QString passwd, int port)
{
        QSqlDatabase db = QSqlDatabase::addDatabase("QTDS",QString("connect%1").arg(j));
        db.setDatabaseName(dbname);
        db.setHostName(host);
        db.setPort(port);
        db.open(user,passwd);
}

void sendimg::send()
{
        //qDebug()<<"4 current thread:"<<QThread::currentThreadId();
        QSqlQuery query;
        QByteArray data_d;
        QByteArray data;
        cvtColor(img_1,img_1,COLOR_BGR2RGB);
        cvtColor(img_1_d,img_1_d,COLOR_BGR2RGB);


        QImage QImg_d = QImage((const unsigned char*)(img_1_d.data),img_1_d.cols,img_1_d.rows,QImage::Format_RGB888);
        QBuffer buffer_d(&data_d);
        buffer_d.open(QIODevice::WriteOnly);
        QImg_d.save(&buffer_d,"jpg");
        QVariant var1(data_d);



        QImage QImg = QImage((const unsigned char*)(img_1.data),img_1.cols,img_1.rows,QImage::Format_RGB888);
        QBuffer buffer(&data);
        buffer.open(QIODevice::WriteOnly);
        QImg.save(&buffer,"jpg");
        QVariant var(data);

        QString sql = QString("insert into %1 (ExpNo,pointNo,shotNo,imagedata,imagetype,defect,time,defectimage) values(?,?,?,?,?,?,?,?)").arg(table);
        query.prepare(sql);
        query.addBindValue(testinfo);
        query.addBindValue(test_point);
        query.addBindValue(round_num);
        query.addBindValue(var);
        query.addBindValue(B_or_A);
        query.addBindValue(defect);
        query.addBindValue(time_str);
        query.addBindValue(var1);
            if(query.exec())
                emit finish();
            else
            {
                qDebug()<<"trans defeat";
                qDebug()<<query.lastError().text();
                emit finish();
            }
}
