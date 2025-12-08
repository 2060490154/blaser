/********************************************************************************
** Form generated from reading UI file 'rgb.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RGB_H
#define UI_RGB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RGB
{
public:
    QGridLayout *gridLayout_2;
    QWidget *widget_3;
    QGridLayout *gridLayout;
    QLabel *label;
    QSpinBox *R_spin;
    QLabel *label_2;
    QSpinBox *G_spin;
    QSlider *G_slider;
    QLabel *label_3;
    QSpinBox *B_spin;
    QSlider *B_slider;
    QSlider *R_slider;
    QPushButton *auto_btn;

    void setupUi(QWidget *RGB)
    {
        if (RGB->objectName().isEmpty())
            RGB->setObjectName(QString::fromUtf8("RGB"));
        RGB->resize(329, 168);
        gridLayout_2 = new QGridLayout(RGB);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        widget_3 = new QWidget(RGB);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        gridLayout = new QGridLayout(widget_3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(widget_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFrameShape(QFrame::NoFrame);
        label->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        R_spin = new QSpinBox(widget_3);
        R_spin->setObjectName(QString::fromUtf8("R_spin"));
        R_spin->setMaximum(155);

        gridLayout->addWidget(R_spin, 0, 1, 1, 1);

        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        G_spin = new QSpinBox(widget_3);
        G_spin->setObjectName(QString::fromUtf8("G_spin"));
        G_spin->setMaximum(155);

        gridLayout->addWidget(G_spin, 1, 1, 1, 1);

        G_slider = new QSlider(widget_3);
        G_slider->setObjectName(QString::fromUtf8("G_slider"));
        G_slider->setMaximum(155);
        G_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(G_slider, 1, 2, 1, 1);

        label_3 = new QLabel(widget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        B_spin = new QSpinBox(widget_3);
        B_spin->setObjectName(QString::fromUtf8("B_spin"));
        B_spin->setMaximum(155);

        gridLayout->addWidget(B_spin, 2, 1, 1, 1);

        B_slider = new QSlider(widget_3);
        B_slider->setObjectName(QString::fromUtf8("B_slider"));
        B_slider->setMaximum(155);
        B_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(B_slider, 2, 2, 1, 1);

        R_slider = new QSlider(widget_3);
        R_slider->setObjectName(QString::fromUtf8("R_slider"));
        R_slider->setMaximum(155);
        R_slider->setSingleStep(1);
        R_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(R_slider, 0, 2, 1, 1);


        gridLayout_2->addWidget(widget_3, 0, 0, 1, 1);

        auto_btn = new QPushButton(RGB);
        auto_btn->setObjectName(QString::fromUtf8("auto_btn"));

        gridLayout_2->addWidget(auto_btn, 1, 0, 1, 1);


        retranslateUi(RGB);

        QMetaObject::connectSlotsByName(RGB);
    } // setupUi

    void retranslateUi(QWidget *RGB)
    {
        RGB->setWindowTitle(QCoreApplication::translate("RGB", "Form", nullptr));
        label->setText(QCoreApplication::translate("RGB", "Red", nullptr));
        label_2->setText(QCoreApplication::translate("RGB", "Green", nullptr));
        label_3->setText(QCoreApplication::translate("RGB", "Blue", nullptr));
        auto_btn->setText(QCoreApplication::translate("RGB", "auto", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RGB: public Ui_RGB {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RGB_H
