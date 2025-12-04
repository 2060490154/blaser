/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[86];
    char stringdata0[1414];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 8), // "giveinfo"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 1), // "p"
QT_MOC_LITERAL(4, 23, 1), // "n"
QT_MOC_LITERAL(5, 25, 14), // "begain_to_deal"
QT_MOC_LITERAL(6, 40, 11), // "deal_finish"
QT_MOC_LITERAL(7, 52, 15), // "OnNewGrabResult"
QT_MOC_LITERAL(8, 68, 8), // "userHint"
QT_MOC_LITERAL(9, 77, 14), // "OnStateChanged"
QT_MOC_LITERAL(10, 92, 10), // "isGrabbing"
QT_MOC_LITERAL(11, 103, 15), // "OnDeviceRemoved"
QT_MOC_LITERAL(12, 119, 13), // "OnNodeUpdated"
QT_MOC_LITERAL(13, 133, 14), // "GenApi::INode*"
QT_MOC_LITERAL(14, 148, 5), // "pNode"
QT_MOC_LITERAL(15, 154, 21), // "on_scanButton_clicked"
QT_MOC_LITERAL(16, 176, 33), // "on_cameraList_currentIndexCha..."
QT_MOC_LITERAL(17, 210, 5), // "index"
QT_MOC_LITERAL(18, 216, 25), // "on_openSelected_1_clicked"
QT_MOC_LITERAL(19, 242, 25), // "on_openSelected_2_clicked"
QT_MOC_LITERAL(20, 268, 21), // "on_openBySN_1_clicked"
QT_MOC_LITERAL(21, 290, 21), // "on_openBySN_2_clicked"
QT_MOC_LITERAL(22, 312, 25), // "on_openByUserID_1_clicked"
QT_MOC_LITERAL(23, 338, 25), // "on_openByUserID_2_clicked"
QT_MOC_LITERAL(24, 364, 18), // "on_close_1_clicked"
QT_MOC_LITERAL(25, 383, 18), // "on_close_2_clicked"
QT_MOC_LITERAL(26, 402, 23), // "on_singleShot_1_clicked"
QT_MOC_LITERAL(27, 426, 23), // "on_singleShot_2_clicked"
QT_MOC_LITERAL(28, 450, 23), // "on_continuous_1_clicked"
QT_MOC_LITERAL(29, 474, 23), // "on_continuous_2_clicked"
QT_MOC_LITERAL(30, 498, 17), // "on_stop_1_clicked"
QT_MOC_LITERAL(31, 516, 17), // "on_stop_2_clicked"
QT_MOC_LITERAL(32, 534, 26), // "on_exposure_1_valueChanged"
QT_MOC_LITERAL(33, 561, 5), // "value"
QT_MOC_LITERAL(34, 567, 26), // "on_exposure_2_valueChanged"
QT_MOC_LITERAL(35, 594, 22), // "on_gain_1_valueChanged"
QT_MOC_LITERAL(36, 617, 22), // "on_gain_2_valueChanged"
QT_MOC_LITERAL(37, 640, 36), // "on_pixelFormat_1_currentIndex..."
QT_MOC_LITERAL(38, 677, 36), // "on_pixelFormat_2_currentIndex..."
QT_MOC_LITERAL(39, 714, 35), // "on_triggerMode_1_currentTextC..."
QT_MOC_LITERAL(40, 750, 4), // "arg1"
QT_MOC_LITERAL(41, 755, 35), // "on_triggerMode_2_currentTextC..."
QT_MOC_LITERAL(42, 791, 37), // "on_triggerSource_1_currentTex..."
QT_MOC_LITERAL(43, 829, 37), // "on_triggerSource_2_currentTex..."
QT_MOC_LITERAL(44, 867, 28), // "on_softwareTrigger_1_clicked"
QT_MOC_LITERAL(45, 896, 28), // "on_softwareTrigger_2_clicked"
QT_MOC_LITERAL(46, 925, 24), // "on_invertPixel_1_toggled"
QT_MOC_LITERAL(47, 950, 7), // "checked"
QT_MOC_LITERAL(48, 958, 24), // "on_invertPixel_2_toggled"
QT_MOC_LITERAL(49, 983, 13), // "OnUpdateTimer"
QT_MOC_LITERAL(50, 997, 22), // "on_editSN_1_textEdited"
QT_MOC_LITERAL(51, 1020, 22), // "on_editSN_2_textEdited"
QT_MOC_LITERAL(52, 1043, 26), // "on_editUserID_1_textEdited"
QT_MOC_LITERAL(53, 1070, 26), // "on_editUserID_2_textEdited"
QT_MOC_LITERAL(54, 1097, 22), // "on_connect_btn_clicked"
QT_MOC_LITERAL(55, 1120, 12), // "receivetable"
QT_MOC_LITERAL(56, 1133, 3), // "str"
QT_MOC_LITERAL(57, 1137, 10), // "receiveSQL"
QT_MOC_LITERAL(58, 1148, 10), // "do_connect"
QT_MOC_LITERAL(59, 1159, 26), // "on_upload_test_btn_clicked"
QT_MOC_LITERAL(60, 1186, 14), // "receivemessage"
QT_MOC_LITERAL(61, 1201, 10), // "receivesrc"
QT_MOC_LITERAL(62, 1212, 1), // "s"
QT_MOC_LITERAL(63, 1214, 13), // "receivedamage"
QT_MOC_LITERAL(64, 1228, 1), // "d"
QT_MOC_LITERAL(65, 1230, 10), // "receivecap"
QT_MOC_LITERAL(66, 1241, 1), // "c"
QT_MOC_LITERAL(67, 1243, 15), // "creatDealThread"
QT_MOC_LITERAL(68, 1259, 8), // "send_get"
QT_MOC_LITERAL(69, 1268, 3), // "get"
QT_MOC_LITERAL(70, 1272, 10), // "send_ready"
QT_MOC_LITERAL(71, 1283, 5), // "ready"
QT_MOC_LITERAL(72, 1289, 11), // "send_deal_1"
QT_MOC_LITERAL(73, 1301, 4), // "deal"
QT_MOC_LITERAL(74, 1306, 7), // "success"
QT_MOC_LITERAL(75, 1314, 8), // "send_cap"
QT_MOC_LITERAL(76, 1323, 3), // "cap"
QT_MOC_LITERAL(77, 1327, 11), // "send_finish"
QT_MOC_LITERAL(78, 1339, 1), // "t"
QT_MOC_LITERAL(79, 1341, 8), // "creatudp"
QT_MOC_LITERAL(80, 1350, 23), // "receiveruler_parameters"
QT_MOC_LITERAL(81, 1374, 1), // "h"
QT_MOC_LITERAL(82, 1376, 10), // "Delay_MSec"
QT_MOC_LITERAL(83, 1387, 4), // "msec"
QT_MOC_LITERAL(84, 1392, 10), // "cameraplay"
QT_MOC_LITERAL(85, 1403, 10) // "camerastop"

    },
    "MainWindow\0giveinfo\0\0p\0n\0begain_to_deal\0"
    "deal_finish\0OnNewGrabResult\0userHint\0"
    "OnStateChanged\0isGrabbing\0OnDeviceRemoved\0"
    "OnNodeUpdated\0GenApi::INode*\0pNode\0"
    "on_scanButton_clicked\0"
    "on_cameraList_currentIndexChanged\0"
    "index\0on_openSelected_1_clicked\0"
    "on_openSelected_2_clicked\0"
    "on_openBySN_1_clicked\0on_openBySN_2_clicked\0"
    "on_openByUserID_1_clicked\0"
    "on_openByUserID_2_clicked\0on_close_1_clicked\0"
    "on_close_2_clicked\0on_singleShot_1_clicked\0"
    "on_singleShot_2_clicked\0on_continuous_1_clicked\0"
    "on_continuous_2_clicked\0on_stop_1_clicked\0"
    "on_stop_2_clicked\0on_exposure_1_valueChanged\0"
    "value\0on_exposure_2_valueChanged\0"
    "on_gain_1_valueChanged\0on_gain_2_valueChanged\0"
    "on_pixelFormat_1_currentIndexChanged\0"
    "on_pixelFormat_2_currentIndexChanged\0"
    "on_triggerMode_1_currentTextChanged\0"
    "arg1\0on_triggerMode_2_currentTextChanged\0"
    "on_triggerSource_1_currentTextChanged\0"
    "on_triggerSource_2_currentTextChanged\0"
    "on_softwareTrigger_1_clicked\0"
    "on_softwareTrigger_2_clicked\0"
    "on_invertPixel_1_toggled\0checked\0"
    "on_invertPixel_2_toggled\0OnUpdateTimer\0"
    "on_editSN_1_textEdited\0on_editSN_2_textEdited\0"
    "on_editUserID_1_textEdited\0"
    "on_editUserID_2_textEdited\0"
    "on_connect_btn_clicked\0receivetable\0"
    "str\0receiveSQL\0do_connect\0"
    "on_upload_test_btn_clicked\0receivemessage\0"
    "receivesrc\0s\0receivedamage\0d\0receivecap\0"
    "c\0creatDealThread\0send_get\0get\0"
    "send_ready\0ready\0send_deal_1\0deal\0"
    "success\0send_cap\0cap\0send_finish\0t\0"
    "creatudp\0receiveruler_parameters\0h\0"
    "Delay_MSec\0msec\0cameraplay\0camerastop"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      62,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  324,    2, 0x06 /* Public */,
       5,    0,  329,    2, 0x06 /* Public */,
       6,    0,  330,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,  331,    2, 0x08 /* Private */,
       9,    2,  334,    2, 0x08 /* Private */,
      11,    1,  339,    2, 0x08 /* Private */,
      12,    2,  342,    2, 0x08 /* Private */,
      15,    0,  347,    2, 0x08 /* Private */,
      16,    1,  348,    2, 0x08 /* Private */,
      18,    0,  351,    2, 0x08 /* Private */,
      19,    0,  352,    2, 0x08 /* Private */,
      20,    0,  353,    2, 0x08 /* Private */,
      21,    0,  354,    2, 0x08 /* Private */,
      22,    0,  355,    2, 0x08 /* Private */,
      23,    0,  356,    2, 0x08 /* Private */,
      24,    0,  357,    2, 0x08 /* Private */,
      25,    0,  358,    2, 0x08 /* Private */,
      26,    0,  359,    2, 0x08 /* Private */,
      27,    0,  360,    2, 0x08 /* Private */,
      28,    0,  361,    2, 0x08 /* Private */,
      29,    0,  362,    2, 0x08 /* Private */,
      30,    0,  363,    2, 0x08 /* Private */,
      31,    0,  364,    2, 0x08 /* Private */,
      32,    1,  365,    2, 0x08 /* Private */,
      34,    1,  368,    2, 0x08 /* Private */,
      35,    1,  371,    2, 0x08 /* Private */,
      36,    1,  374,    2, 0x08 /* Private */,
      37,    1,  377,    2, 0x08 /* Private */,
      38,    1,  380,    2, 0x08 /* Private */,
      39,    1,  383,    2, 0x08 /* Private */,
      41,    1,  386,    2, 0x08 /* Private */,
      42,    1,  389,    2, 0x08 /* Private */,
      43,    1,  392,    2, 0x08 /* Private */,
      44,    0,  395,    2, 0x08 /* Private */,
      45,    0,  396,    2, 0x08 /* Private */,
      46,    1,  397,    2, 0x08 /* Private */,
      48,    1,  400,    2, 0x08 /* Private */,
      49,    0,  403,    2, 0x08 /* Private */,
      50,    1,  404,    2, 0x08 /* Private */,
      51,    1,  407,    2, 0x08 /* Private */,
      52,    1,  410,    2, 0x08 /* Private */,
      53,    1,  413,    2, 0x08 /* Private */,
      54,    0,  416,    2, 0x08 /* Private */,
      55,    1,  417,    2, 0x08 /* Private */,
      57,    1,  420,    2, 0x08 /* Private */,
      58,    0,  423,    2, 0x08 /* Private */,
      59,    0,  424,    2, 0x08 /* Private */,
      60,    0,  425,    2, 0x08 /* Private */,
      61,    1,  426,    2, 0x08 /* Private */,
      63,    1,  429,    2, 0x08 /* Private */,
      65,    1,  432,    2, 0x08 /* Private */,
      67,    0,  435,    2, 0x08 /* Private */,
      68,    1,  436,    2, 0x08 /* Private */,
      70,    1,  439,    2, 0x08 /* Private */,
      72,    2,  442,    2, 0x08 /* Private */,
      75,    1,  447,    2, 0x08 /* Private */,
      77,    1,  450,    2, 0x08 /* Private */,
      79,    0,  453,    2, 0x08 /* Private */,
      80,    3,  454,    2, 0x08 /* Private */,
      82,    1,  461,    2, 0x08 /* Private */,
      84,    0,  464,    2, 0x08 /* Private */,
      85,    0,  465,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Char, QMetaType::Char,    3,    4,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    8,   10,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 13,    8,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   33,
    QMetaType::Void, QMetaType::Int,   33,
    QMetaType::Void, QMetaType::Int,   33,
    QMetaType::Void, QMetaType::Int,   33,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::QString,   40,
    QMetaType::Void, QMetaType::QString,   40,
    QMetaType::Void, QMetaType::QString,   40,
    QMetaType::Void, QMetaType::QString,   40,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   47,
    QMetaType::Void, QMetaType::Bool,   47,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   40,
    QMetaType::Void, QMetaType::QString,   40,
    QMetaType::Void, QMetaType::QString,   40,
    QMetaType::Void, QMetaType::QString,   40,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   56,
    QMetaType::Void, QMetaType::QString,   56,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   62,
    QMetaType::Void, QMetaType::Float,   64,
    QMetaType::Void, QMetaType::Bool,   66,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   69,
    QMetaType::Void, QMetaType::Bool,   71,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,   73,   74,
    QMetaType::Void, QMetaType::Bool,   76,
    QMetaType::Void, QMetaType::Bool,   78,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,   81,   78,
    QMetaType::Void, QMetaType::UInt,   83,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->giveinfo((*reinterpret_cast< char(*)>(_a[1])),(*reinterpret_cast< char(*)>(_a[2]))); break;
        case 1: _t->begain_to_deal(); break;
        case 2: _t->deal_finish(); break;
        case 3: _t->OnNewGrabResult((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->OnStateChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 5: _t->OnDeviceRemoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->OnNodeUpdated((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< GenApi::INode*(*)>(_a[2]))); break;
        case 7: _t->on_scanButton_clicked(); break;
        case 8: _t->on_cameraList_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_openSelected_1_clicked(); break;
        case 10: _t->on_openSelected_2_clicked(); break;
        case 11: _t->on_openBySN_1_clicked(); break;
        case 12: _t->on_openBySN_2_clicked(); break;
        case 13: _t->on_openByUserID_1_clicked(); break;
        case 14: _t->on_openByUserID_2_clicked(); break;
        case 15: _t->on_close_1_clicked(); break;
        case 16: _t->on_close_2_clicked(); break;
        case 17: _t->on_singleShot_1_clicked(); break;
        case 18: _t->on_singleShot_2_clicked(); break;
        case 19: _t->on_continuous_1_clicked(); break;
        case 20: _t->on_continuous_2_clicked(); break;
        case 21: _t->on_stop_1_clicked(); break;
        case 22: _t->on_stop_2_clicked(); break;
        case 23: _t->on_exposure_1_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->on_exposure_2_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->on_gain_1_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->on_gain_2_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->on_pixelFormat_1_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->on_pixelFormat_2_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 29: _t->on_triggerMode_1_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 30: _t->on_triggerMode_2_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 31: _t->on_triggerSource_1_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 32: _t->on_triggerSource_2_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 33: _t->on_softwareTrigger_1_clicked(); break;
        case 34: _t->on_softwareTrigger_2_clicked(); break;
        case 35: _t->on_invertPixel_1_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 36: _t->on_invertPixel_2_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 37: _t->OnUpdateTimer(); break;
        case 38: _t->on_editSN_1_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 39: _t->on_editSN_2_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 40: _t->on_editUserID_1_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 41: _t->on_editUserID_2_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 42: _t->on_connect_btn_clicked(); break;
        case 43: _t->receivetable((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 44: _t->receiveSQL((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 45: _t->do_connect(); break;
        case 46: _t->on_upload_test_btn_clicked(); break;
        case 47: _t->receivemessage(); break;
        case 48: _t->receivesrc((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 49: _t->receivedamage((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 50: _t->receivecap((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 51: _t->creatDealThread(); break;
        case 52: _t->send_get((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 53: _t->send_ready((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 54: _t->send_deal_1((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 55: _t->send_cap((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 56: _t->send_finish((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 57: _t->creatudp(); break;
        case 58: _t->receiveruler_parameters((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 59: _t->Delay_MSec((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 60: _t->cameraplay(); break;
        case 61: _t->camerastop(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(char , char );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::giveinfo)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::begain_to_deal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::deal_finish)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 62)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 62;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 62)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 62;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::giveinfo(char _t1, char _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::begain_to_deal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainWindow::deal_finish()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
