#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QVector>



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


    private:
        Ui::MainWindow *ui;
        void toggle_Contacts(int contact_Number);
        void hide_Others(int contact_Number);
        void show_All();
        QVector<QPushButton*> all_Buttons;
        QVector<QLabel*> all_Labels;

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
