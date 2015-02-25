#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include"contactwindow.h"


namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

    public slots:
        void openContactWindow(); //Contact Window

    private:
        ContactWindow *myContactWindow; //Contact window
        Ui::MainWindow *ui;

    private slots:
        void on_ButtonContact1_clicked();
        void on_ButtonContact2_clicked();
        void on_ButtonContact3_clicked();
        void on_ButtonContact4_clicked();
        void on_ButtonContact5_clicked();
        void on_ButtonContact6_clicked();
        void on_ButtonContact7_clicked();
        void on_ButtonContact8_clicked();
        void on_ButtonContact9_clicked();
        void on_ButtonContact10_clicked();

};

#endif // MAINWINDOW_H
