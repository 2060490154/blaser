/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_7;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *base_line;
    QLineEdit *user_line;
    QLineEdit *pwdd_line;
    QLineEdit *IP_line;
    QLineEdit *port_line;
    QLineEdit *table_name;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *con_btn;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancel_btn;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(432, 321);
        verticalLayout = new QVBoxLayout(Dialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        widget_2 = new QWidget(groupBox);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(10, 20, 381, 221));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget = new QWidget(widget_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_2->addWidget(label_5);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_2->addWidget(label_7);


        horizontalLayout->addWidget(widget);

        widget_6 = new QWidget(widget_2);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        verticalLayout_3 = new QVBoxLayout(widget_6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        base_line = new QLineEdit(widget_6);
        base_line->setObjectName(QString::fromUtf8("base_line"));

        verticalLayout_3->addWidget(base_line);

        user_line = new QLineEdit(widget_6);
        user_line->setObjectName(QString::fromUtf8("user_line"));

        verticalLayout_3->addWidget(user_line);

        pwdd_line = new QLineEdit(widget_6);
        pwdd_line->setObjectName(QString::fromUtf8("pwdd_line"));

        verticalLayout_3->addWidget(pwdd_line);

        IP_line = new QLineEdit(widget_6);
        IP_line->setObjectName(QString::fromUtf8("IP_line"));

        verticalLayout_3->addWidget(IP_line);

        port_line = new QLineEdit(widget_6);
        port_line->setObjectName(QString::fromUtf8("port_line"));

        verticalLayout_3->addWidget(port_line);

        table_name = new QLineEdit(widget_6);
        table_name->setObjectName(QString::fromUtf8("table_name"));

        verticalLayout_3->addWidget(table_name);


        horizontalLayout->addWidget(widget_6);

        widget_3 = new QWidget(groupBox);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(10, 250, 381, 51));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        con_btn = new QPushButton(widget_3);
        con_btn->setObjectName(QString::fromUtf8("con_btn"));

        horizontalLayout_2->addWidget(con_btn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        cancel_btn = new QPushButton(widget_3);
        cancel_btn->setObjectName(QString::fromUtf8("cancel_btn"));

        horizontalLayout_2->addWidget(cancel_btn);


        verticalLayout->addWidget(groupBox);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Dialog", "\346\225\260\346\215\256\345\272\223\350\277\236\346\216\245", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "\346\225\260\346\215\256\346\272\220\345\220\215\347\247\260\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog", "\345\257\206\347\240\201\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("Dialog", "\344\270\273\346\234\272IP\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("Dialog", "\347\253\257\345\217\243\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("Dialog", "\350\241\250\345\220\215\357\274\232", nullptr));
        base_line->setText(QCoreApplication::translate("Dialog", "SmallBorePlatformDB", nullptr));
        user_line->setText(QCoreApplication::translate("Dialog", "sa", nullptr));
        pwdd_line->setText(QCoreApplication::translate("Dialog", "123456", nullptr));
        IP_line->setText(QCoreApplication::translate("Dialog", "192.168.1.50", nullptr));
        port_line->setText(QCoreApplication::translate("Dialog", "1433", nullptr));
        table_name->setText(QCoreApplication::translate("Dialog", "T_DEFECT_SYSTEM_DATA", nullptr));
        con_btn->setText(QCoreApplication::translate("Dialog", "\350\277\236\346\216\245", nullptr));
        cancel_btn->setText(QCoreApplication::translate("Dialog", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
