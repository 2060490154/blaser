/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "gamma_1.h"
#include "light.h"
#include "pfs.h"
#include "rgb.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *save_line;
    QPushButton *bro_btn;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *save_name;
    QCheckBox *name_check;
    QWidget *widget;
    QPushButton *cap_btn;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *ruler_btn;
    QLabel *pixe_label;
    QLabel *height_label;
    QLabel *longth_label;
    QCheckBox *ruler_box;
    QCheckBox *cap_check;
    QPushButton *deal_btn;
    QGroupBox *groupBox;
    RGB *RGB_w;
    QGroupBox *groupBox_2;
    light *light_w;
    QGroupBox *groupBox_3;
    pfs *fps_w;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *inti_btn;
    QPushButton *start_btn;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *play_btn;
    QPushButton *stop_btn;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_3;
    QTextEdit *socket_text;
    QTextEdit *textEdit;
    QPushButton *saveset_btn;
    QPushButton *recover_btn;
    QGroupBox *groupBox_5;
    QPushButton *connect_btn;
    QWidget *widget_6;
    QGridLayout *gridLayout;
    QLabel *status_label;
    QLabel *table_label;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_4;
    QLabel *SQL_label;
    QGroupBox *groupBox_6;
    gamma_1 *gamma_w;
    QGroupBox *groupBox_7;
    QLabel *label_3;
    QLabel *label_;
    QLabel *label_8;
    QLineEdit *pixe_real;
    QLineEdit *defect_piont;
    QLineEdit *defect_all;
    QLineEdit *exposure_edit;
    QLabel *label_7;
    QWidget *image;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1500, 818);
        MainWindow->setMinimumSize(QSize(623, 730));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(10, 510, 1481, 191));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_2 = new QWidget(frame_3);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        save_line = new QLineEdit(widget_2);
        save_line->setObjectName(QString::fromUtf8("save_line"));

        horizontalLayout->addWidget(save_line);

        bro_btn = new QPushButton(widget_2);
        bro_btn->setObjectName(QString::fromUtf8("bro_btn"));

        horizontalLayout->addWidget(bro_btn);


        verticalLayout->addWidget(widget_2);

        widget_3 = new QWidget(frame_3);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_4 = new QHBoxLayout(widget_3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        save_name = new QLineEdit(widget_3);
        save_name->setObjectName(QString::fromUtf8("save_name"));

        horizontalLayout_4->addWidget(save_name);

        name_check = new QCheckBox(widget_3);
        name_check->setObjectName(QString::fromUtf8("name_check"));

        horizontalLayout_4->addWidget(name_check);


        verticalLayout->addWidget(widget_3);

        widget = new QWidget(frame_3);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMaximumSize(QSize(730, 16777215));
        cap_btn = new QPushButton(widget);
        cap_btn->setObjectName(QString::fromUtf8("cap_btn"));
        cap_btn->setGeometry(QRect(9, 18, 85, 33));
        widget_7 = new QWidget(widget);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        widget_7->setGeometry(QRect(103, 9, 341, 51));
        horizontalLayout_5 = new QHBoxLayout(widget_7);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        ruler_btn = new QPushButton(widget_7);
        ruler_btn->setObjectName(QString::fromUtf8("ruler_btn"));

        horizontalLayout_5->addWidget(ruler_btn);

        pixe_label = new QLabel(widget_7);
        pixe_label->setObjectName(QString::fromUtf8("pixe_label"));

        horizontalLayout_5->addWidget(pixe_label);

        height_label = new QLabel(widget_7);
        height_label->setObjectName(QString::fromUtf8("height_label"));

        horizontalLayout_5->addWidget(height_label);

        longth_label = new QLabel(widget_7);
        longth_label->setObjectName(QString::fromUtf8("longth_label"));

        horizontalLayout_5->addWidget(longth_label);

        ruler_box = new QCheckBox(widget);
        ruler_box->setObjectName(QString::fromUtf8("ruler_box"));
        ruler_box->setGeometry(QRect(450, 20, 75, 28));
        cap_check = new QCheckBox(widget);
        cap_check->setObjectName(QString::fromUtf8("cap_check"));
        cap_check->setGeometry(QRect(534, 20, 90, 28));

        verticalLayout->addWidget(widget);

        deal_btn = new QPushButton(centralwidget);
        deal_btn->setObjectName(QString::fromUtf8("deal_btn"));
        deal_btn->setGeometry(QRect(650, 430, 191, 41));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(320, 150, 281, 181));
        RGB_w = new RGB(groupBox);
        RGB_w->setObjectName(QString::fromUtf8("RGB_w"));
        RGB_w->setGeometry(QRect(0, 20, 281, 161));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 220, 291, 80));
        light_w = new light(groupBox_2);
        light_w->setObjectName(QString::fromUtf8("light_w"));
        light_w->setGeometry(QRect(10, 20, 261, 51));
        light_w->setCursor(QCursor(Qt::PointingHandCursor));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 310, 291, 81));
        fps_w = new pfs(groupBox_3);
        fps_w->setObjectName(QString::fromUtf8("fps_w"));
        fps_w->setGeometry(QRect(10, 20, 261, 51));
        fps_w->setCursor(QCursor(Qt::PointingHandCursor));
        widget_4 = new QWidget(centralwidget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setGeometry(QRect(60, 40, 214, 118));
        verticalLayout_2 = new QVBoxLayout(widget_4);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        frame = new QFrame(widget_4);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        inti_btn = new QPushButton(frame);
        inti_btn->setObjectName(QString::fromUtf8("inti_btn"));

        horizontalLayout_3->addWidget(inti_btn);

        start_btn = new QPushButton(frame);
        start_btn->setObjectName(QString::fromUtf8("start_btn"));

        horizontalLayout_3->addWidget(start_btn);


        verticalLayout_2->addWidget(frame);

        frame_2 = new QFrame(widget_4);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        play_btn = new QPushButton(frame_2);
        play_btn->setObjectName(QString::fromUtf8("play_btn"));

        horizontalLayout_2->addWidget(play_btn);

        stop_btn = new QPushButton(frame_2);
        stop_btn->setObjectName(QString::fromUtf8("stop_btn"));

        horizontalLayout_2->addWidget(stop_btn);


        verticalLayout_2->addWidget(frame_2);

        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(320, 10, 521, 141));
        verticalLayout_3 = new QVBoxLayout(groupBox_4);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        socket_text = new QTextEdit(groupBox_4);
        socket_text->setObjectName(QString::fromUtf8("socket_text"));

        verticalLayout_3->addWidget(socket_text);

        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 710, 1481, 71));
        saveset_btn = new QPushButton(centralwidget);
        saveset_btn->setObjectName(QString::fromUtf8("saveset_btn"));
        saveset_btn->setGeometry(QRect(60, 160, 99, 27));
        recover_btn = new QPushButton(centralwidget);
        recover_btn->setObjectName(QString::fromUtf8("recover_btn"));
        recover_btn->setGeometry(QRect(170, 160, 99, 27));
        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(650, 160, 191, 221));
        connect_btn = new QPushButton(groupBox_5);
        connect_btn->setObjectName(QString::fromUtf8("connect_btn"));
        connect_btn->setGeometry(QRect(0, 30, 81, 27));
        widget_6 = new QWidget(groupBox_5);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setGeometry(QRect(0, 80, 181, 151));
        gridLayout = new QGridLayout(widget_6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        status_label = new QLabel(widget_6);
        status_label->setObjectName(QString::fromUtf8("status_label"));

        gridLayout->addWidget(status_label, 0, 1, 1, 2);

        table_label = new QLabel(widget_6);
        table_label->setObjectName(QString::fromUtf8("table_label"));

        gridLayout->addWidget(table_label, 2, 1, 1, 2);

        label_5 = new QLabel(widget_6);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        label_6 = new QLabel(widget_6);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        label_4 = new QLabel(widget_6);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        SQL_label = new QLabel(widget_6);
        SQL_label->setObjectName(QString::fromUtf8("SQL_label"));

        gridLayout->addWidget(SQL_label, 1, 1, 1, 2);

        groupBox_6 = new QGroupBox(centralwidget);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(10, 390, 291, 80));
        gamma_w = new gamma_1(groupBox_6);
        gamma_w->setObjectName(QString::fromUtf8("gamma_w"));
        gamma_w->setGeometry(QRect(10, 20, 261, 51));
        groupBox_7 = new QGroupBox(centralwidget);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(310, 380, 321, 92));
        label_3 = new QLabel(groupBox_7);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 25, 61, 23));
        label_ = new QLabel(groupBox_7);
        label_->setObjectName(QString::fromUtf8("label_"));
        label_->setGeometry(QRect(115, 25, 45, 23));
        label_8 = new QLabel(groupBox_7);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(195, 25, 45, 23));
        pixe_real = new QLineEdit(groupBox_7);
        pixe_real->setObjectName(QString::fromUtf8("pixe_real"));
        pixe_real->setGeometry(QRect(30, 50, 61, 27));
        defect_piont = new QLineEdit(groupBox_7);
        defect_piont->setObjectName(QString::fromUtf8("defect_piont"));
        defect_piont->setGeometry(QRect(110, 50, 61, 27));
        defect_all = new QLineEdit(groupBox_7);
        defect_all->setObjectName(QString::fromUtf8("defect_all"));
        defect_all->setGeometry(QRect(190, 50, 61, 27));
        exposure_edit = new QLineEdit(centralwidget);
        exposure_edit->setObjectName(QString::fromUtf8("exposure_edit"));
        exposure_edit->setGeometry(QRect(440, 340, 61, 27));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(320, 340, 111, 20));
        image = new QWidget(centralwidget);
        image->setObjectName(QString::fromUtf8("image"));
        image->setGeometry(QRect(860, 10, 631, 491));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1500, 26));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\345\233\276\347\211\207\344\277\235\345\255\230\350\267\257\345\276\204\357\274\232", nullptr));
        bro_btn->setText(QCoreApplication::translate("MainWindow", "Browse", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\345\233\276\347\211\207\345\220\215\347\247\260\357\274\232", nullptr));
        name_check->setText(QCoreApplication::translate("MainWindow", "using this", nullptr));
        cap_btn->setText(QCoreApplication::translate("MainWindow", "\346\210\252\345\233\276", nullptr));
        ruler_btn->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\346\240\207\345\260\272\345\217\202\346\225\260", nullptr));
        pixe_label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        height_label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        longth_label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        ruler_box->setText(QCoreApplication::translate("MainWindow", "\345\212\240\346\240\207\345\260\272", nullptr));
        cap_check->setText(QCoreApplication::translate("MainWindow", "\351\242\204\350\247\210\346\210\252\345\233\276", nullptr));
        deal_btn->setText(QCoreApplication::translate("MainWindow", "\345\233\276\345\203\217\345\244\204\347\220\206\347\225\214\351\235\242", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "RGB", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\346\233\235\345\205\211\346\227\266\351\227\264/ms", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\345\270\247\347\216\207/FPS", nullptr));
        inti_btn->setText(QCoreApplication::translate("MainWindow", "\345\210\235\345\247\213\345\214\226\350\256\276\345\244\207", nullptr));
        start_btn->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\220\257\347\272\277\347\250\213", nullptr));
        play_btn->setText(QCoreApplication::translate("MainWindow", "play", nullptr));
        stop_btn->setText(QCoreApplication::translate("MainWindow", "stop", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "\344\270\212\344\275\215\346\234\272\351\200\232\344\277\241", nullptr));
        saveset_btn->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\345\275\223\345\211\215\350\256\276\347\275\256", nullptr));
        recover_btn->setText(QCoreApplication::translate("MainWindow", "\346\201\242\345\244\215\345\207\272\345\216\202\350\256\276\347\275\256", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\345\272\223", nullptr));
        connect_btn->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245\346\225\260\346\215\256\345\272\223", nullptr));
        status_label->setText(QString());
        table_label->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "\350\241\250\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\347\212\266\346\200\201\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\345\272\223\357\274\232", nullptr));
        SQL_label->setText(QString());
        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "\344\274\275\351\251\254", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("MainWindow", "\346\215\237\344\274\244\347\202\271\345\260\272\345\272\246\350\256\276\347\275\256\357\274\210\345\215\225\344\275\215\357\274\232um\357\274\211", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\345\203\217\347\264\240\345\256\275\345\272\246", nullptr));
        label_->setText(QCoreApplication::translate("MainWindow", "\347\202\271\346\215\237\344\274\244", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\346\200\273\346\215\237\344\274\244", nullptr));
        pixe_real->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        defect_piont->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
        defect_all->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
        exposure_edit->setText(QCoreApplication::translate("MainWindow", "12", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\350\260\203\346\225\264\346\227\266\351\225\277\357\274\210\347\247\222\357\274\211\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
