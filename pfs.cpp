#include "pfs.h"
#include "ui_pfs.h"

pfs::pfs(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pfs)
{
    ui->setupUi(this);
    void (QSpinBox:: *spsignal)(int)=&QSpinBox::valueChanged;
    connect(ui->spinBox,spsignal,ui->horizontalSlider,&QSlider::setValue);

    connect(ui->horizontalSlider,&QSlider::valueChanged,ui->spinBox,&QSpinBox::setValue);

    connect(ui->horizontalSlider,&QSlider::valueChanged,[=](){
        emit valuechange();
    });
}

pfs::~pfs()
{
    delete ui;
}

int pfs::pfs_value()
{
    return ui->horizontalSlider->value();
}

void pfs::setvalue(float i)
{
    int j = (int)(i);
    ui->horizontalSlider->setValue(j);
}
