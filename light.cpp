#include "light.h"
#include "ui_light.h"

light::light(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::light)
{
    ui->setupUi(this);
    void (QSpinBox:: *spsignal)(int)=&QSpinBox::valueChanged;
    connect(ui->spinBox,spsignal,ui->horizontalSlider,&QSlider::setValue);

    connect(ui->horizontalSlider,&QSlider::valueChanged,ui->spinBox,&QSpinBox::setValue);

    connect(ui->horizontalSlider,&QSlider::valueChanged,[=](){
        emit valuechange();
    });
}

light::~light()
{
    delete ui;
}

int light::light_value()
{
    return ui->horizontalSlider->value();
}

void light::setvalue(float i)
{
    int ret = (int)(i);
    ui->horizontalSlider->setValue(ret);
}
