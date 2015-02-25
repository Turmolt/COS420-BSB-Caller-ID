#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

	// Here's a test comment chadconflict added something to the end of the comment
    return a.exec();
}
