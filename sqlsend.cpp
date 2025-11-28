#include "sqlsend.h"
#include <QImage>
#include <QVariant>
#include <QBuffer>
#include <QDebug>
#include <QThread>
#include <QTimer>
#include <QTimerEvent>
#include "camera.h"
#include <QTime>
#include <QDateTime>
#include <QMessageBox>

#define pi 3.14157


int i=0;

using namespace std;

Mat img_0,img_1,img_1_src,img_2,img_defect;

SQLsend::SQLsend(QString db, QString hos, QString use, QString pwd, int por, QString tablen, HANDLE camera, int model, int point, int num, QString info, int pixe_real, int defect_point, int defect_all, QObject *parent) : QObject(parent)
{
    cameraname = camera;
    table = tablen;
    database = db;
    host = hos;
    user = use;
    pwsd = pwd;
    port = por;
    TestModel = model;
    TestPoint = point;
    TestNum = num;
    TestInfo = info;
    pixe = pixe_real;
    point_max = defect_point;
    defect_max = defect_all;

    HaveCap = false;
}


void SQLsend::capture(Mat &img)
{
    std::vector<U8> frameBuffer(4000 * 4000 * 2);
    FRAME_DESC frameDesc;
    frameDesc.uSize = sizeof(FRAME_DESC);
    U32 imageBufferSize = frameBuffer.size() * 3;
    std::vector<U8> imageBuffer(imageBufferSize);
    PxLGetNextFrame(cameraname, (U32)frameBuffer.size(), &frameBuffer[0], &frameDesc);
    PxLFormatImage(&frameBuffer[0], &frameDesc, IMAGE_FORMAT_RAW_BGR24, &imageBuffer[0],
            &imageBufferSize);
    Mat openCVImage((int)(frameDesc.Roi.fHeight/frameDesc.PixelAddressingValue.fVertical),
                    (int)(frameDesc.Roi.fWidth/ frameDesc.PixelAddressingValue.fHorizontal),
                    CV_8UC3,
                    &imageBuffer[0]);
    img = openCVImage.clone();
}



void SQLsend::toSQL(int db_n, QString tablename, QString info, int n, int p, QString time, int i, int d, Mat img,  Mat img_d)
{
    sendimg *img_s;
    QThread *threadsend;
    img_s = new sendimg(db_n,database,host,user,pwsd,port,tablename,info,n,p,time,i,d,img,img_d);
    threadsend = new QThread;
    img_s->moveToThread(threadsend);
    threadsend->start();

    connect(threadsend,&QThread::started,img_s,&sendimg::send);
    connect(img_s,SIGNAL(finish()),img_s,SLOT(deleteLater()));
    connect(img_s,SIGNAL(destroyed()),threadsend,SLOT(quit()));
    connect(threadsend,SIGNAL(finished()),threadsend,SLOT(deleteLater()));
}

void SQLsend::toSQL_s(int db_n, QString tablename, QString info, int n, int p, QString time, int i, int d, Mat img)
{
    sendimg_s *img_s;
    QThread *threadsend;
    img_s = new sendimg_s(db_n,database,host,user,pwsd,port,tablename,info,n,p,time,i,d,img);
    threadsend = new QThread;
    img_s->moveToThread(threadsend);
    threadsend->start();

    connect(threadsend,&QThread::started,img_s,&sendimg_s::send);
    connect(img_s,SIGNAL(finish()),img_s,SLOT(deleteLater()));
    connect(img_s,SIGNAL(destroyed()),threadsend,SLOT(quit()));
    connect(threadsend,SIGNAL(finished()),threadsend,SLOT(deleteLater()));
}

//get info
void SQLsend::getinfo(char p, char n)
{
    if(p!=TestPoint)
        total_area = 0;
    HaveCap = false;
    emit sendcap(HaveCap);
    TestPoint = p;
    TestNum = n;
    capture(img_0);
    if(!img_0.empty())
    {
        qDebug()<<"get src";
        toSQL_s(i++,table,TestInfo,TestNum,TestPoint,datetime->currentDateTime().toString("hhmm"),0,0,img_0);
        emit get_src(true);
    }
    else
        emit get_src(false);
}

//start dealing
void SQLsend::start_deal()
{
    int thred;
    cvtColor(img_0,img_0,COLOR_RGB2GRAY);

    capture(img_1);
    if(!img_1.empty())
    {
        qDebug()<<"get after pic";
        HaveCap = true;
        emit sendcap(HaveCap);
    }
    else
        QMessageBox::warning(NULL,"error","打后图像采集失败");

    img_1_src = img_1.clone();
    img_defect = img_1.clone();

    cvtColor(img_1,img_1,COLOR_RGB2GRAY);

    /*deal*/

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    absdiff(img_1,img_0,img_2);

    int Channels[] = { 0 };
    int nHistSize[] = { 256 };
    float range[] = { 0, 255 };
    const float* fHistRanges[] = { range };
    Mat hist;
    calcHist(&img_2, 1, Channels, Mat(), hist, 1, nHistSize, fHistRanges, true, false);
    for (int i = 2; i < 253; i++)
    {
            if ((cvRound(hist.at<uchar>(i) <= cvRound(hist.at<uchar>(i + 1))) && (cvRound(hist.at<uchar>(i + 1))) <= cvRound(hist.at<uchar>(i + 2))))
            {
//               if(i>10)
//               {
                    thred = i;
                    break;
//               }
            }
    }
    threshold(img_2,img_2,thred,255,0);

    Mat out;
    Mat element = getStructuringElement(MORPH_RECT, Size(5, 5));
    morphologyEx(img_2, out, MORPH_OPEN, element);

    namedWindow("结果预览",0);
    resizeWindow("结果预览",480,480);
    imshow("结果预览",out);

    findContours(out,contours,hierarchy,RETR_CCOMP,CHAIN_APPROX_NONE);
    int area;

    float diameter,equi_diameter;
    Scalar color(0,0,255);
    for (size_t index=0;index<contours.size();index++)
    {
        area=contourArea(contours[index]);
        diameter = pixe*sqrt(4*area/pi);
        if(diameter >= point_max)
        {
            total_area+=area;
            drawContours(img_defect,contours,index,color,1,8,hierarchy);
        }
    }
    equi_diameter = pixe*sqrt(4*total_area/pi);


    if(equi_diameter >= defect_max)
    {
        toSQL(i++,table,TestInfo,TestNum,TestPoint,datetime->currentDateTime().toString("hhmm"),1,1,img_1_src,img_defect);
        QString str = QString("defec pic trans");
        qDebug()<<str;

    }
    else
    {
        toSQL_s(i++,table,TestInfo,TestNum,TestPoint,datetime->currentDateTime().toString("hhmm"),1,0,img_1_src);
    }
    emit senddamage(equi_diameter);
    qDebug()<<"deal complete";
}


//delay function
void SQLsend::Delay_MSec(unsigned int msec)
{
    QEventLoop loop;
    QTimer::singleShot(msec,&loop,SLOT(quit()));
    loop.exec();
}

//count thread
void SQLsend::count()
{
    m+=1;
}
