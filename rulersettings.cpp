#include "rulersettings.h"
#include "ui_rulersettings.h"
#include <QDesktopWidget>

rulersettings::rulersettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::rulersettings)
{
    ui->setupUi(this);
    setWindowTitle("标尺设置");
    QDesktopWidget *desktop = QApplication::desktop();
    move((desktop->width()-this->width())/2,(desktop->height()-this->height())/2);
    connect(ui->btn1,&QPushButton::clicked,[=](){
        QString pixes = ui->pixe_line->text();
        QString height = ui->height_line->text();
        QString longth = ui->real_line->text();
        emit rulerparameters(pixes,height,longth);
        this->hide();
    });
    connect(ui->btn2,&QPushButton::clicked,[=](){
        this->hide();
    });
}

rulersettings::~rulersettings()
{
    delete ui;
}
