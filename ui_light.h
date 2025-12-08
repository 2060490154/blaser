/********************************************************************************
** Form generated from reading UI file 'light.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIGHT_H
#define UI_LIGHT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_light
{
public:
    QWidget *widget;
    QSpinBox *spinBox;
    QSlider *horizontalSlider;

    void setupUi(QWidget *light)
    {
        if (light->objectName().isEmpty())
            light->setObjectName(QString::fromUtf8("light"));
        light->resize(270, 60);
        widget = new QWidget(light);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 10, 261, 44));
        spinBox = new QSpinBox(widget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(9, 9, 71, 26));
        spinBox->setMinimum(30);
        spinBox->setMaximum(100000);
        spinBox->setSingleStep(10);
        horizontalSlider = new QSlider(widget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(80, 10, 170, 26));
        horizontalSlider->setMaximum(100000);
        horizontalSlider->setSingleStep(10);
        horizontalSlider->setPageStep(20);
        horizontalSlider->setOrientation(Qt::Horizontal);

        retranslateUi(light);

        QMetaObject::connectSlotsByName(light);
    } // setupUi

    void retranslateUi(QWidget *light)
    {
        light->setWindowTitle(QCoreApplication::translate("light", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class light: public Ui_light {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIGHT_H
