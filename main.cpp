#include "mainwindow.h"
#include <QApplication>
#include <pylon/PylonIncludes.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Pylon::PylonAutoInitTerm pylonInit;

    MainWindow w;
    w.show();

    return a.exec();
}
