#ifndef CAMERA_H
#define CAMERA_H

#include <QObject>
#include <opencv.hpp>
#include <highgui.hpp>
#include <imgproc.hpp>
#include <cstdio>
#include <cassert>
#include <vector>
#include <iostream>

// Use the project's Pylon-based GUI camera wrapper
#include "guicamera.h"

using namespace cv;

typedef enum _ColorChannels
{
    RedChannel,
    GreenChannel,
    BlueChannel,
    NumColorChannels = BlueChannel
} ColorChannels;

/*
 * camera class:
 * - wraps the CGuiCamera (Pylon) instance and forwards capture / settings calls.
 * - this replaces previous Pixelink HANDLE-based implementation.
 */
class camera : public QObject
{
    Q_OBJECT
public:
    explicit camera(QObject *parent = 0);

    // Underlying Pylon-based camera wrapper
    CGuiCamera m_guiCamera;

    // Public image
    Mat openCVImage;

    // Camera control methods (wrappers around CGuiCamera / Pylon API)
    bool initcamera();           // initialize and open the first camera device
    bool cameraplay();           // start continuous grab
    bool camerastop();           // stop grab

    // Image capture: will fill Image with a snapshot (uses CGuiCamera::capture)
    void capture(Mat &Image);
    void picshow(QString str,int x,int y);

    // Basic setting wrappers (where possible)
    float getexposure();
    void setexposure(int time);
    float getframe();
    void setframe(int value);
    float getgamma();
    void setgamma(int g);

    void RGB_change(ColorChannels color, int RGB_value);
    float *getRGB(float* colors);
    void autoWhiteBalance ();
    bool savesetting();
    bool recoversetting();

signals:
    // kept for compatibility signals in the UI layer — not used like Pixelink HANDLE, but kept for compatibility
    void sendcamera(void* token);

public slots:
};

#endif // CAMERA_H
