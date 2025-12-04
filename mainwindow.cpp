#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QByteArray>
#include <QUdpSocket>
#include <QFileDialog>
#include "deal.h"
#include "unistd.h"
#include "dialog.h"
#include <QByteArray>
#include <QFile>
#include <pylon/PylonIncludes.h>
#include <BaslerCamera.h>
#include <pylon/ImageFormatConverter.h>
//#include <pylon/PylonGUI.h>
#include <opencv2/opencv.hpp>
#include <QPainter>
using namespace cv;
using namespace std;
//using namespace Pylon;
using namespace Basler_UniversalCameraParams;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("主界面");
    QDesktopWidget *desktop = QApplication::desktop();
    move((desktop->width()-this->width())/2,(desktop->height()-this->height())/2);


    for (int i = 0; i < MaxCamera; i++)
    {
        m_camera[i].SetUserHint( i );
        camera_enable = 1;
        // Connect signals from CGuiCamera class to this dialog.
        QObject::connect( &(m_camera[i]), &CGuiCamera::NewGrabResult, this, &MainWindow::OnNewGrabResult );
        QObject::connect( &(m_camera[i]), &CGuiCamera::StateChanged, this, &MainWindow::OnStateChanged );
        QObject::connect( &(m_camera[i]), &CGuiCamera::DeviceRemoved, this, &MainWindow::OnDeviceRemoved );
        QObject::connect( &(m_camera[i]), &CGuiCamera::NodeUpdated, this, &MainWindow::OnNodeUpdated );
    }

    // Create preview label inside the UI placeholder widget 'image'
    m_previewLabel = new QLabel(ui->image);
    m_previewLabel->setScaledContents(true);
    m_previewLabel->setGeometry(0, 0, ui->image->width(), ui->image->height());
    m_previewLabel->setAlignment(Qt::AlignCenter);

    // Add an Upload Test button near connect button area
    if (ui->groupBox_5) {
        upload_test_btn = new QPushButton(ui->groupBox_5);
        upload_test_btn->setObjectName("upload_test_btn");
        upload_test_btn->setText("上传测试");
        upload_test_btn->setGeometry(ui->connect_btn->geometry().x(), ui->connect_btn->geometry().y() + 40, 81, 27);
        connect(upload_test_btn, &QPushButton::clicked, this, &MainWindow::on_upload_test_btn_clicked);
    }


    //set the slider of FPS
    connect(ui->fps_w,&pfs::valuechange,[=](){
        int i = ui->fps_w->pfs_value();
        if(m_camera[0].m_camera.IsOpen())
        {
            m_camera[0].m_camera.AcquisitionFrameRate.SetValue(i);
            ui->textEdit->append("设置FPS值为");
            string str = to_string(i);
            ui->textEdit->append(QString::fromStdString(str));
        }
        else
            ui->textEdit->append("相机未打开，设置失败");
    });

    //set the slider of exposure
    connect(ui->light_w,&light::valuechange,[=](){
        int i = ui->light_w->light_value();
        if(m_camera[0].m_camera.IsOpen())
        {
            m_camera[0].m_camera.ExposureTime.SetValue(i);
            ui->textEdit->append("设置曝光时间为");
            string str = to_string(i);
            ui->textEdit->append(QString::fromStdString(str));
        }
        else
            ui->textEdit->append("相机未打开，设置失败");
    });


    //set the slider of gamma
    connect(ui->gamma_w,&gamma_1::valuechange,[=](){
        float i = ui->gamma_w->gamma_value();
        i = i / 10;
        if(m_camera[0].m_camera.IsOpen())
        {
            m_camera[0].m_camera.Gamma.SetValue(i);
            ui->textEdit->append("设置gamma值为");
            string str = to_string(i*10);
            ui->textEdit->append(QString::fromStdString(str));
        }
        else
            ui->textEdit->append("相机未打开，设置失败");

    });


    //set the slider of RGB
    connect(ui->RGB_w,&RGB::R_change,[=](){
        float i = ui->RGB_w->R_value();
        i = i / 10;
        if(m_camera[0].m_camera.IsOpen())
        {
            m_camera[0].m_camera.BalanceRatioSelector.SetValue(BalanceRatioSelector_Red);
            m_camera[0].m_camera.BalanceRatio.SetValue(i);
            ui->textEdit->append("设置Red值为");
            string str = to_string(i*10);
            ui->textEdit->append(QString::fromStdString(str));
        }
        else
            ui->textEdit->append("相机未打开，设置失败");
    });
    connect(ui->RGB_w,&RGB::G_change,[=](){
        float i = ui->RGB_w->G_value();
        i = i / 10;
        if(m_camera[0].m_camera.IsOpen())
        {
            m_camera[0].m_camera.BalanceRatioSelector.SetValue(BalanceRatioSelector_Green);
            m_camera[0].m_camera.BalanceRatio.SetValue(i);
            ui->textEdit->append("设置Green值为");
            string str = to_string(i*10);
            ui->textEdit->append(QString::fromStdString(str));
        }
        else
            ui->textEdit->append("相机未打开，设置失败");
    });
    connect(ui->RGB_w,&RGB::B_change,[=](){
        float i = ui->RGB_w->B_value();
        i = i / 10;
        if(m_camera[0].m_camera.IsOpen())
        {
            m_camera[0].m_camera.BalanceRatioSelector.SetValue(BalanceRatioSelector_Blue);
            m_camera[0].m_camera.BalanceRatio.SetValue(i);
            ui->textEdit->append("设置Blue值为");
            string str = to_string(i*10);
            ui->textEdit->append(QString::fromStdString(str));
        }
        else
            ui->textEdit->append("相机未打开，设置失败");
    });
    connect(ui->RGB_w,&RGB::do_auto,[=](){
        if(m_camera[0].m_camera.IsOpen())
        {
            m_camera[0].m_camera.BalanceWhiteAuto.SetValue(BalanceWhiteAuto_Once);
            //m_camera[0].m_camera.BalanceWhiteAuto.SetValue(BalanceWhiteAuto_Off);

            int j = ui->exposure_edit->text().toInt();
            int n = 1;
            for(int i = 0;i<j;i++)
            {
                ui->exposure_edit->setText(QString("%1").arg(n++));
                Delay_MSec(1000);
            }
            ui->textEdit->append("自动设置RGB成功");

            float arr[3];

            m_camera[0].m_camera.BalanceRatioSelector.SetValue(BalanceRatioSelector_Red);
            arr[0] = m_camera[0].m_camera.BalanceRatio.GetValue();
            m_camera[0].m_camera.BalanceRatioSelector.SetValue(BalanceRatioSelector_Green);
            arr[1] = m_camera[0].m_camera.BalanceRatio.GetValue();
            m_camera[0].m_camera.BalanceRatioSelector.SetValue(BalanceRatioSelector_Blue);
            arr[2] = m_camera[0].m_camera.BalanceRatio.GetValue();

            ui->RGB_w->setRGBvalue(arr,3);
        }
        else
            ui->textEdit->append("相机未打开，设置失败");
    });

    //set socket

    creatudp();


    //set the hardware initial
    connect(ui->inti_btn,&QPushButton::clicked,[=](){
        if(!init_or_not)
        {
            if(camera_enable == 1)
            {

                int deviceCount = EnumerateDevices();
                if (deviceCount == 0)
                {
                    ShowWarning( "找不到相机设备" );
                    return;
                }

                for (Pylon::DeviceInfoList_t::const_iterator it = m_devices.begin(); it != m_devices.end(); ++it)
                {
                    const Pylon::CDeviceInfo* const pDeviceInfo = &(*it);
                    InternalOpenCamera( *pDeviceInfo, 0 );
                }

                float arr[3];
                m_camera[0].m_camera.BalanceRatioSelector.SetValue(BalanceRatioSelector_Red);
                arr[0] = m_camera[0].m_camera.BalanceRatio.GetValue();
                m_camera[0].m_camera.BalanceRatioSelector.SetValue(BalanceRatioSelector_Green);
                arr[1] = m_camera[0].m_camera.BalanceRatio.GetValue();
                m_camera[0].m_camera.BalanceRatioSelector.SetValue(BalanceRatioSelector_Blue);
                arr[2] = m_camera[0].m_camera.BalanceRatio.GetValue();
                ui->RGB_w->setRGBvalue(arr,3);

                float time =  m_camera[0].m_camera.ExposureTime.GetValue();
                ui->light_w->setvalue(time);

                int rate =  m_camera[0].m_camera.AcquisitionFrameRate.GetValue();
                ui->fps_w->setvalue(rate);

                float gamma =  m_camera[0].m_camera.Gamma.GetValue();
                ui->gamma_w->setvalue(gamma);

                init_or_not = true;
                ui->textEdit->append("初始化CCD成功");
            }
            else
                ui->textEdit->append("初始化CCD失败");

        }
        else
            ui->textEdit->append("CCD已初始化");

    });

    // Removed legacy Pixelink 'sendcamera' connection because CGuiCamera does not emit this signal.
    // If you need to get a callback when a camera is created, use proper CGuiCamera signals or implement such a signal.

    //start the thread
    connect(ui->start_btn,&QPushButton::clicked,[=](){
        if(!thread_or_not)
        {
            creatDealThread();
        }
        else
            ui->textEdit->append("线程已开启过");

    });


    //contral of the camera
    connect(ui->play_btn,&QPushButton::clicked,[=](){
        if(camera_flag == 0 && (!m_camera[0].m_camera.IsOpen()))
            ui->textEdit->append("预览失败，请检查CCD情况");
        else
        {
            cameraplay();
            ui->textEdit->append("预览成功");
        }

    });
    connect(ui->stop_btn,&QPushButton::clicked,[=](){
        if(camera_flag == 1 && m_camera[0].m_camera.IsOpen())
        {
            camerastop();
            ui->textEdit->append("预览停止");
        }
        else
            ui->textEdit->append("停止失败，请检查CCD情况");
    });


    //capture
    connect(ui->bro_btn,&QPushButton::clicked,[=](){
        QString path = QFileDialog::getExistingDirectory(this,"chooseDir","/");
        ui->save_line->setText(path);
    });

    rulersettings *ruler = new rulersettings;

    connect(ui->ruler_btn,&QPushButton::clicked,[=](){
        ruler->show();
    });

    connect(ruler,SIGNAL(rulerparameters(QString,QString,QString)),this,SLOT(receiveruler_parameters(QString,QString,QString)));

    connect(ui->cap_btn,&QPushButton::clicked,[=](){
        if(!init_or_not)
        {
            QMessageBox::warning(this,"error","CCD未初始化");
        }
        else
        {
            if(ui->save_line->text().isEmpty())
                QMessageBox::warning(this,"error","请选择存储路径");
            else
            {
                QString dir = ui->save_line->text();
                QString name;
                if(ui->name_check->isChecked())
                {
                    name = ui->save_name->text();
                }
                else
                {
                    name = QString("%1.bmp").arg(datetime->currentDateTime().toString("yyyyMMddhhmmss"));
                }
                QString picPath = QString("%1/%2").arg(dir).arg(name);
                Mat Img;
                if(ui->name_check->isChecked()&&ui->save_name->text().isEmpty())
                    QMessageBox::warning(this,"error","请输入图片名");
                else
                {
                    //PXLcamera->capture(Img);
                    try
                    {
                        m_camera[0].capture(Img);
                    }
                    catch (const Pylon::GenericException& e)
                    {
                        ShowWarning( QString( "Could not start grab!\n" ) + QString( e.GetDescription() ) );
                    }

                    if(ui->ruler_box->isChecked())
                    {
                        int x_num,y_num;
                        x_num=Img.cols;
                        y_num=Img.rows;

                        Point p1(x_num-x_num/5,y_num-y_num/5);
                        Point p2(x_num-x_num/5-ruler_pixe,y_num-y_num/5);

                        line(Img,p1,p2,Scalar(255,255,255),ruler_height);

                        QString ruler_str = ruler_real;
                        putText(Img,ruler_str.toStdString(),Point(p2.x,p2.y+25),FONT_HERSHEY_PLAIN,1.5,Scalar(255,255,255),2,8,0);
                    }

                    imwrite(picPath.toStdString(),Img);

                    if(ui->cap_check->isChecked())
                    {
                        m_camera[0].picshow(picPath,612,506);
                    }
                }
            }
        }

    });


    //deal
    connect(ui->deal_btn,&QPushButton::clicked,[=](){
        deal *dealwidget = new deal;
        dealwidget->show();
    });

    //settings
    connect(ui->saveset_btn,&QPushButton::clicked,[=](){
        if(m_camera[0].m_camera.IsOpen())
        {
            camerastop();
            m_camera[0].m_camera.UserSetSelector.SetValue(UserSetSelector_UserSet1);
            m_camera[0].m_camera.UserSetLoad.Execute();

            int i = ui->fps_w->pfs_value();
            m_camera[0].m_camera.AcquisitionFrameRate.SetValue(i);

            int a = ui->light_w->light_value();
            m_camera[0].m_camera.ExposureTime.SetValue(a);

            float b = ui->gamma_w->gamma_value();
            b = b / 10;
            m_camera[0].m_camera.Gamma.SetValue(b);

            float c = ui->RGB_w->R_value();
            c = c / 10;
            m_camera[0].m_camera.BalanceRatioSelector.SetValue(BalanceRatioSelector_Red);
            m_camera[0].m_camera.BalanceRatio.SetValue(c);

            float d = ui->RGB_w->G_value();
            d = d / 10;
            m_camera[0].m_camera.BalanceRatioSelector.SetValue(BalanceRatioSelector_Green);
            m_camera[0].m_camera.BalanceRatio.SetValue(d);

            float e = ui->RGB_w->B_value();
            e = e / 10;
            m_camera[0].m_camera.BalanceRatioSelector.SetValue(BalanceRatioSelector_Blue);
            m_camera[0].m_camera.BalanceRatio.SetValue(e);

            m_camera[0].m_camera.UserSetSelector.SetValue(UserSetSelector_UserSet1);
            m_camera[0].m_camera.UserSetSave.Execute();
            m_camera[0].m_camera.UserSetDefault.SetValue(UserSetDefault_UserSet1);
            cameraplay();
            ui->textEdit->append("保存设置成功");
        }
        else
            ui->textEdit->append("保存设置失败");
    });

    connect(ui->recover_btn,&QPushButton::clicked,[=](){
        if(m_camera[0].m_camera.IsOpen())
        {
            camerastop();
            m_camera[0].m_camera.UserSetSelector.SetValue(UserSetSelector_Default);
            m_camera[0].m_camera.UserSetLoad.Execute();

            float arr[3];

            m_camera[0].m_camera.BalanceRatioSelector.SetValue(BalanceRatioSelector_Red);
            arr[0] = m_camera[0].m_camera.BalanceRatio.GetValue();
            m_camera[0].m_camera.BalanceRatioSelector.SetValue(BalanceRatioSelector_Green);
            arr[1] = m_camera[0].m_camera.BalanceRatio.GetValue();
            m_camera[0].m_camera.BalanceRatioSelector.SetValue(BalanceRatioSelector_Blue);
            arr[2] = m_camera[0].m_camera.BalanceRatio.GetValue();
            ui->RGB_w->setRGBvalue(arr,3);

            float time =  m_camera[0].m_camera.ExposureTime.GetValue();
            ui->light_w->setvalue(time);

            int rate =  m_camera[0].m_camera.AcquisitionFrameRate.GetValue();
            ui->fps_w->setvalue(rate);

            float gamma =  m_camera[0].m_camera.Gamma.GetValue();
            ui->gamma_w->setvalue(gamma);
            cameraplay();
            ui->textEdit->append("恢复出厂设置成功");
        }
        else
            ui->textEdit->append("恢复出厂设置失败");
    });

    //get the info of SQL
    connect(condia,SIGNAL(sendtable(QString)) ,this,SLOT(receivetable(QString)));
    connect(condia,SIGNAL(sendSQL(QString)),this,SLOT(receiveSQL(QString)));
    connect(condia,SIGNAL(connect()),this,SLOT(do_connect()));

}

MainWindow::~MainWindow()
{
    if(thread_or_not)
    {
        qDebug()<<"quit thread";
        threadsend->quit();
        threadsend->wait();
    }

        m_camera[0].Close();


    delete ui;
}

// Minimal stub implementations for methods declared in mainwindow.h but not defined.
int MainWindow::EnumerateDevices()
{
    using namespace Pylon;
    CTlFactory& TlFactory = CTlFactory::GetInstance();
    DeviceInfoList_t devices;
    try {
        TlFactory.EnumerateDevices(devices);
        m_devices = devices;
        int cnt = (int)devices.size();
        if (ui)
        {
            ui->textEdit->append(QString("Enumerated %1 device(s)").arg(cnt));
            for (size_t i = 0; i < devices.size(); ++i) {
                    const Pylon::CDeviceInfo &di = devices[i];
                    QString info = QString::fromUtf8(di.GetModelName().c_str()) + " SN:" + QString::fromUtf8(di.GetSerialNumber().c_str());
                    ui->textEdit->append(info);
                }
        }
        return cnt;
    } catch (const GenericException &e) {
        if (ui)
            ui->textEdit->append(QString("Pylon enumerate failed: %1").arg(QString::fromStdString(e.GetDescription())));
        return 0;
    }
}

void MainWindow::ShowWarning(QString warningText)
{
    QMessageBox::warning(this, "Warning", warningText);
}

void MainWindow::OnNewGrabResult(int userHint)
{
    if (userHint < 0 || userHint >= MaxCamera)
        return;

    // Get the latest image (as QImage) from camera
    const QImage &img = m_camera[userHint].GetImage();
    if (img.isNull())
        return;

    // Convert and display it in the preview label
    QPixmap pix = QPixmap::fromImage(img);
    if (m_previewLabel)
    {
        QSize widgetSize = ui->image->size();
        QPixmap scaled = pix.scaled(widgetSize, Qt::KeepAspectRatio);
        m_previewLabel->setPixmap(scaled);
    }
}

void MainWindow::OnStateChanged(int userHint, bool isGrabbing)
{
    Q_UNUSED(userHint);
    Q_UNUSED(isGrabbing);
}

void MainWindow::OnDeviceRemoved(int userHint)
{
    Q_UNUSED(userHint);
}

void MainWindow::OnNodeUpdated(int userHint, GenApi::INode* pNode)
{
    Q_UNUSED(userHint);
    Q_UNUSED(pNode);
}

void MainWindow::creatudp()
{
    // stub: setup UDP socket
}

void MainWindow::creatDealThread()
{
    // stub: create deal thread
}

void MainWindow::Delay_MSec(unsigned int msec)
{
    QEventLoop loop;
    QTimer::singleShot(msec, &loop, SLOT(quit()));
    loop.exec();
}

void MainWindow::cameraplay()
{
    if (m_camera[0].m_camera.IsOpen())
    m_camera[0].ContinuousGrab();
}

void MainWindow::camerastop()
{
    if (m_camera[0].m_camera.IsOpen())
    {
        // disable debug saving first to stop file writes from OnImageGrabbed
        m_camera[0].SetDebugSaveEnabled(false);
        m_camera[0].StopGrab();
        // Wait briefly for the grabbing to stop to avoid OnImageGrabbed from running during Close
        int wait_ms = 0;
        while (m_camera[0].m_camera.IsGrabbing() && wait_ms < 2000)
        {
            Delay_MSec(10);
            wait_ms += 10;
        }
    }
}

bool MainWindow::InternalOpenCamera(const Pylon::CDeviceInfo& devInfo, int cameraId)
{
    try {
        if (cameraId < 0 || cameraId >= MaxCamera) return false;
        m_camera[cameraId].Open(devInfo);
        m_camera[cameraId].SetUserHint(cameraId);
        return true;
    } catch (const Pylon::GenericException &e) {
        ShowWarning(QString("Failed to open camera: %1").arg(QString::fromStdString(e.GetDescription())));
    }
    return false;
}

void MainWindow::InternalCloseCamera( int cameraId )
{
    if (cameraId < 0 || cameraId >= MaxCamera) return;
    try {
        m_camera[cameraId].Close();
    } catch(...) {}
}

void MainWindow::showEvent(QShowEvent *event)
{
    QMainWindow::showEvent(event);
    if (m_previewLabel && ui && ui->image)
    {
        m_previewLabel->setGeometry(0, 0, ui->image->width(), ui->image->height());
    }
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QMainWindow::paintEvent(event);
    if (m_previewLabel && ui && ui->image)
    {
        m_previewLabel->setGeometry(0, 0, ui->image->width(), ui->image->height());
    }
}


void MainWindow::on_connect_btn_clicked()
{
    condia->show();
}

void MainWindow::on_upload_test_btn_clicked()
{
    if (!send) {
        ui->textEdit->append("请先连接数据库以创建 SQLsend");
        return;
    }
    ui->textEdit->append("开始手动上传测试...");
    // trigger pre-capture upload (source) and then do processing upload
    send->getinfo(1,1);
    // wait a moment then start processing (optional)
    send->start_deal();
}

void MainWindow::receivetable(QString str)
{
    ui->table_label->setText(str);
}
void MainWindow::receiveSQL(QString str)
{
    ui->SQL_label->setText(str);
}

// Removed legacy usedcamera slot (Pixelink HANDLE usage no longer used)

//sql and auto_deal
QSqlError MainWindow::addconnection(const QString dbname, const QString host, const QString user, const QString passwd, int port)
{
    QSqlError err;
    // Prefer QTDS if available; otherwise fallback to QODBC + FreeTDS (better on ARM)
    QStringList drivers = QSqlDatabase::drivers();
    QString driverToUse;
    if (drivers.contains("QTDS")) {
        driverToUse = "QTDS";
    } else if (drivers.contains("QODBC")) {
        driverToUse = "QODBC";
    } else {
        qDebug() << "No suitable Qt SQL driver found. Please install QTDS or QODBC (FreeTDS).";
        err = QSqlError("Driver not found", "No suitable Qt SQL driver found", QSqlError::ConnectionError);
        return err;
    }

    QSqlDatabase db = QSqlDatabase::addDatabase(driverToUse);
    if (driverToUse == "QTDS") {
        db.setDatabaseName(dbname);
        db.setHostName(host);
        db.setPort(port);
        if(!db.open(user,passwd))
        {
            err = db.lastError();
        }
    } else {
        // QODBC path, using FreeTDS driver string suitable for Linux ARM
        QString conn = QString("Driver={FreeTDS};Server=%1,%2;Database=%3;Uid=%4;Pwd=%5;TDS_Version=7.4;")
                .arg(host)
                .arg(port)
                .arg(dbname)
                .arg(user)
                .arg(passwd);
        db.setDatabaseName(conn);
        if(!db.open())
        {
            err = db.lastError();
        }
    }
    return err;
}

void MainWindow::do_connect()
{
    database = condia->databasename();
    host = condia->hostname();
    user = condia->username();
    pwd = condia->password();
    port = condia->port();

    QSqlError err = addconnection(database,host,user,pwd,port);
    if(err.type()!=QSqlError::NoError)
        ui->textEdit->append(err.text());
    else
    {
        database_or_not = true;
        ui->textEdit->append("连接数据库成功");
        ui->status_label->setText(QString("connected"));
        // create SQLsend if not present
        if (!send) {
            QString table = ui->table_label->text();
            // defaults for model, point, num, info and thresholds
            int model = 1;
            int point = 1;
            int num = 1;
            QString info = ui->table_label->text();
            int pixe_real = ui->pixe_real->text().toInt();
            int defect_point = ui->defect_piont->text().toInt();
            int defect_all = ui->defect_all->text().toInt();
            send = new SQLsend(database, host, user, pwd, port, table, &m_camera[0], model, point, num, info, pixe_real, defect_point, defect_all, this);
            connect(send, &SQLsend::get_src, this, [&](bool ok){ ui->textEdit->append(ok ? "上传前图完成" : "上传前图失败"); });
            connect(send, &SQLsend::senddamage, this, [&](float d){ ui->textEdit->append(QString("上传检测结果：%1").arg(d)); });
            connect(send, &SQLsend::sendcap, this, [&](bool c){ ui->textEdit->append(c ? "已采集图像" : "未采集图像"); });
            ui->textEdit->append("SQLsend 已创建并连接到摄像头。");
                qDebug() << "Available Qt SQL drivers:" << QSqlDatabase::drivers();
        }
    }
}

// UI slot stubs (implement simple behaviors or no-ops to satisfy linker)
void MainWindow::on_scanButton_clicked()
{
    // trigger device enumeration
    EnumerateDevices();
}

void MainWindow::on_cameraList_currentIndexChanged(int index)
{
    Q_UNUSED(index);
}

void MainWindow::on_openSelected_1_clicked()
{
}

void MainWindow::on_openSelected_2_clicked()
{
}

void MainWindow::on_openBySN_1_clicked()
{
}

void MainWindow::on_openBySN_2_clicked()
{
}

void MainWindow::on_openByUserID_1_clicked()
{
}

void MainWindow::on_openByUserID_2_clicked()
{
}

void MainWindow::on_close_1_clicked()
{
}

void MainWindow::on_close_2_clicked()
{
}

void MainWindow::on_singleShot_1_clicked()
{
}

void MainWindow::on_singleShot_2_clicked()
{
}

void MainWindow::on_continuous_1_clicked()
{
}

void MainWindow::on_continuous_2_clicked()
{
}

void MainWindow::on_stop_1_clicked()
{
}

void MainWindow::on_stop_2_clicked()
{
}

void MainWindow::on_exposure_1_valueChanged(int value)
{
    Q_UNUSED(value);
}

void MainWindow::on_exposure_2_valueChanged(int value)
{
    Q_UNUSED(value);
}

void MainWindow::on_gain_1_valueChanged(int value)
{
    Q_UNUSED(value);
}

void MainWindow::on_gain_2_valueChanged(int value)
{
    Q_UNUSED(value);
}

void MainWindow::on_pixelFormat_1_currentIndexChanged(int index)
{
    Q_UNUSED(index);
}

void MainWindow::on_pixelFormat_2_currentIndexChanged(int index)
{
    Q_UNUSED(index);
}

void MainWindow::on_triggerMode_1_currentTextChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
}

void MainWindow::on_triggerMode_2_currentTextChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
}

void MainWindow::on_triggerSource_1_currentTextChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
}

void MainWindow::on_triggerSource_2_currentTextChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
}

void MainWindow::on_softwareTrigger_1_clicked()
{
}

void MainWindow::on_softwareTrigger_2_clicked()
{
}

void MainWindow::on_invertPixel_1_toggled(bool checked)
{
    Q_UNUSED(checked);
}

void MainWindow::on_invertPixel_2_toggled(bool checked)
{
    Q_UNUSED(checked);
}

void MainWindow::OnUpdateTimer()
{
    // Called from internal timer — no-op stub
}

void MainWindow::on_editSN_1_textEdited(const QString &arg1)
{
    Q_UNUSED(arg1);
}

void MainWindow::on_editSN_2_textEdited(const QString &arg1)
{
    Q_UNUSED(arg1);
}

void MainWindow::on_editUserID_1_textEdited(const QString &arg1)
{
    Q_UNUSED(arg1);
}

void MainWindow::on_editUserID_2_textEdited(const QString &arg1)
{
    Q_UNUSED(arg1);
}

void MainWindow::receivemessage()
{
    // placeholder: process incoming messages
}

void MainWindow::receivesrc(bool s)
{
    Q_UNUSED(s);
}

void MainWindow::receivedamage(float d)
{
    Q_UNUSED(d);
}

void MainWindow::receivecap(bool c)
{
    Q_UNUSED(c);
}

void MainWindow::send_get(bool get)
{
    Q_UNUSED(get);
}

void MainWindow::send_ready(bool ready)
{
    Q_UNUSED(ready);
}

void MainWindow::send_deal_1(bool deal, bool success)
{
    Q_UNUSED(deal);
    Q_UNUSED(success);
}

void MainWindow::send_cap(bool cap)
{
    Q_UNUSED(cap);
}

void MainWindow::send_finish(bool t)
{
    Q_UNUSED(t);
}

void MainWindow::receiveruler_parameters(QString p, QString h, QString t)
{
    Q_UNUSED(p);
    Q_UNUSED(h);
    Q_UNUSED(t);
}

// ... rest of file unchanged (omitted for brevity in this submission)
