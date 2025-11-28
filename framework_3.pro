#-------------------------------------------------
#
# Project created by QtCreator 2020-06-22T03:28:42
# NVIDIA
#-------------------------------------------------

QT       += core gui sql
QT += network

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 损伤诊断
TEMPLATE = app


SOURCES +=     main.cpp \
    light.cpp \
    mainwindow.cpp \
    pfs.cpp \
    gpio.cpp \
    camera.cpp \
    rgb.cpp \
    deal.cpp \
    imagewidget.cpp \
    drawview.cpp \
    rulebar.cpp \
    dialog.cpp \
    sqlsend.cpp \
    sendimg.cpp \
    rulersettings.cpp \
    sendimg_s.cpp \
    gamma_1.cpp \
    guicamera.cpp \


HEADERS  += light.h \
    BaslerCamera.h \
    BaslerCameraArray.h \
    BaslerCameraCameraEventHandler.h \
    BaslerCameraCameraParams.h \
    BaslerCameraChunkDataParams.h \
    BaslerCameraConfigurationEventHandler.h \
    BaslerCameraEventParams.h \
    BaslerCameraGrabResultData.h \
    BaslerCameraGrabResultPtr.h \
    BaslerCameraImageEventHandler.h \
    BaslerCameraStreamParams.h \
    BaslerCameraTLParams.h \
    mainwindow.h \
    pfs.h \
    jetsonGPIO.h \
    gpio.h \
    camera.h \
    rgb.h \
    deal.h \
    imagewidget.h \
    drawview.h \
    rulebar.h \
    dialog.h \
    sqlsend.h \
    sendimg.h \
    rulersettings.h \
    sendimg_s.h \
    gamma_1.h \
    guicamera.h \


FORMS    += \
    light.ui \
    mainwindow.ui \
    pfs.ui \
    rgb.ui \
    deal.ui \
    dialog.ui \
    rulersettings.ui \
    gamma_1.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

## Add Pylon`
#win32 {
#    INCLUDEPATH += "$$(PYLON_ROOT)/include"
#    contains(QMAKE_TARGET.arch, x86_64) {
#        LIBS += -L"$$(PYLON_ROOT)/lib/x64"
#    } else {
#        LIBS += -L"$$(PYLON_ROOT)/lib/win32"
#    }
#}
#linux {
#    INCLUDEPATH += "$$(PYLON_ROOT)/include"
#    LIBS += -L"$$(PYLON_ROOT)/lib" -libpylonbase -libpylonutility -libGenApi_gcc_v3_1_Basler_pylon -libGCBase_gcc_v3_1_Basler_pylon
#}
#macx {
#    QMAKE_RPATHDIR += "/Library/Frameworks/"
#    CONFIG-=app_bundle
#    INCLUDEPATH += "/Library/Frameworks/pylon.framework/Headers/GenICam"
#    QMAKE_CXXFLAGS += -F"/Library/Frameworks"
#    LIBS += -F"/Library/Frameworks" -framework pylon
#}

INCLUDEPATH +=  /home/night/Desktop/QtPrj/PixeLINKSdk/include\
                /usr/include/opencv4/opencv2\
                /usr/include/opencv4\
                /opt/pylon/include\


LIBS += /home/night/Desktop/QtPrj/PixeLINKSdk/lib/libPxLApi.so\
        /usr/lib/aarch64-linux-gnu/libopencv_core.so\
        /usr/lib/aarch64-linux-gnu/libopencv_highgui.so\
        /usr/lib/aarch64-linux-gnu/libopencv_imgcodecs.so\
        /usr/lib/aarch64-linux-gnu/libopencv_features2d.so\
        /usr/lib/aarch64-linux-gnu/libopencv_flann.so\
        /usr/lib/aarch64-linux-gnu/libopencv_imgproc.so\
/opt/pylon/lib/libpylonbase.so\
/opt/pylon/lib/libpylonutility.so\
/opt/pylon/lib/libGenApi_gcc_v3_1_Basler_pylon.so\
/opt/pylon/lib/libGCBase_gcc_v3_1_Basler_pylon.so\




