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

    //connect(PXLcamera,SIGNAL(sendcamera(HANDLE)),this,SLOT(usedcamera(HANDLE)));
    connect(m_camera,SIGNAL(sendcamera(HANDLE)),this,SLOT(usedcamera(HANDLE)));

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


void MainWindow::on_connect_btn_clicked()
{
    condia->show();
}

void MainWindow::receivetable(QString str)
{
    ui->table_label->setText(str);
}
void MainWindow::receiveSQL(QString str)
{
    ui->SQL_label->setText(str);
}

void MainWindow::usedcamera(HANDLE c)
{
    sendcamera = c;
}

//sql and auto_deal
QSqlError MainWindow::addconnection(const QString dbname, const QString host, const QString user, const QString passwd, int port)
{
    QSqlError err;
    QSqlDatabase db = QSqlDatabase::addDatabase("QTDS");
    db.setDatabaseName(dbname);
    db.setHostName(host);
    db.setPort(port);
    if(!db.open(user,passwd))
    {
        err = db.lastError();
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
    }
}

void MainWindow::receivedamage(float d)
{
    ui->textEdit->append(QString("损伤点等效直径为：%1").arg(d));
    if(d>=ui->defect_all->text().toInt())
    {
        damage_or_not = true;
    }
    deal_or_not = true;
    emit deal_finish();
}

void MainWindow::receivecap(bool c)
{
    if(c)
    {
        cap_or_not = true;
        send_cap(cap_or_not);
    }
    else
        cap_or_not = false;
}

void MainWindow::receivesrc(bool s)
{
    if(s)
    {
        ready_or_not = true;
    }
    else
        QMessageBox::warning(this,"error","打前图像采集失败");
    send_ready(ready_or_not);
}

void MainWindow::creatDealThread()
{
//    int pixe = ui->pixe_real->text().toInt();
//    int point_max = ui->defect_piont->text().toInt();
//    int defect_max = ui->defect_all->text().toInt();
    send = new SQLsend(database,host,user,pwd,port,ui->table_label->text(),sendcamera,TestModel,GetTestPoint,GetRoundNum,TestInfo,ui->pixe_real->text().toInt(),ui->defect_piont->text().toInt(),ui->defect_all->text().toInt());
    threadsend = new QThread;
    send->moveToThread(threadsend);
    threadsend->start();
    ui->textEdit->append("开启处理线程");
    connect(this,SIGNAL(giveinfo(char,char)),send,SLOT(getinfo(char,char)));
    connect(send,SIGNAL(get_src(bool)),this,SLOT(receivesrc(bool)));
    connect(this,SIGNAL(begain_to_deal()),send,SLOT(start_deal()));
    connect(send,SIGNAL(senddamage(float)),this,SLOT(receivedamage(float)));
    connect(send,SIGNAL(sendcap(bool)),this,SLOT(receivecap(bool)));
    connect(threadsend,&QThread::finished,send,&SQLsend::deleteLater);
    thread_or_not = true;
}

//udp socket
void MainWindow::receivemessage()
{
    while(usocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        QByteArray info;
        QString get_str;
        //qDebug()<<"receive";

        datagram.resize(usocket->pendingDatagramSize());
        usocket->readDatagram(datagram.data(),datagram.size(),&hostadd,&hostport);


        if(datagram.at(0)==0xA0)
        {
            if(datagram.at(1)==0x01)
                TestModel = 1;//1 on 1
            else if(datagram.at(1)==0x02)
                TestModel = 2;//R on 1
            info = datagram.right(20);
            TestInfo = info;
            if (!TestInfo.isEmpty())
            {
                get_or_not = true;
//                if((!thread_or_not)&&(!ui->pixe_real->text().isEmpty())&&(!ui->defect_piont->text().isEmpty())&&(!ui->defect_all->text().isEmpty())&&database_or_not)
//                    creatDealThread();
//                else if((ui->pixe_real->text().isEmpty())||(ui->defect_piont->text().isEmpty())||(ui->defect_all->text().isEmpty()))
//                    QMessageBox::warning(this,"error","请输入像素参数");
//                else if(!database_or_not)
//                    QMessageBox::warning(this,"error","未连接数据库");
            }
            else
                ui->textEdit->append("实验信息为空");
            QByteArray by = datagram.left(2);
            get_str = by.toHex() + info;
            send_get(get_or_not);
        }
        if(datagram.at(0)==0xA1)
        {
            qDebug()<<"11111111";
            Delay_MSec(800);
            qDebug()<<"222222";
            GetTestPoint = datagram.at(1);
            GetRoundNum = datagram.at(2);
            qDebug()<<"ready";
            if(!init_or_not)
            {
                QMessageBox::warning(this,"error","CCD初始化未完成，准备失败");
                ui->textEdit->append("CCD初始化未完成，准备失败");
                send_ready(ready_or_not);
            }
            else if((ui->pixe_real->text().isEmpty())||(ui->defect_piont->text().isEmpty())||(ui->defect_all->text().isEmpty()))
            {
                QMessageBox::warning(this,"error","请输入像素参数");
                ui->textEdit->append("像素参数未设置，准备失败");
                send_ready(ready_or_not);
            }
            else if(!database_or_not)
            {
                QMessageBox::warning(this,"error","未连接数据库");
                ui->textEdit->append("未连接数据库，准备失败");
                send_ready(ready_or_not);
            }

            else if(!thread_or_not)
            {
                creatDealThread();
                emit giveinfo(GetTestPoint,GetRoundNum);
            }
            else
            {
                //qDebug()<<"22222";
                emit giveinfo(GetTestPoint,GetRoundNum);
            }
            get_str = datagram.toHex();
        }
        if(datagram.at(0)==0xA2)
        {
            GiveTestPoint = datagram.at(2);
            GiveRoundNum = datagram.at(1);
            get_str = datagram.toHex();
            while(!deal_or_not)
            {
                QCoreApplication::processEvents(QEventLoop::AllEvents,50);
            }
            send_deal_1(damage_or_not,deal_or_not);
        }
        if(datagram.at(0) == 0xA3)
        {
            deal_or_not = false;
            get_str = datagram.toHex();
            emit begain_to_deal();
        }
        if(datagram.at(0) == 0xA4)
        {
            qDebug()<<"quit thread";
            get_str = datagram.toHex();
            threadsend->quit();
            threadsend->wait();
            thread_or_not = false;
            ui->textEdit->append("实验结束");
            send_finish(thread_or_not);
        }
        ui->socket_text->append(get_str);
    }
}


void MainWindow::send_get(bool get)
{
    message_s send_get;
    QByteArray data;
    send_get.command[0] = 0xA0;
    send_get.roud_info[0] = 0x00;

    if(get)
    {
        send_get.return_ok[0] = 0x01;
    }
    else
    {
        send_get.command[0] = 0xA0;
    }

    data.append(send_get.command,sizeof(send_get.command));
    data.append(send_get.return_ok,sizeof(send_get.return_ok));
    data.append(send_get.roud_info,sizeof(send_get.roud_info));
    data.append(send_get.other,sizeof(send_get.other));
    get_or_not = false;

    usocket->writeDatagram(data.data(),data.size(),hostadd,hostport);

}

void MainWindow::send_ready(bool ready)
{
    message_s send_ready;
    QByteArray data;
    send_ready.command[0] = 0xA1;
    send_ready.roud_info[0] = 0x00;
    if(ready)
    {
        send_ready.return_ok[0] = 0x01;
    }
    else
    {
        send_ready.return_ok[0] = 0x02;
    }

    data.append(send_ready.command,sizeof(send_ready.command));
    data.append(send_ready.return_ok,sizeof(send_ready.return_ok));
    data.append(send_ready.roud_info,sizeof(send_ready.roud_info));
    data.append(send_ready.other,sizeof(send_ready.other));

    usocket->writeDatagram(data.data(),data.size(),hostadd,hostport);
}

void MainWindow::send_deal_1(bool deal, bool success)
{
    message_s send_deal;
    QByteArray data;
    send_deal.command[0] = 0xA2;
    send_deal.roud_info[0] = GiveRoundNum;
    send_deal.other[0] = GiveTestPoint;


    if((!deal)&&success)
    {
        send_deal.return_ok[0] = 0x01;

    }
    if((deal)&&success)
    {
        send_deal.return_ok[0] = 0x02;
        damage_or_not = false;
    }
    else if(!success)
    {
        send_deal.return_ok[0] = 0x03;
    }


    data.append(send_deal.command,sizeof(send_deal.command));
    data.append(send_deal.return_ok,sizeof(send_deal.return_ok));
    data.append(send_deal.roud_info,sizeof(send_deal.roud_info));
    data.append(send_deal.other,sizeof(send_deal.other));

    usocket->writeDatagram(data.data(),data.size(),hostadd,hostport);
}

void MainWindow::send_cap(bool cap)
{
    message_s send_cap;
    QByteArray data;
    send_cap.command[0] = 0xA3;
    send_cap.roud_info[0] = 0x00;
    if(cap)
        send_cap.return_ok[0] = 0x01;
    else
        send_cap.return_ok[0] = 0x02;
    data.append(send_cap.command,sizeof(send_cap.command));
    data.append(send_cap.return_ok,sizeof(send_cap.return_ok));
    data.append(send_cap.roud_info,sizeof(send_cap.roud_info));
    data.append(send_cap.other,sizeof(send_cap.other));

    usocket->writeDatagram(data.data(),data.size(),hostadd,hostport);
}

void MainWindow::send_finish(bool t)
{
    message_s send_finish;
    QByteArray data;
    send_finish.command[0] = 0xA4;
    send_finish.roud_info[0] = 0x00;
    if(!t)
    {
        send_finish.return_ok[0] = 0x01;
    }
    else
        send_finish.return_ok[0] = 0x02;
    data.append(send_finish.command,sizeof(send_finish.command));
    data.append(send_finish.return_ok,sizeof(send_finish.return_ok));
    data.append(send_finish.roud_info,sizeof(send_finish.roud_info));
    data.append(send_finish.other,sizeof(send_finish.other));

    usocket->writeDatagram(data.data(),data.size(),hostadd,hostport);

}

void MainWindow::creatudp()
{
    bool result;

    result = usocket->bind(6101);
    if(!result)
    {
        QMessageBox::information(this,tr("error"),tr("udp create error"));
        return;
    }
    else
        ui->socket_text->append("创建UDP SOCKET成功");

    connect(usocket,&QUdpSocket::readyRead,this,&MainWindow::receivemessage);
}

//delay function
void MainWindow::Delay_MSec(unsigned int msec)
{
    QEventLoop loop;
    QTimer::singleShot(msec,&loop,SLOT(quit()));
    loop.exec();
}

//capture
void MainWindow::receiveruler_parameters(QString p, QString h, QString t)
{
    ruler_pixe = p.toInt();
    ruler_height = h.toInt();
    ruler_real = t;

    ui->pixe_label->setText(p);
    ui->height_label->setText(h);
    ui->longth_label->setText(t);
}


///////////////////////new add
void MainWindow::cameraplay()
{

        try
    {
        m_camera[0].ContinuousGrab();
    }
    catch (const Pylon::GenericException& e)
    {
        ShowWarning( QString( "Could not start grab!\n" ) + QString( e.GetDescription() ) );
    }


    camera_flag = 1;
}

void MainWindow::camerastop()
{

    try
    {
        m_camera[0].StopGrab();
    }
    catch (const Pylon::GenericException& e)
    {
        ShowWarning( QString( "Could not stop grab!\n" ) + QString( e.GetDescription() ) );
    }
    camera_flag = 0;
}

void MainWindow::showEvent(QShowEvent *event)
{
    QMainWindow::showEvent( event );

    // Enable/disable controls.
    for (int i = 0; i < MaxCamera; i++)
    {
        UpdateCameraDialog( i );
    }

    // Set timer for status bar (1000 ms update interval).
    connect(&m_updateTimer, SIGNAL(timeout()), this, SLOT(OnUpdateTimer()));
    m_updateTimer.start(1000);

    // Simulate the user clicking the Discover Cameras button.
    //on_scanButton_clicked();
}


// Update the camera dialog by enabling/disabling control elements according to the camera state.
void MainWindow::UpdateCameraDialog( int cameraId )
{

}


// This gets called every second. Update the status bar texts.
void MainWindow::OnUpdateTimer()
{
    // Update the status bars.
    if (m_camera[0].IsOpen())
    {
        uint64_t imageCount = m_camera[0].GetGrabbedImages();
        uint64_t errorCount = m_camera[0].GetGrabErrors();
        // Very rough approximation approximation. The timer is triggerd every second.
        double fpsEstimate = (double) m_camera[0].GetGrabbedImagesDiff();

        QString status = QString( "Frame rate: %0 fps\tImages: %1\tErrors: %2").arg(fpsEstimate, 6, 'f', 1).arg(imageCount).arg(errorCount);

    }
    else
    {

    }

}


// Helper function to get a list of all attached devices and store it in m_devices.
int MainWindow::EnumerateDevices()
{
    Pylon::DeviceInfoList_t devices;
    try
    {
        // Get the transport layer factory.
        Pylon::CTlFactory& TlFactory = Pylon::CTlFactory::GetInstance();

        // Get all attached cameras.
        TlFactory.EnumerateDevices( devices );
    }
    catch (const Pylon::GenericException& e)
    {
        PYLON_UNUSED( e );
        devices.clear();

        qDebug() << e.GetDescription();
    }

    m_devices = devices;

    // When calling this function, make sure to update the device list control
    // because its items store pointers to elements in the m_devices list.
    return (int) m_devices.size();
}


// Show a warning dialog.
void MainWindow::ShowWarning( QString warningText )
{
    QMessageBox::warning( this, "GUI Sample", warningText, QMessageBox::Ok );
}


// The Discover Cameras button has been clicked.
void MainWindow::on_scanButton_clicked()
{





}


// The Open Selected button for camera 1 has been clicked.
void MainWindow::on_openSelected_1_clicked()
{


}


// The Open Selected button for camera 2 has been clicked.
void MainWindow::on_openSelected_2_clicked()
{

}


// Enable the Open by SN button if a serial number has been entered.
void MainWindow::on_editSN_1_textEdited(const QString &arg1)
{

}


// Enable the Open by SN button if a serial number has been entered.
void MainWindow::on_editSN_2_textEdited(const QString &arg1)
{

}


// The Open by SN button for camera 1 has been clicked.
void MainWindow::on_openBySN_1_clicked()
{

}


// The Open by SN button for camera 2 has been clicked.
void MainWindow::on_openBySN_2_clicked()
{

}


// Enable the Open by User ID button if a user ID has been entered.
void MainWindow::on_editUserID_1_textEdited(const QString &arg1)
{

}


// Enable the Open by User ID button if a user ID has been entered.
void MainWindow::on_editUserID_2_textEdited(const QString &arg1)
{

}


// The Open by User ID button for camera 1 has been clicked.
void MainWindow::on_openByUserID_1_clicked()
{

}


// The Open by User ID button for camera 2 has been clicked.
void MainWindow::on_openByUserID_2_clicked()
{

}


// Helper function to open a CGuiCamera and update controls.
// After the camera has been opened, we adjust the controls to configure
// the camera features. Slider ranges are set and drop-down lists are filled
// with enumeration entries.
bool MainWindow::InternalOpenCamera( const Pylon::CDeviceInfo& devInfo, int cameraId )
{
    try
    {
        // Open() may throw exceptions.
        m_camera[cameraId].Open( devInfo );
    }
    catch (const Pylon::GenericException& e)
    {
        ShowWarning( QString("Could not open camera!\n") + QString( e.GetDescription() ) );

        return false;
    }

    try
    {
        // Update controls.
        UpdateCameraDialog( cameraId );
        if (cameraId == 0)
        {

        }
        else
        {
            assert( false );
        }

        return true;
    }
    catch (const Pylon::GenericException& e)
    {
        PYLON_UNUSED( e );
        return false;
    }
}


// Helper function to close a CGuiCamera and update controls.
// After the camera has been closed, we disable controls to configure the camera.
// Slider ranges are reset and drop-down lists are cleared.
void MainWindow::InternalCloseCamera( int cameraId )
{
    try
    {
        m_camera[cameraId].Close();

        // Enable/disable controls.
        UpdateCameraDialog( cameraId );
    }
    catch (const Pylon::GenericException& e)
    {
        PYLON_UNUSED( e );
    }
}


// The Close button for camera 1 has been clicked.
void MainWindow::on_close_1_clicked()
{
    InternalCloseCamera( 0 );

    // Make sure to repaint the image control.
    // The actual drawing is done in paintEvent.
    ui->image->repaint();
}


// The Close button for camera 2 has been clicked.
void MainWindow::on_close_2_clicked()
{

}


// Grab a single image.
void MainWindow::on_singleShot_1_clicked()
{
//    try
//    {
//        m_camera[0].SingleGrab();
//    }
//    catch (const Pylon::GenericException& e)
//    {
//        ShowWarning( QString( "Could not start grab!\n" ) + QString( e.GetDescription() ) );
//    }
}


// Grab a single image.
void MainWindow::on_singleShot_2_clicked()
{
//    try
//    {
//        m_camera[1].SingleGrab();
//    }
//    catch (const Pylon::GenericException& e)
//    {
//        ShowWarning( QString( "Could not start grab!\n" ) + QString( e.GetDescription() ) );
//    }
}


// Start a continuous grab.
void MainWindow::on_continuous_1_clicked()
{

}


// Start a continuous grab.
void MainWindow::on_continuous_2_clicked()
{

}


// Stop a continuous grab.
void MainWindow::on_stop_1_clicked()
{

}


// Stop a continuous grab.
void MainWindow::on_stop_2_clicked()
{

}


// Called to update value of slider.
void MainWindow::UpdateSlider( QSlider* pCtrl, Pylon::IIntegerEx& integerParameter )
{

}


// Update the control with the value of a camera parameter.
void MainWindow::UpdateSliderText( QLabel *pString, Pylon::IIntegerEx& integerParameter )
{

}


// Stores GenApi enumeration items into CComboBox.
void MainWindow::UpdateEnumeration( QComboBox* pCtrl, Pylon::IEnumerationEx& enumParameter )
{

}


// Reset a slider control to default values.
void MainWindow::ClearSlider( QSlider* pCtrl, QLabel* pString )
{

}


// Called to update the enumeration in a combo box.
void MainWindow::ClearEnumeration( QComboBox* pCtrl )
{

}


// This will be called in response to the NewGrabResult signal posted by
// CGuiCamera when a new grab result has been received.
// This function is called in the GUI thread so you can access GUI elements.
void MainWindow::OnNewGrabResult( int userHint )
{
    if ((userHint == 0) && m_camera[0].IsOpen())
    {
        // Make sure to repaint the image control.
        // The actual drawing is done in paintEvent.
        ui->image->repaint();
    }


}


// This overrides the paintEvent of the dialog to paint the images.
// For better performance and easy maintenance a custom control should be used.
void MainWindow::paintEvent(QPaintEvent *ev)
{
    QMainWindow::paintEvent(ev);

    // Repaint image of camera 1.
    if( m_camera[0].IsOpen())
    {
        QPainter painter(this);
        QRect target = ui->image->geometry();

        QMutexLocker locker( m_camera[0].GetBmpLock() );
        QImage Image = m_camera[0].GetImage();
        //cout<<"width"<<Image.width()<<"height"<<Image.height()<<endl;
        QRect source = QRect(0, 0, Image.width(), Image.height());
        painter.drawImage(target, Image, source);
    }

}


// This will be called in response to the DeviceRemoved signal posted by
// CGuiCamera when the camera has been disconnected.
// This function is called in the GUI thread so you can access GUI elements.
void MainWindow::OnDeviceRemoved( int userHint )
{

}


// This will be called in response to the NodeUpdated signal posted by
// CGuiCamera when a camera parameter changes its attributes or value.
// This function is called in the GUI thread so you can access GUI elements.
void MainWindow::OnNodeUpdated( int userHint, GenApi::INode* pNode )
{

}


// This will be called in response to the StateChanged signal posted by
// CGuiCamera when the grab is started or stopped.
// This function is called in the GUI thread so you can access GUI elements.
void MainWindow::OnStateChanged( int userHint, bool isGrabbing )
{

}


// This will be called when the Exposure Time slider is changed.
void MainWindow::on_exposure_1_valueChanged(int value)
{

}


// This will be called when the Exposure Time slider is changed.
void MainWindow::on_exposure_2_valueChanged(int value)
{

}


// This will be called when the Gain slider is changed.
void MainWindow::on_gain_1_valueChanged(int value)
{

}


// This will be called when the Gain slider is changed.
void MainWindow::on_gain_2_valueChanged(int value)
{

}


// This will be called when the setting of the Pixel Format drop-down list changes.
void MainWindow::on_pixelFormat_1_currentIndexChanged(int index)
{

}


// This will be called when the setting of the Pixel Format drop-down list changes.
void MainWindow::on_pixelFormat_2_currentIndexChanged(int index)
{

}


// This will be called when the setting of the Trigger Source drop-down list changes.
void MainWindow::on_triggerMode_1_currentTextChanged(const QString &arg1)
{

}


// This will be called when the setting of the Trigger Source drop-down list changes.
void MainWindow::on_triggerMode_2_currentTextChanged(const QString &arg1)
{

}


// This will be called when the setting of the Trigger Source drop-down list changes.
void MainWindow::on_triggerSource_1_currentTextChanged(const QString &arg1)
{

}


// This will be called when the setting of the Trigger Source drop-down list changes.
void MainWindow::on_triggerSource_2_currentTextChanged(const QString &arg1)
{

}


// This will be called when the Software Trigger button is clicked.
void MainWindow::on_softwareTrigger_1_clicked()
{

}


// This will be called when the Software Trigger button is clicked.
void MainWindow::on_softwareTrigger_2_clicked()
{

}


// This will be called when the state of the Invert Pixel checkbox changes. 负片
void MainWindow::on_invertPixel_1_toggled(bool checked)
{

}


// This will be called when the state of the Invert Pixel checkbox changes.
void MainWindow::on_invertPixel_2_toggled(bool checked)
{

}


// Enable/disable buttons when the user selects a camera in the camera box.
void MainWindow::on_cameraList_currentIndexChanged(int index)
{

}

