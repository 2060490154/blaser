#include "rgb.h"
#include "ui_rgb.h"
#include <iostream>
#include <stdio.h>
#include <stdexcept>
#include <unistd.h>
#include <vector>
#include <cassert>

#include <QDebug>

using namespace std;

RGB::RGB(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RGB)
{
    ui->setupUi(this);
    void (QSpinBox:: *spsignal)(int)=&QSpinBox::valueChanged;
    //connect the spin and slider
    connect(ui->R_spin,spsignal,ui->R_slider,&QSlider::setValue);
    connect(ui->R_slider,&QSlider::valueChanged,ui->R_spin,&QSpinBox::setValue);

    connect(ui->G_spin,spsignal,ui->G_slider,&QSlider::setValue);
    connect(ui->G_slider,&QSlider::valueChanged,ui->G_spin,&QSpinBox::setValue);

    connect(ui->B_spin,spsignal,ui->B_slider,&QSlider::setValue);
    connect(ui->B_slider,&QSlider::valueChanged,ui->B_spin,&QSpinBox::setValue);

    //connect the value and signal
    connect(ui->R_slider,&QSlider::valueChanged,[=](){
        emit R_change();
    });
    connect(ui->G_slider,&QSlider::valueChanged,[=](){
        emit G_change();
    });
    connect(ui->B_slider,&QSlider::valueChanged,[=](){
        emit B_change();
    });

    //connect the auto
    connect(ui->auto_btn,&QPushButton::clicked,[=](){
       emit do_auto();
    });

}

RGB::~RGB()
{
    delete ui;
}

int RGB::R_value()
{
    return ui->R_slider->value();
}

int RGB::G_value()
{
    return ui->G_slider->value();
}

int RGB::B_value()
{
    return ui->B_slider->value();
}

void RGB::setRGBvalue(float *colornums,int size)
{
    float R_value = colornums[0];
    int ret1 = (int)(R_value*10);
//    int ret1 = (int)(R_value*10+0.5f);
    ui->R_slider->setValue(ret1);

    float G_value = colornums[1];
    int ret2 = (int)(G_value*10);
//    int ret1 = (int)(R_value*10+0.5f);
    ui->G_slider->setValue(ret2);

    float B_value = colornums[2];
    int ret3 = (int)(B_value*10);
//    int ret1 = (int)(R_value*10+0.5f);
    ui->B_slider->setValue(ret3);
}
