#include "mainwindow.h"
#include <QApplication>

#include "androidreciever.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    androidReciever android(0, &w);
    android.startServer();


    return a.exec();
}
