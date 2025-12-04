#include "sqlsend.h"
#include <QImage>
#include <QVariant>
#include <QBuffer>
#include <QDebug>
#include <QThread>
#include <QTimer>
#include <QEventLoop>
#include "sendimg_s.h"
#include <QMessageBox>
#include <QSqlError>

#define pi 3.14157

using namespace std;

SQLsend::SQLsend(QString db, QString hos, QString use, QString pwd, int por, QString tablen,
                 CGuiCamera *camPtr, int model, int point, int num, QString info, int pixe_real, int defect_point, int defect_all, QObject *parent)
    : QObject(parent),
    m_cam(camPtr)
{
    database = db;
    host = hos;
    user = use;
    pwsd = pwd;
    port = por;
    table = tablen;
    TestModel = model;
    TestPoint = point;
    TestNum = num;
    TestInfo = info;
    pixe = pixe_real;
    point_max = defect_point;
    defect_max = defect_all;
    HaveCap = false;
    i = 0;
    datetime = new QDateTime(QDateTime::currentDateTime());
}

/*
 * Capture wrapper: delegates to camera->capture(Mat&)
 */
void SQLsend::capture(Mat &img)
{
    if (m_cam)
        m_cam->capture(img);
    else
        img = Mat();
}

void SQLsend::getinfo(char p, char n)
{
    if(p != TestPoint) {
        // reset area on new point
    }
    HaveCap = false;
    emit sendcap(HaveCap);
    TestPoint = p;
    TestNum = n;

    Mat img0;
    capture(img0);
    if (!img0.empty())
    {
        qDebug() << "get src";
        // Call toSQL_s to upload source image
        toSQL_s(i++, table, TestInfo, TestNum, TestPoint, QDateTime::currentDateTime().toString("hhmm"), 0, 0, img0);
        emit get_src(true);
    }
    else
        emit get_src(false);
}

void SQLsend::start_deal()
{
    Mat img_0, img_1, img_1_src, img_2, img_defect;
    capture(img_0);
    if (img_0.empty()) {
        QMessageBox::warning(NULL,"error","拍摄前图像采集失败");
        return;
    }
    // convert to gray and processing as previous logic
    cvtColor(img_0, img_0, COLOR_RGB2GRAY);

    capture(img_1);
    if (img_1.empty()) {
        QMessageBox::warning(NULL,"error","打后图像采集失败");
        return;
    }

    qDebug() << "get after pic";
    HaveCap = true;
    emit sendcap(HaveCap);

    img_1_src = img_1.clone();
    img_defect = img_1.clone();

    cvtColor(img_1, img_1, COLOR_RGB2GRAY);

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    absdiff(img_1, img_0, img_2);

    int Channels[] = { 0 };
    int nHistSize[] = { 256 };
    float range[] = { 0, 255 };
    const float* fHistRanges[] = { range };
    Mat hist;
    calcHist(&img_2, 1, Channels, Mat(), hist, 1, nHistSize, fHistRanges, true, false);
    int thred = 10;
    for (int iHist = 2; iHist < 253; iHist++)
    {
        if ((cvRound(hist.at<uchar>(iHist) <= cvRound(hist.at<uchar>(iHist + 1)))) &&
            (cvRound(hist.at<uchar>(iHist + 1)) <= cvRound(hist.at<uchar>(iHist + 2))))
        {
            thred = iHist;
            break;
        }
    }
    threshold(img_2, img_2, thred, 255, 0);

    Mat out;
    Mat element = getStructuringElement(MORPH_RECT, Size(5, 5));
    morphologyEx(img_2, out, MORPH_OPEN, element);

    findContours(out, contours, hierarchy, RETR_CCOMP, CHAIN_APPROX_NONE);
    int area;
    float total_area = 0;
    float diameter, equi_diameter;
    Scalar color(0,0,255);
    for (size_t index=0; index<contours.size(); index++)
    {
        area = contourArea(contours[index]);
        diameter = pixe*sqrt(4*area/pi);
        if (diameter >= point_max)
        {
            total_area += area;
            drawContours(img_defect, contours, index, color, 1, 8, hierarchy);
        }
    }
    equi_diameter = pixe*sqrt(4*total_area/pi);

    if (equi_diameter >= defect_max)
    {
        toSQL(i++, table, TestInfo, TestNum, TestPoint, QDateTime::currentDateTime().toString("hhmm"), 1, 1, img_1_src, img_defect);
        qDebug() << "defect pic trans";
    }
    else
    {
        toSQL_s(i++, table, TestInfo, TestNum, TestPoint, QDateTime::currentDateTime().toString("hhmm"), 1, 0, img_1_src);
    }
    emit senddamage(equi_diameter);
    qDebug() << "deal complete";
}

void SQLsend::toSQL(int db_n, QString tablename, QString info, int n, int p, QString time, int i, int d, Mat img,  Mat img_d)
{
    sendimg *img_s = new sendimg(db_n, database, host, user, pwsd, port, tablename, info, n, p, time, i, d, img, img_d);
    QThread *threadsend = new QThread;
    img_s->moveToThread(threadsend);
    threadsend->start();

    connect(threadsend, &QThread::started, img_s, &sendimg::send);
    connect(img_s, SIGNAL(finish()), img_s, SLOT(deleteLater()));
    connect(img_s, SIGNAL(destroyed()), threadsend, SLOT(quit()));
    connect(threadsend, SIGNAL(finished()), threadsend, SLOT(deleteLater()));
}

void SQLsend::toSQL_s(int db_n, QString tablename, QString info, int n, int p, QString time, int i, int d, Mat img)
{
    // sendimg_s has similar behavior (not modified here), ensure it uses ODBC in the same way
    // Call the sendimg_s constructor directly
    sendimg_s *img_s = new sendimg_s(db_n, database, host, user, pwsd, port, tablename, info, n, p, time, i, d, img);
    QThread *threadsend = new QThread;
    img_s->moveToThread(threadsend);
    threadsend->start();

    connect(threadsend, &QThread::started, img_s, &sendimg_s::send);
    connect(img_s, SIGNAL(finish()), img_s, SLOT(deleteLater()));
    connect(img_s, SIGNAL(destroyed()), threadsend, SLOT(quit()));
    connect(threadsend, SIGNAL(finished()), threadsend, SLOT(deleteLater()));
}

void SQLsend::Delay_MSec(unsigned int msec)
{
    QEventLoop loop;
    QTimer::singleShot(msec, &loop, SLOT(quit()));
    loop.exec();
}
