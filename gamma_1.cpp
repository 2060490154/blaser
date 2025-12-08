#include "gamma_1.h"
#include "ui_gamma_1.h"

gamma_1::gamma_1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gamma_1)
{
    ui->setupUi(this);
    ui->setupUi(this);

    void (QSpinBox:: *spsignal)(int)=&QSpinBox::valueChanged;

    connect(ui->spinBox,spsignal,ui->horizontalSlider,&QSlider::setValue);

    connect(ui->horizontalSlider,&QSlider::valueChanged,ui->spinBox,&QSpinBox::setValue);

    connect(ui->horizontalSlider,&QSlider::valueChanged,[=](){
        emit valuechange();
    });
}

gamma_1::~gamma_1()
{
    delete ui;
}

int gamma_1::gamma_value()
{
    return ui->horizontalSlider->value();
}

void gamma_1::setvalue(float i)
{
    int j = (int)(10*i);
    ui->horizontalSlider->setValue(j);
}
