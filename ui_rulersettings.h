/********************************************************************************
** Form generated from reading UI file 'rulersettings.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RULERSETTINGS_H
#define UI_RULERSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rulersettings
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *pixe_line;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *height_line;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *real_line;
    QPushButton *btn1;
    QPushButton *btn2;

    void setupUi(QWidget *rulersettings)
    {
        if (rulersettings->objectName().isEmpty())
            rulersettings->setObjectName(QString::fromUtf8("rulersettings"));
        rulersettings->resize(211, 202);
        rulersettings->setMinimumSize(QSize(211, 202));
        rulersettings->setMaximumSize(QSize(211, 202));
        widget = new QWidget(rulersettings);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 211, 165));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(widget_3);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        pixe_line = new QLineEdit(widget_3);
        pixe_line->setObjectName(QString::fromUtf8("pixe_line"));

        horizontalLayout_2->addWidget(pixe_line);


        verticalLayout->addWidget(widget_3);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        height_line = new QLineEdit(widget_2);
        height_line->setObjectName(QString::fromUtf8("height_line"));

        horizontalLayout->addWidget(height_line);


        verticalLayout->addWidget(widget_2);

        widget_4 = new QWidget(widget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(widget_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        real_line = new QLineEdit(widget_4);
        real_line->setObjectName(QString::fromUtf8("real_line"));

        horizontalLayout_3->addWidget(real_line);


        verticalLayout->addWidget(widget_4);

        btn1 = new QPushButton(rulersettings);
        btn1->setObjectName(QString::fromUtf8("btn1"));
        btn1->setGeometry(QRect(0, 170, 99, 27));
        btn2 = new QPushButton(rulersettings);
        btn2->setObjectName(QString::fromUtf8("btn2"));
        btn2->setGeometry(QRect(110, 170, 99, 27));

        retranslateUi(rulersettings);

        QMetaObject::connectSlotsByName(rulersettings);
    } // setupUi

    void retranslateUi(QWidget *rulersettings)
    {
        rulersettings->setWindowTitle(QCoreApplication::translate("rulersettings", "Form", nullptr));
        label->setText(QCoreApplication::translate("rulersettings", "\346\240\207\345\260\272\351\225\277\345\272\246(pixel)\357\274\232", nullptr));
        pixe_line->setText(QCoreApplication::translate("rulersettings", "50", nullptr));
        label_2->setText(QCoreApplication::translate("rulersettings", "\346\240\207\345\260\272\345\256\275\345\272\246(pixel)\357\274\232", nullptr));
        height_line->setText(QCoreApplication::translate("rulersettings", "5", nullptr));
        label_3->setText(QCoreApplication::translate("rulersettings", "\345\256\236\351\231\205\351\225\277\345\272\246(um)\357\274\232", nullptr));
        real_line->setText(QCoreApplication::translate("rulersettings", "100", nullptr));
        btn1->setText(QCoreApplication::translate("rulersettings", "\347\241\256\345\256\232", nullptr));
        btn2->setText(QCoreApplication::translate("rulersettings", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class rulersettings: public Ui_rulersettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RULERSETTINGS_H
