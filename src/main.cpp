#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

	// chaddev added something at the start of the comment line. Here's a test comment
    return a.exec();
}
