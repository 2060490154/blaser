#ifndef CAMERA_H
#define CAMERA_H

#include <QObject>
#include <opencv.hpp>
#include <highgui.hpp>
//#include <highgui.hpp>
#include <imgproc.hpp>
#include <cstdio>
#include <cassert>
#include <vector>
#include <PixeLINKApi.h>
#include <iostream>
#include <guicamera.h>

using namespace cv;

typedef enum _ColorChannels
{
    RedChannel,
    GreenChannel,
    BlueChannel,
    NumColorChannels = BlueChannel
} ColorChannels;



class camera : public QObject
{
    Q_OBJECT
public:
    explicit camera(QObject *parent = 0);
    Mat openCVImage;
    HWND previewHandle;
    PXL_RETURN_CODE rc;
    U32 flags;


    //Pylon::CInstantCamera CAMERA;



    bool initcamera();
    bool cameraplay();
    bool camerastop();

    void RGB_change(ColorChannels color, int RGB_value);
    float *getRGB(float* colors);
    void autoWhiteBalance ();

    float getexposure();
    void setexposure(int time);

    float getgamma();
    void setgamma(int g);
    void enable_gamma();

    void capture(Mat &Image);
    void picshow(QString str,int x,int y);

    bool savesetting();
    bool recoversetting();

    float getframe();
    void setframe(int value);
    HANDLE hCamera;




signals:
    void sendcamera(HANDLE name);

public slots:
};

#endif // CAMERA_H
