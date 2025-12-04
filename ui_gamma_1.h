/********************************************************************************
** Form generated from reading UI file 'gamma_1.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMMA_1_H
#define UI_GAMMA_1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gamma_1
{
public:
    QWidget *widget;
    QSpinBox *spinBox;
    QSlider *horizontalSlider;

    void setupUi(QWidget *gamma_1)
    {
        if (gamma_1->objectName().isEmpty())
            gamma_1->setObjectName(QString::fromUtf8("gamma_1"));
        gamma_1->resize(256, 60);
        widget = new QWidget(gamma_1);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 10, 251, 44));
        spinBox = new QSpinBox(widget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(9, 9, 57, 26));
        spinBox->setMaximum(35);
        spinBox->setSingleStep(1);
        spinBox->setValue(0);
        horizontalSlider = new QSlider(widget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(70, 10, 170, 26));
        horizontalSlider->setMaximum(35);
        horizontalSlider->setSingleStep(1);
        horizontalSlider->setPageStep(5);
        horizontalSlider->setOrientation(Qt::Horizontal);

        retranslateUi(gamma_1);

        QMetaObject::connectSlotsByName(gamma_1);
    } // setupUi

    void retranslateUi(QWidget *gamma_1)
    {
        gamma_1->setWindowTitle(QCoreApplication::translate("gamma_1", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gamma_1: public Ui_gamma_1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMMA_1_H
