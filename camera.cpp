#include "camera.h"
#include <QDebug>
#include <BaslerCamera.h>
#define ASSERT(x)	do { assert((x)); } while(0)

using namespace cv;
using namespace std;


camera::camera(QObject *parent) : QObject(parent)
{

}

bool camera::initcamera()
{
    rc = PxLInitialize(0, &hCamera);
    if (!API_SUCCESS(rc))
    {
        //printf("Error: Unable to initialize a camera\n");
        qDebug()<<"unable to intialize the camera";
        return false;
    }
    else
    {
        //printf("enable the camera successfully\n");
        HANDLE name = hCamera;
        qDebug()<<"enable the camera successfully";
        emit sendcamera(name);
        return true;
        //rc = PxLLoadSettings(hCamera,PXL_SETTINGS_FACTORY);
    }
}

//camera preview
bool camera::cameraplay()
{
    rc = PxLSetPreviewSettings(hCamera,"previewing window",0,0,0,768,576);
    rc = PxLSetStreamState(hCamera, START_STREAM);
    if (!API_SUCCESS(rc))
    {
        printf("Error: Unable to start the stream on the camera\n");
        PxLUninitialize(hCamera);
        return false;
    }
    rc = PxLSetPreviewState(hCamera, START_PREVIEW, &previewHandle);
    if (!API_SUCCESS(rc))
        return false;
    else
        return true;
}

bool camera::camerastop()
{
    rc = PxLSetStreamState(hCamera, STOP_STREAM);
    if (!API_SUCCESS(rc))
        return false;
    else
        return true;
}


//camera RGB change
void camera::RGB_change(ColorChannels color, int RGB_value)
{
    U32   numParams = 3;
    U32 flags;
    vector<float> cameraColors(numParams);
    rc = PxLGetFeature(hCamera,FEATURE_WHITE_SHADING,&flags,&numParams,&cameraColors[0]);

    // adjust the specified color
    cameraColors[color] = RGB_value*0.1;

    rc = PxLSetFeature (hCamera, FEATURE_WHITE_SHADING, flags, numParams, &cameraColors[0]);
    if (!API_SUCCESS(rc))
    {
        qDebug()<<"set the color failed";
    }
}

float * camera::getRGB(float *colors)
{
    U32 numParams=3;
    vector<float> cameraColors(numParams);
    rc = PxLGetFeature (hCamera, FEATURE_WHITE_SHADING, &flags, &numParams, &cameraColors[0]);

    colors[0]=cameraColors[0];
    colors[1]=cameraColors[1];
    colors[2]=cameraColors[2];

    //CAMERA.BalanceRatioSelector.SetValue(4);
    //camera.BalanceRatio.SetValue(1.76270);
   // colors[0] = camera.BalanceRatio.GetValue();
       // colors[1] = camera.BalanceRatio.GetValue();
           // colors[2] = camera.BalanceRatio.GetValue();
    return colors;
}

void camera::autoWhiteBalance ()
{
    ULONG rc;
    U32   numParams = 3;
    vector<float> cameraColors(numParams, 0.0); // Intialize to 0 (no color), but these values are ignored when initating auto adjustment.

    rc = PxLSetFeature (hCamera, FEATURE_WHITE_SHADING, FEATURE_FLAG_ONEPUSH, numParams, &cameraColors[0]);
    if (!API_SUCCESS(rc))
    {
        printf (" !! Attempt to set Auto White Balance returned 0x%X!\n", rc);
    }
}

//camera exposure
float camera::getexposure()
{
    float currentExposure;
    ULONG numParams = 1;
    rc = PxLGetFeature(hCamera,FEATURE_EXPOSURE,&flags,&numParams,&currentExposure);
    return currentExposure;
}

void camera::setexposure(int time)
{
    ULONG numParams = 1;
    float stime = float(time/1000.0);
    rc = PxLSetStreamState(hCamera, STOP_STREAM);
    rc = PxLSetFeature(hCamera,FEATURE_EXPOSURE,FEATURE_FLAG_MANUAL,numParams,&stime);
    rc = PxLSetStreamState(hCamera, START_STREAM);
}

//camera capture
void camera::capture(Mat &Image)
{
    std::vector<U8> frameBuffer(4000 * 4000 * 2);
    FRAME_DESC frameDesc;
    frameDesc.uSize = sizeof(FRAME_DESC);
    U32 imageBufferSize = frameBuffer.size() * 3;
    std::vector<U8> imageBuffer(imageBufferSize);
    rc = PxLGetNextFrame(hCamera, (U32)frameBuffer.size(), &frameBuffer[0], &frameDesc);
    rc = PxLFormatImage(&frameBuffer[0], &frameDesc, IMAGE_FORMAT_RAW_BGR24, &imageBuffer[0],
            &imageBufferSize);
    Mat openCVImage((int)(frameDesc.Roi.fHeight/frameDesc.PixelAddressingValue.fVertical),
                    (int)(frameDesc.Roi.fWidth/ frameDesc.PixelAddressingValue.fHorizontal),
                    CV_8UC3,
                    &imageBuffer[0]);
    Image = openCVImage.clone();

}

void camera::picshow(QString str,int x, int y)
{
    Mat pic = imread(str.toStdString());
    namedWindow("预览图片",WINDOW_NORMAL);
    resizeWindow("预览图片",x,y);
    imshow("预览图片",pic);
}

//camera settings
bool camera::savesetting()
{
    rc = PxLSetStreamState(hCamera, STOP_STREAM);
    rc = PxLSaveSettings(hCamera,1);
    if (!API_SUCCESS(rc))
    {
        return false;
    }
    else
    {
        rc = PxLSetStreamState(hCamera, START_STREAM);
        return true;
    }
}

bool camera::recoversetting()
{
    rc = PxLSetStreamState(hCamera, STOP_STREAM);
    rc = PxLLoadSettings(hCamera,PXL_SETTINGS_FACTORY);
    if (!API_SUCCESS(rc))
    {
        qDebug()<<"unable to intialize the settings";
        return false;
    }
    else
    {
        qDebug()<<"enable the settings successfully";
        rc = PxLSetStreamState(hCamera, START_STREAM);
        return true;
    }

}

//camera framerate
float camera::getframe()
{
    float currentrate;
    ULONG numParams = 1;
    rc = PxLGetFeature(hCamera,FEATURE_FRAME_RATE,&flags,&numParams,&currentrate);
    return currentrate;
}

void camera::setframe(int value)
{
    ULONG numParams = 1;
    float rate = (float)value/10.0;
    rc = PxLSetStreamState(hCamera, STOP_STREAM);
    rc = PxLSetFeature(hCamera, FEATURE_FRAME_RATE, FEATURE_FLAG_MANUAL, numParams, &rate);
    rc = PxLSetStreamState(hCamera, START_STREAM);
}

//camera gamma
float camera::getgamma()
{
    float currentgamma;
    ULONG numParams = 1;
    rc = PxLGetFeature(hCamera,FEATURE_GAMMA,&flags,&numParams,&currentgamma);
    return currentgamma;
}

void camera::setgamma(int g)
{
    ULONG numParams = 1;
    float ga = g*0.1;
    rc = PxLSetStreamState(hCamera, STOP_STREAM);
    rc = PxLSetFeature(hCamera,FEATURE_GAMMA,FEATURE_FLAG_MANUAL,numParams,&ga);
    rc = PxLSetStreamState(hCamera, START_STREAM);
}

void camera::enable_gamma()
{
    PXL_RETURN_CODE rc = ApiSuccess;
    ULONG  flags = 0;
    float featureValues[10]; // This is large enough for any feature
    ULONG numParams = 10;

    rc = PxLGetFeature (hCamera, FEATURE_GAMMA, &flags, &numParams, &featureValues[0]);
    IS_FEATURE_ENABLED(flags);

}

