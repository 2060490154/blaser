#ifndef SENDIMG_S_H
#define SENDIMG_S_H

#include <QObject>
#include "opencv.hpp"
#include <QDebug>

using namespace cv;

class sendimg_s : public QObject
{
    Q_OBJECT
public:
    explicit sendimg_s(int db_n,QString db, QString hos, QString use, QString pwd, int por,QString tablename, QString info,int n,int p,QString time,int i, int d,Mat img,QObject *parent = 0);
    void addconnect(const QString dbname, const QString host, const QString user, const QString passwd, int port);
    void send();
    Mat img_1;
    QString table;
    QString testinfo;
    int round_num;
    int test_point;
    QString time_str;
    int B_or_A;
    int defect;
    int j;

    ~sendimg_s()
    {
        //emit over();
        qDebug()<<"~~~~b";
    }


signals:
    void finish();
    //void over();

public slots:
};

#endif // SENDIMG_S_H
