#include "mainwindow.h"
#include <QApplication>

#include "androidreceiver.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    androidReceiver android(0, &w);
    android.startServer();


    return a.exec();
}
