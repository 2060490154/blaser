/********************************************************************************
** Form generated from reading UI file 'pfs.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PFS_H
#define UI_PFS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pfs
{
public:
    QWidget *widget;
    QSpinBox *spinBox;
    QSlider *horizontalSlider;

    void setupUi(QWidget *pfs)
    {
        if (pfs->objectName().isEmpty())
            pfs->setObjectName(QString::fromUtf8("pfs"));
        pfs->resize(258, 60);
        widget = new QWidget(pfs);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 10, 251, 44));
        spinBox = new QSpinBox(widget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(9, 9, 57, 26));
        spinBox->setMinimum(1);
        spinBox->setMaximum(35);
        horizontalSlider = new QSlider(widget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(72, 9, 170, 26));
        horizontalSlider->setMaximum(35);
        horizontalSlider->setOrientation(Qt::Horizontal);

        retranslateUi(pfs);

        QMetaObject::connectSlotsByName(pfs);
    } // setupUi

    void retranslateUi(QWidget *pfs)
    {
        pfs->setWindowTitle(QCoreApplication::translate("pfs", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pfs: public Ui_pfs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PFS_H
