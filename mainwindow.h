#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimerEvent>
#include "jetsonGPIO.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <opencv.hpp>
#include <imgproc.hpp>
#include <highgui.hpp>
#include <PixeLINKApi.h>
#include <guicamera.h>
#include <QUdpSocket>
#include "camera.h"
#include <QDesktopWidget>
#include <QDir>
#include <QDateTime>
#include <QSqlQuery>
#include "dialog.h"
#include <QThread>
#include "sqlsend.h"
#include <QTimer>
#include <QEventLoop>
#include "rulersettings.h"
#include <pylon/PylonIncludes.h>
#include <pylon/BaslerUniversalInstantCamera.h>
#include <QSlider>
#include <QComboBox>
#include <QLabel>
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

   // CBaslerUniversalInstantCamera *CAMERA = new CBaslerUniversalInstantCamera(CTlFactory::GetInstance().CreateFirstDevice());;


    camera *PXLcamera = new camera;
    QUdpSocket *usocket = new QUdpSocket;
    QHostAddress hostadd;
    quint16 hostport;

    QDateTime *datetime = new QDateTime;

    QSqlError addconnection(const QString dbname,const QString host, const QString user,
                            const QString passwd, int port = -1);

    HANDLE sendcamera;

    int TestModel;
    QString TestInfo;
    char GiveTestPoint = 0x00;
    char GiveRoundNum = 0x00;
    char GetTestPoint = 0x00;
    char GetRoundNum = 0x00;

    struct message_s
    {
        char command[1];
        char return_ok[1];
        char roud_info[1];
        char other[19] = {0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00};
    };
    bool get_or_not = false;
    bool init_or_not = false;
    bool thread_or_not = false;
    bool database_or_not = false;
    bool get_src = false;
    bool cap_flag = false;
    bool ready_or_not = false;
    bool damage_or_not = false;
    bool deal_or_not = false;
    bool cap_or_not = false;


        int camera_enable;
        char camera_flag = 2;


    ~MainWindow();


//////////////////////////////////////////////////////////////////////////////
        int EnumerateDevices();

    void ShowWarning( QString warningText );

    void UpdateCameraDialog( int cameraId );
    void UpdateSlider( QSlider* pCtrl, Pylon::IIntegerEx& integerParameter );
    void UpdateSliderText( QLabel *pString, Pylon::IIntegerEx& integerParameter );
    void UpdateEnumeration( QComboBox* pCtrl, Pylon::IEnumerationEx& enumParameter );
    void ClearSlider( QSlider* pCtrl, QLabel* pString );
    void ClearEnumeration( QComboBox* pCtrl );
    bool InternalOpenCamera( const Pylon::CDeviceInfo& devInfo, int cameraId );
    void InternalCloseCamera( int cameraId );




protected:
    virtual void showEvent(QShowEvent *event) override;
    virtual void paintEvent(QPaintEvent *) override;

private slots:
    // Slots for GuiCamera signals
    void OnNewGrabResult( int userHint );
    void OnStateChanged( int userHint, bool isGrabbing );
    void OnDeviceRemoved( int userHint );
    void OnNodeUpdated( int userHint, GenApi::INode* pNode );

    // Slots for GUI signals
    void on_scanButton_clicked();
    void on_cameraList_currentIndexChanged(int index);
    void on_openSelected_1_clicked();
    void on_openSelected_2_clicked();
    void on_openBySN_1_clicked();
    void on_openBySN_2_clicked();
    void on_openByUserID_1_clicked();
    void on_openByUserID_2_clicked();
    void on_close_1_clicked();
    void on_close_2_clicked();
    void on_singleShot_1_clicked();
    void on_singleShot_2_clicked();
    void on_continuous_1_clicked();
    void on_continuous_2_clicked();
    void on_stop_1_clicked();
    void on_stop_2_clicked();
    void on_exposure_1_valueChanged(int value);
    void on_exposure_2_valueChanged(int value);
    void on_gain_1_valueChanged(int value);
    void on_gain_2_valueChanged(int value);
    void on_pixelFormat_1_currentIndexChanged(int index);
    void on_pixelFormat_2_currentIndexChanged(int index);
    void on_triggerMode_1_currentTextChanged(const QString &arg1);
    void on_triggerMode_2_currentTextChanged(const QString &arg1);
    void on_triggerSource_1_currentTextChanged(const QString &arg1);
    void on_triggerSource_2_currentTextChanged(const QString &arg1);
    void on_softwareTrigger_1_clicked();
    void on_softwareTrigger_2_clicked();
    void on_invertPixel_1_toggled(bool checked);
    void on_invertPixel_2_toggled(bool checked);

    void OnUpdateTimer();

    void on_editSN_1_textEdited(const QString &arg1);

    void on_editSN_2_textEdited(const QString &arg1);

    void on_editUserID_1_textEdited(const QString &arg1);

    void on_editUserID_2_textEdited(const QString &arg1);

//////////////////////////////////////////////////////////////////////////////

signals:
    void giveinfo(char p,char n);
    void begain_to_deal();
    void deal_finish();


private slots:
    void on_connect_btn_clicked();
    void receivetable(QString str);
    void receiveSQL(QString str);
    void do_connect();
    void usedcamera(HANDLE c);

    void receivemessage();
    void receivesrc(bool s);
    void receivedamage(float d);
    void receivecap(bool c);

    void creatDealThread();
    //void senddamage(float d);
    void send_get(bool get);
    void send_ready(bool ready);
    void send_deal_1(bool deal,bool success);
    void send_cap(bool cap);
    void send_finish(bool t);

    void creatudp();

    void receiveruler_parameters(QString p,QString h,QString t);

    void Delay_MSec(unsigned int msec);


///////////////////new add
    void cameraplay();
    void camerastop();

///
///
/// //////////////
private:
    Ui::MainWindow *ui;
    Dialog *condia = new Dialog;
    SQLsend *send;
    QThread *threadsend;

    QString database;
    QString host;
    QString user;
    QString pwd;
    int port;
    //int thread_flag = 0;


    int ruler_pixe;
    int ruler_height;
    QString ruler_real;

//////////////////////
    Pylon::DeviceInfoList_t m_devices;
    static const int MaxCamera = 2;
    CGuiCamera m_camera[MaxCamera];
    QTimer m_updateTimer;
///////////////////////

};
#endif // MAINWINDOW_H
