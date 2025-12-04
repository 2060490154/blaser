QT       += core gui sql network widgets

CONFIG += c++11

# Default PYLON_ROOT if not set in environment
isEmpty(PYLON_ROOT) {
    PYLON_ROOT = /opt/pylon
}

TARGET = blaser_app
TEMPLATE = app

SOURCES +=     main.cpp \
    camera.cpp \
    light.cpp \
    mainwindow.cpp \
    pfs.cpp \
    gpio.cpp \
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
    guicamera.cpp

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
    camera.h \
    mainwindow.h \
    pfs.h \
    jetsonGPIO.h \
    gpio.h \
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
    guicamera.h

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

# Use environment variables to configure SDK locations. Set these in your shell:
# export PYLON_ROOT=/opt/pylon
# export OPENCV_DIR=/usr/include/opencv4

INCLUDEPATH += $$OPENCV_DIR \
               $$PYLON_ROOT/include

# Link against OpenCV (system-installed), and Basler Pylon (installed at PYLON_ROOT)
LIBS += -L/usr/lib/aarch64-linux-gnu -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_features2d -lopencv_flann -lopencv_imgproc \
        -L$$PYLON_ROOT/lib -lpylonbase -lpylonutility

GENAPI_SO = $$system(ls -1 $$PYLON_ROOT/lib/libGenApi_gcc_v3_*.so 2>/dev/null | head -n 1)
GCBASE_SO = $$system(ls -1 $$PYLON_ROOT/lib/libGCBase_gcc_v3_*.so 2>/dev/null | head -n 1)
!isEmpty(GENAPI_SO) {
    LIBS += $$GENAPI_SO
} else {
    LIBS += -lGenApi_gcc_v3_1_Basler_pylon
}
!isEmpty(GCBASE_SO) {
    LIBS += $$GCBASE_SO
} else {
    LIBS += -lGCBase_gcc_v3_1_Basler_pylon
}

# Add rpath so runtime can find the SDK libs
QMAKE_RPATHDIR += $$PYLON_ROOT/lib

# If PYLON_ROOT not set in environment, default to /opt/pylon
isEmpty(PYLON_ROOT) {
    PYLON_ROOT = /opt/pylon
}

!isEmpty(PIXELINK_ROOT) {
    INCLUDEPATH += $$PIXELINK_ROOT/include
}
INCLUDEPATH += /usr/include/opencv4/opencv2 \
               /usr/include/opencv4 \
               /opt/pylon/include


!isEmpty(PIXELINK_ROOT) {
    LIBS += $$PIXELINK_ROOT/lib/libPxLApi.so
}




