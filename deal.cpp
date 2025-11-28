#include "deal.h"
#include "ui_deal.h"
#include <QFileDialog>
#include <QPainter>
#include <QStandardItemModel>
#include <QHeaderView>




deal::deal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::deal)
{
    ui->setupUi(this);
    setWindowTitle("图像处理界面");
    QDesktopWidget *desktop = QApplication::desktop();
    move((desktop->width()-this->width())/1.2,(desktop->height()-this->height())/2);

    QStandardItemModel *model = new QStandardItemModel;
    model->setHorizontalHeaderLabels({"编号","x","y","等效直径"});
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //ui->tableView->setModel(model);

    //choose and save the picture
    connect(ui->actionChoose_file,&QAction::triggered,[=](){
        QString path = QFileDialog::getOpenFileName(this,"图像选择",QDir::currentPath(),tr("图像文件(*.png *.jpg *.jpeg *.bmp)"));
        if(path.isEmpty())
        {
            QMessageBox::warning(this,"warning","请选择一张图片");
        }
        else
        {
            ui->lineEdit->setText(path);
            Mat imgData = imread(path.toLatin1().data());
            cvtColor(imgData,imgData,COLOR_BGR2RGB);
            myImg = imgData;
            myQImg = QImage((const unsigned char*)(imgData.data),imgData.cols,imgData.rows,QImage::Format_RGB888);
            recvShowPicSignal(myQImg);
        }
    });
    connect(ui->actionSave_picture,&QAction::triggered,[=](){
        QString filename = QFileDialog::getSaveFileName(this,tr("图像保存"),QDir::currentPath(),tr("图像文件(*.png *.jpg *.jpeg *.bmp)"));
        QImage saveimg = myQImg;
        saveimg.save(filename);
    });


    connect(ui->contrastslider,&QSlider::valueChanged,[=](){
        int i = contrastvalue();
        int j = brightvalue();
        imgProc(i/33.3,j);
    });

    connect(ui->lightslider,&QSlider::valueChanged,[=](){
        int i = contrastvalue();
        int j = brightvalue();
        imgProc(i/33.3,j);
    });

    //analysis about the damage
    connect(ui->back_btn,&QPushButton::clicked,[=](){
        QString filename = QFileDialog::getOpenFileName(this,tr("选择背景图片"),QString("/home/nvidia/qtDemo/testPic/"),tr("图像文件(*.png *.jpg *.jpeg *.bmp)"));
        if(filename.isEmpty())
        {
            QMessageBox::warning(this,"warning","请选择一张图片");
        }
        else
        {
            ui->back_edit->setText(filename);
            Mat imgData = imread(filename.toLatin1().data());
            myImg_b = imgData;
            namedWindow("背景图片",0);
            resizeWindow("背景图片",480,360);
            imshow("背景图片",myImg_b);
        }
    });

    connect(ui->forward_btn,&QPushButton::clicked,[=](){
        QString filename = QFileDialog::getOpenFileName(this,tr("选择前景图片"),QString("/home/nvidia/qtDemo/testPic/"),tr("图像文件(*.png *.jpg *.jpeg *.bmp)"));
        if(filename.isEmpty())
        {
            QMessageBox::warning(this,"warning","请选择一张图片");
        }
        else
        {
            ui->forward_edit->setText(filename);
            Mat imgData = imread(filename.toLatin1().data());
            myImg_f = imgData;
            namedWindow("前景图片",0);
            resizeWindow("前景图片",480,360);
            imshow("前景图片",myImg_f);
        }
    });

    connect(ui->ana_btn,&QPushButton::clicked,[=](){
        int i;
        float d;
        analysis(myImg_b,myImg_f,myImg,i,d);
        ui->num_label->setText(QString::number(i));
        ui->d_label->setText(QString::number(d,'f',2));
        myQImg = QImage((const unsigned char*)(myImg.data),myImg.cols,myImg.rows,QImage::Format_RGB888);
        recvShowPicSignal(myQImg);
        for(int m=0;m<i;m++)
        {
            model->setItem(m,0,new QStandardItem(dia[m].P_name));
            model->setItem(m,1,new QStandardItem(QString("%1").arg(dia[m].P_X)));
            model->setItem(m,2,new QStandardItem(QString("%1").arg(dia[m].P_Y)));
            model->setItem(m,3,new QStandardItem(QString::number(dia[m].P_diameter,'f',2)));
        }
        ui->tableView->setModel(model);
    });

    //ruler settings
    connect(ruler,SIGNAL(rulerparameters(QString,QString,QString)),this,SLOT(receiveruler_parameters(QString,QString,QString)));
    connect(ui->ruler_btn,&QPushButton::clicked,[=](){
        ruler->show();
    });
}

deal::~deal()
{
    delete ui;
}

void deal::recvShowPicSignal(QImage image)
{
    QPixmap ConvertPixmap=QPixmap::fromImage(image);//The QPixmap class is an off-screen image representation that can be used as a paint device
    QGraphicsScene  *qgraphicsScene = new QGraphicsScene;//要用QGraphicsView就必须要有QGraphicsScene搭配着用
    m_Image = new ImageWidget(&ConvertPixmap);//实例化类ImageWidget的对象m_Image，该类继承自QGraphicsItem，是自己写的类
    int nwith = ui->ImageGraphic->width();//获取界面控件Graphics View的宽度
    int nheight = ui->ImageGraphic->height();//获取界面控件Graphics View的高度
    m_Image->setQGraphicsViewWH(nwith,nheight);//将界面控件Graphics View的width和height传进类m_Image中
    qgraphicsScene->addItem(m_Image);//将QGraphicsItem类对象放进QGraphicsScene中
    ui->ImageGraphic->setSceneRect(QRectF(-(nwith/2),-(nheight/2),nwith,nheight));//使视窗的大小固定在原始大小，不会随图片的放大而放大（默认状态下图片放大的时候视窗两边会自动出现滚动条，并且视窗内的视野会变大），防止图片放大后重新缩小的时候视窗太大而不方便观察图片
    ui->ImageGraphic->setScene(qgraphicsScene);//Sets the current scene to scene. If scene is already being viewed, this function does nothing.
    ui->ImageGraphic->setFocus();//将界面的焦点设置到当前Graphics View控件
}


void deal::imgProc(float contrast, int bright)
{
    Mat imgsrc = myImg;
    Mat imgdst = Mat::zeros(imgsrc.size(),imgsrc.type());
    imgsrc.convertTo(imgdst,-1,contrast,bright);
    myQImg = QImage((const unsigned char*)(imgdst.data),imgdst.cols,imgdst.rows,QImage::Format_RGB888);
    recvShowPicSignal(myQImg);
}

int deal::contrastvalue()
{
    return ui->contrastslider->value();
}

int deal::brightvalue()
{
    return ui->lightslider->value();
}

void deal::analysis(Mat img1, Mat img2, Mat &img3,int &i,float &d)
{
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    float area = 0;
    float total_area = 0;
    float diameter;
    i=0;
    int thred;
    int j = 0;
    Mat srcImg;
    Mat saveImg;

    saveImg = img2;

    cvtColor(img1,img1,COLOR_RGB2GRAY);
    cvtColor(img2,img2,COLOR_RGB2GRAY);
    absdiff(img1,img2,srcImg);

    int Channels[] = { 0 };
    int nHistSize[] = { 256 };
    float range[] = { 0, 255 };
    const float* fHistRanges[] = { range };
    Mat hist;
    calcHist(&srcImg, 1, Channels, Mat(), hist, 1, nHistSize, fHistRanges, true, false);
    //normalize(hist, hist, 0.0, matHistImage.rows, NORM_MINMAX, -1, Mat());

    for (int i = 2; i < 253; i++)
    {
            if ((cvRound(hist.at<uchar>(i) <= cvRound(hist.at<uchar>(i + 1))) && (cvRound(hist.at<uchar>(i + 1))) <= cvRound(hist.at<uchar>(i + 2))))
            {
//                if(i>10)
//                {
                    thred = i;
                    break;
//                }
            }
    }
    threshold(srcImg,srcImg,thred,255,0);

    Mat out;
    Mat element = getStructuringElement(MORPH_RECT, Size(5, 5));
    morphologyEx(srcImg, out, MORPH_OPEN, element);

    findContours(out,contours,hierarchy,RETR_CCOMP,CHAIN_APPROX_NONE);

    for (unsigned int index=0;index<contours.size();index++)
    {
        area=contourArea(contours[index]);
        diameter = sqrt(4*area/pi);
        if(diameter>=10)
        {
            i+=1;
            dia[j].P_name = QString("PG%1").arg(i);
            dia[j].P_diameter = diameter;
            total_area+=area;

            Moments mom = moments(contours[index]);
            Point pt = Point(mom.m10 / mom.m00,mom.m01/mom.m00);
            dia[j].P_X = pt.x;
            dia[j].P_Y = pt.y;
            Scalar color(0,0,255);
            putText(saveImg,dia[j].P_name.toStdString(),Point(pt.x+20,pt.y+20),FONT_HERSHEY_PLAIN,1.5,color,1,8,0);
            drawContours(saveImg,contours,index,color,1,8,hierarchy);
            j+=1;
        }
    }

    d=sqrt(4*total_area/pi);
    cvtColor(saveImg,saveImg,COLOR_BGR2RGB);
    img3 = saveImg.clone();

}

void deal::receiveruler_parameters(QString p, QString h, QString t)
{
    int x_num,y_num;
    x_num=myImg.cols;
    y_num=myImg.rows;
    Point p1(x_num-x_num/5,y_num-y_num/5);
    Point p2(x_num-x_num/5-p.toInt(),y_num-y_num/5);

    line(myImg,p1,p2,Scalar(255,255,255),h.toInt());

    QString ruler_str = t;
    putText(myImg,ruler_str.toStdString(),Point(p2.x,p2.y+25),FONT_HERSHEY_PLAIN,1.5,Scalar(255,255,255),2,8,0);
    //cvtColor(myImg,myImg,COLOR_BGR2RGB);

    //imshow("test",myImg);

    myQImg = QImage((const unsigned char*)(myImg.data),myImg.cols,myImg.rows,QImage::Format_RGB888);
    recvShowPicSignal(myQImg);
}
