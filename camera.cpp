#include "camera.h"
#include <QDebug>
#include <pylon/PylonIncludes.h>

using namespace Basler_UniversalCameraParams;

using namespace cv;
using namespace std;
using namespace Pylon;

camera::camera(QObject *parent) : QObject(parent)
{
}

/*
 * Initialize camera: create a device (first found) and attach to the CGuiCamera wrapper.
 * Returns true if camera opened successfully.
 */
bool camera::initcamera()
{
    try
    {
        // Initialize Pylon runtime if necessary (main.cpp usually does PylonAutoInitTerm)
        // Create device and attach to wrapper
        Pylon::CTlFactory& TlFactory = Pylon::CTlFactory::GetInstance();
        Pylon::DeviceInfoList_t devices;
        TlFactory.EnumerateDevices( devices );
        if (devices.empty())
        {
            qDebug() << "No Basler devices found.";
            return false;
        }
        // Use first device
        Pylon::IPylonDevice* pDevice = TlFactory.CreateDevice( devices[0] );
        // Attach to underlying camera object inside CGuiCamera (m_camera is public in guicamera.h)
        m_guiCamera.m_camera.Attach( pDevice, Pylon::Cleanup_Delete );
        // Open camera via CGuiCamera::Open might assume deviceInfo; ensure camera is open
        m_guiCamera.m_camera.Open();
        qDebug() << "Basler camera opened.";
        // Emit a token-like pointer (not HANDLE) to keep compatibility if something expects sendcamera.
        emit sendcamera(reinterpret_cast<void*>(&m_guiCamera));
        return true;
    }
    catch (const Pylon::GenericException& e)
    {
        qDebug() << "initcamera failed:" << e.GetDescription();
        return false;
    }
}

bool camera::cameraplay()
{
    try
    {
        m_guiCamera.ContinuousGrab();
        return true;
    }
    catch (const Pylon::GenericException& e)
    {
        qDebug() << "cameraplay failed:" << e.GetDescription();
        return false;
    }
}

bool camera::camerastop()
{
    try
    {
        m_guiCamera.StopGrab();
        return true;
    }
    catch (const Pylon::GenericException& e)
    {
        qDebug() << "camerastop failed:" << e.GetDescription();
        return false;
    }
}

void camera::capture(Mat &Image)
{
    // Forward to CGuiCamera::capture which fills an OpenCV Mat
    m_guiCamera.capture(Image);
}

void camera::picshow(QString str,int x, int y)
{
    m_guiCamera.picshow(str,x,y);
}

float camera::getexposure()
{
    try {
        if (m_guiCamera.m_camera.IsOpen())
            return m_guiCamera.m_camera.ExposureTime.GetValue();
    } catch (...) {}
    return 0.0f;
}

void camera::setexposure(int time)
{
    try {
        if (m_guiCamera.m_camera.IsOpen())
            m_guiCamera.m_camera.ExposureTime.SetValue(time);
    } catch (...) {}
}

float camera::getframe()
{
    try {
        if (m_guiCamera.m_camera.IsOpen())
            return m_guiCamera.m_camera.ResultingFrameRate.GetValue();
    } catch (...) {}
    return 0.0f;
}

void camera::setframe(int value)
{
    try {
        if (m_guiCamera.m_camera.IsOpen())
            m_guiCamera.m_camera.AcquisitionFrameRate.SetValue(value);
    } catch (...) {}
}

float camera::getgamma()
{
    try {
        if (m_guiCamera.m_camera.IsOpen())
            return m_guiCamera.m_camera.Gamma.GetValue();
    } catch (...) {}
    return 0.0f;
}

void camera::setgamma(int g)
{
    try {
        if (m_guiCamera.m_camera.IsOpen())
            m_guiCamera.m_camera.Gamma.SetValue(g*0.1f);
    } catch (...) {}
}

void camera::RGB_change(ColorChannels color, int RGB_value)
{
    // Map to BalanceRatio selectors
    try {
        if (!m_guiCamera.m_camera.IsOpen()) return;
        float v = RGB_value * 0.1f;
        if (color == RedChannel)
        {
            m_guiCamera.m_camera.BalanceRatioSelector.SetValue(BalanceRatioSelector_Red);
            m_guiCamera.m_camera.BalanceRatio.SetValue(v);
        }
        else if (color == GreenChannel)
        {
            m_guiCamera.m_camera.BalanceRatioSelector.SetValue(BalanceRatioSelector_Green);
            m_guiCamera.m_camera.BalanceRatio.SetValue(v);
        }
        else if (color == BlueChannel)
        {
            m_guiCamera.m_camera.BalanceRatioSelector.SetValue(BalanceRatioSelector_Blue);
            m_guiCamera.m_camera.BalanceRatio.SetValue(v);
        }
    } catch (...) {}
}

float* camera::getRGB(float* colors)
{
    try {
        if (!m_guiCamera.m_camera.IsOpen()) return colors;
        m_guiCamera.m_camera.BalanceRatioSelector.SetValue(BalanceRatioSelector_Red);
        colors[0] = m_guiCamera.m_camera.BalanceRatio.GetValue();
        m_guiCamera.m_camera.BalanceRatioSelector.SetValue(BalanceRatioSelector_Green);
        colors[1] = m_guiCamera.m_camera.BalanceRatio.GetValue();
        m_guiCamera.m_camera.BalanceRatioSelector.SetValue(BalanceRatioSelector_Blue);
        colors[2] = m_guiCamera.m_camera.BalanceRatio.GetValue();
    } catch (...) {}
    return colors;
}

void camera::autoWhiteBalance ()
{
    try {
        if (!m_guiCamera.m_camera.IsOpen()) return;
        m_guiCamera.m_camera.BalanceWhiteAuto.SetValue(BalanceWhiteAuto_Once);
    } catch (...) {}
}

bool camera::savesetting()
{
    try {
        // Use Pylon user set save if available
        if (!m_guiCamera.m_camera.IsOpen()) return false;
        m_guiCamera.m_camera.UserSetSelector.SetValue(UserSetSelector_UserSet1);
        m_guiCamera.m_camera.UserSetSave.Execute();
        return true;
    } catch (...) { return false; }
}

bool camera::recoversetting()
{
    try {
        if (!m_guiCamera.m_camera.IsOpen()) return false;
        m_guiCamera.m_camera.UserSetSelector.SetValue(UserSetSelector_Default);
        m_guiCamera.m_camera.UserSetLoad.Execute();
        return true;
    } catch (...) { return false; }
}
