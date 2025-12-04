/********************************************************************************
** Form generated from reading UI file 'deal.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEAL_H
#define UI_DEAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>
#include <drawview.h>

QT_BEGIN_NAMESPACE

class Ui_deal
{
public:
    QAction *actionChoose_file;
    QAction *actionSave_picture;
    QAction *actionSave_as;
    QWidget *centralwidget;
    QSlider *contrastslider;
    QSlider *lightslider;
    QLabel *label_2;
    QLabel *label_3;
    drawview *ImageGraphic;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QGroupBox *area_label;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QPushButton *back_btn;
    QLineEdit *back_edit;
    QPushButton *forward_btn;
    QLineEdit *forward_edit;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *num_label;
    QLabel *d_label;
    QPushButton *ana_btn;
    QTableView *tableView;
    QPushButton *ruler_btn;
    QMenuBar *menubar;
    QMenu *menuFile;

    void setupUi(QMainWindow *deal)
    {
        if (deal->objectName().isEmpty())
            deal->setObjectName(QString::fromUtf8("deal"));
        deal->resize(1150, 720);
        deal->setMinimumSize(QSize(871, 720));
        actionChoose_file = new QAction(deal);
        actionChoose_file->setObjectName(QString::fromUtf8("actionChoose_file"));
        actionSave_picture = new QAction(deal);
        actionSave_picture->setObjectName(QString::fromUtf8("actionSave_picture"));
        actionSave_as = new QAction(deal);
        actionSave_as->setObjectName(QString::fromUtf8("actionSave_as"));
        centralwidget = new QWidget(deal);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        contrastslider = new QSlider(centralwidget);
        contrastslider->setObjectName(QString::fromUtf8("contrastslider"));
        contrastslider->setGeometry(QRect(500, 20, 160, 29));
        contrastslider->setMaximum(100);
        contrastslider->setPageStep(5);
        contrastslider->setValue(33);
        contrastslider->setOrientation(Qt::Horizontal);
        lightslider = new QSlider(centralwidget);
        lightslider->setObjectName(QString::fromUtf8("lightslider"));
        lightslider->setGeometry(QRect(500, 50, 160, 29));
        lightslider->setMaximum(100);
        lightslider->setPageStep(5);
        lightslider->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(430, 30, 67, 17));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(440, 60, 41, 17));
        ImageGraphic = new drawview(centralwidget);
        ImageGraphic->setObjectName(QString::fromUtf8("ImageGraphic"));
        ImageGraphic->setGeometry(QRect(30, 90, 779, 581));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 20, 391, 45));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        area_label = new QGroupBox(centralwidget);
        area_label->setObjectName(QString::fromUtf8("area_label"));
        area_label->setGeometry(QRect(830, 90, 301, 561));
        widget_2 = new QWidget(area_label);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(-10, 40, 311, 90));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        back_btn = new QPushButton(widget_2);
        back_btn->setObjectName(QString::fromUtf8("back_btn"));

        gridLayout->addWidget(back_btn, 0, 0, 1, 1);

        back_edit = new QLineEdit(widget_2);
        back_edit->setObjectName(QString::fromUtf8("back_edit"));

        gridLayout->addWidget(back_edit, 0, 1, 1, 1);

        forward_btn = new QPushButton(widget_2);
        forward_btn->setObjectName(QString::fromUtf8("forward_btn"));

        gridLayout->addWidget(forward_btn, 1, 0, 1, 1);

        forward_edit = new QLineEdit(widget_2);
        forward_edit->setObjectName(QString::fromUtf8("forward_edit"));

        gridLayout->addWidget(forward_edit, 1, 1, 1, 1);

        label_4 = new QLabel(area_label);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 200, 81, 17));
        label_5 = new QLabel(area_label);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 520, 101, 17));
        num_label = new QLabel(area_label);
        num_label->setObjectName(QString::fromUtf8("num_label"));
        num_label->setGeometry(QRect(110, 200, 67, 17));
        d_label = new QLabel(area_label);
        d_label->setObjectName(QString::fromUtf8("d_label"));
        d_label->setGeometry(QRect(120, 520, 67, 17));
        ana_btn = new QPushButton(area_label);
        ana_btn->setObjectName(QString::fromUtf8("ana_btn"));
        ana_btn->setGeometry(QRect(0, 140, 99, 27));
        tableView = new QTableView(area_label);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 231, 281, 281));
        ruler_btn = new QPushButton(centralwidget);
        ruler_btn->setObjectName(QString::fromUtf8("ruler_btn"));
        ruler_btn->setGeometry(QRect(690, 50, 111, 27));
        deal->setCentralWidget(centralwidget);
        menubar = new QMenuBar(deal);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1150, 31));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        deal->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionChoose_file);
        menuFile->addAction(actionSave_picture);

        retranslateUi(deal);

        QMetaObject::connectSlotsByName(deal);
    } // setupUi

    void retranslateUi(QMainWindow *deal)
    {
        deal->setWindowTitle(QCoreApplication::translate("deal", "MainWindow", nullptr));
        actionChoose_file->setText(QCoreApplication::translate("deal", "choose...", nullptr));
        actionSave_picture->setText(QCoreApplication::translate("deal", "save as...", nullptr));
        actionSave_as->setText(QCoreApplication::translate("deal", "save as", nullptr));
        label_2->setText(QCoreApplication::translate("deal", "\345\257\271\346\257\224\345\272\246", nullptr));
        label_3->setText(QCoreApplication::translate("deal", "\344\272\256\345\272\246", nullptr));
        label->setText(QCoreApplication::translate("deal", "\350\276\223\345\205\245\345\233\276\345\203\217\350\267\257\345\276\204", nullptr));
        area_label->setTitle(QCoreApplication::translate("deal", "\347\262\222\345\272\246\345\210\206\346\236\220", nullptr));
        back_btn->setText(QCoreApplication::translate("deal", "\350\203\214\346\231\257\345\233\276\347\211\207", nullptr));
        forward_btn->setText(QCoreApplication::translate("deal", "\345\211\215\346\231\257\345\233\276\347\211\207", nullptr));
        label_4->setText(QCoreApplication::translate("deal", "\346\215\237\344\274\244\347\202\271\344\270\252\346\225\260\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("deal", "\346\215\237\344\274\244\347\255\211\346\225\210\347\233\264\345\276\204\357\274\232", nullptr));
        num_label->setText(QString());
        d_label->setText(QString());
        ana_btn->setText(QCoreApplication::translate("deal", "\345\244\204\347\220\206", nullptr));
        ruler_btn->setText(QCoreApplication::translate("deal", "\350\256\276\347\275\256\346\240\207\345\260\272\345\217\202\346\225\260", nullptr));
        menuFile->setTitle(QCoreApplication::translate("deal", "file", nullptr));
    } // retranslateUi

};

namespace Ui {
    class deal: public Ui_deal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEAL_H
