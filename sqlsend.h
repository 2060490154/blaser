#ifndef SQLSEND_H
#define SQLSEND_H

#include <QObject>
#include <QString>
#include <QDateTime>
#include <QThread>
#include <opencv.hpp>
#include <memory>
#include "sendimg.h"
#include "guicamera.h"   // use CGuiCamera (Pylon wrapper)

using namespace cv;

class SQLsend : public QObject
{
    Q_OBJECT
public:
    // Constructor now accepts a camera pointer (Pylon wrapper) instead of Pixelink HANDLE
        SQLsend(QString db, QString hos, QString use, QString pwd, int por, QString tablen,
            CGuiCamera *camPtr, int model, int point, int num, QString info, int pixe_real, int defect_point, int defect_all, QObject *parent = nullptr);

    void capture(Mat &img);

public slots:
    void getinfo(char p, char n);
    void start_deal();

signals:
    void get_src(bool OK);
    void senddamage(float d);
    void sendcap(bool c);
    void finish();

private:
    void toSQL(int db_n, QString tablename, QString info, int n, int p, QString time, int i, int d, Mat img, Mat img_d);
    void toSQL_s(int db_n, QString tablename, QString info, int n, int p, QString time, int i, int d, Mat img);

    void Delay_MSec(unsigned int msec);

    // DB params
    QString database;
    QString host;
    QString user;
    QString pwsd;
    int port;
    QString table;
    QString TestInfo;

    // Camera reference (Pylon wrapper)
    CGuiCamera *m_cam;

    // various processing params
    int pixe;
    int point_max;
    int defect_max;
    int TestModel;
    int TestPoint;
    int TestNum;

    QDateTime *datetime;
    bool HaveCap;
    int i;
};

#endif // SQLSEND_H
