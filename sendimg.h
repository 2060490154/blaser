#ifndef SENDIMG_H
#define SENDIMG_H

#include <QObject>
#include "opencv.hpp"
#include <QDebug>

using namespace cv;

class sendimg : public QObject
{
    Q_OBJECT
public:
    explicit sendimg(int db_n, QString db, QString hos, QString use, QString pwd, int por, QString tablename, QString info, int n, int p, QString time, int i, int d, Mat img, Mat img_d, QObject *parent = nullptr);
    void addconnect(const QString dbname, const QString host, const QString user, const QString passwd, int port);
    void send();
    Mat img_1;
    Mat img_1_d;
    QString table;
    QString testinfo;
    int round_num;
    int test_point;
    QString time_str;
    int B_or_A;
    int defect;
    int j;
    QString connStr;
    QString connName;
    QString connDriver;
    QString dbHost;
    int dbPort;
    ~sendimg() { qDebug() << "sendimg destroyed"; }

signals:
    void finish();

public slots:
};

#endif // SENDIMG_H
