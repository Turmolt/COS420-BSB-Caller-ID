#include "mainwindow.h"
#include "androidreciever.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    androidReciever android;
    android.startServer();

    MainWindow w;
    w.show();


    return a.exec();
}
