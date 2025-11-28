#ifndef SQLSEND_H
#define SQLSEND_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <opencv.hpp>
#include <imgproc.hpp>
#include <highgui.hpp>
#include <QByteArray>
#include <QDir>
#include <QDateTime>
#include <QTimer>
#include "camera.h"
#include "gpio.h"
#include "sendimg.h"
#include "sendimg_s.h"
#include <QThread>
#include <QEventLoop>

using namespace cv;

class SQLsend : public QObject
{
    Q_OBJECT
public:
    explicit SQLsend(QString db, QString hos, QString use, QString pwd, int por, QString tablen, HANDLE camera,int model,int point,int num,QString info,int pixe_real,int defect_point,int defect_all,QObject *parent = 0);
    int timer1;
    QDir *dir = new QDir;
    QDateTime *datetime = new QDateTime;
    void toSQL(int db_n,QString tablename, QString info,int n,int p,QString time,int i, int d,Mat img,  Mat img_d);
    void toSQL_s(int db_n,QString tablename, QString info,int n,int p,QString time,int i, int d,Mat img);
    void capture(Mat &img);
    HANDLE cameraname;
    int TestModel;
    int TestPoint;
    int TestNum;
    QString TestInfo;
    unsigned int gpio_value = low;
    GPIO *gpio = new GPIO;

    int pixe;
    int point_max;
    int defect_max;

    bool gpio_creat = false;
    jetsonTX2GPIONumber plus = gpio480;



signals:
    void senddamage(float d);
    void sendcap(bool cap);
    void get_src(bool s);

public slots:
    void count();

private slots:
    void getinfo(char p,char n);
    void start_deal();
private:
    QString table;
    QString database;
    QString host;
    QString user;
    QString pwsd;
    int port;
    bool HaveCap;
    int m = 0;
    int total_area=0;

    void Delay_MSec(unsigned int msec);
};

#endif // SQLSEND_H
