#ifndef DEAL_H
#define DEAL_H

#include <QMainWindow>
#include "opencv.hpp"
#include <imgproc.hpp>
#include <highgui.hpp>
#include "imagewidget.h"
#include <QDesktopWidget>
#include "rulersettings.h"
#include <imgproc.hpp>

#define pi 3.14157

using namespace cv;
using namespace std;

struct damage_P
{
    QString P_name;
    float P_diameter;
    int P_X;
    int P_Y;
};

namespace Ui {
class deal;
}

class deal : public QMainWindow
{
    Q_OBJECT

public:
    explicit deal(QWidget *parent = 0);
    ~deal();
    void imgProc(float contrast,int bright);
    int contrastvalue();
    int brightvalue();
    void analysis(Mat img1,Mat img2,Mat &img3,int &i,float &d);
    void recvShowPicSignal(QImage image);//接收并显示图片的函数


    damage_P dia[100];

private:
    Ui::deal *ui;
    Mat myImg;
    QImage myQImg;

    Mat myImg_b;
    Mat myImg_f;
    Mat myImg_r;
    rulersettings *ruler = new rulersettings;
    ImageWidget     *m_Image;

private slots:
    void receiveruler_parameters(QString p,QString h,QString t);

};

#endif // DEAL_H
