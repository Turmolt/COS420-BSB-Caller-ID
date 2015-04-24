#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QVector>
#include <QStack>
#include <QString>

#include "sqlhelper.h"
#include "contact.h"


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

        void populate_Contacts(QString phone_Number);
        void display_Contacts(void);
        void show_All(void);
        void hide_All(void);
        void set_Number(QString number);

        QVector<contact> contacts;
        QVector<QPushButton*> all_Buttons;
        QVector<QLabel*> all_Labels;
        bool all_Shown;
        int num_Contacts;
        int displayed_Contact;
        sqlHelper dbconn;

    public slots:


    private:
        Ui::MainWindow *ui;
        void toggle_Contacts(int contact_Number);
        void show_Contact(int contact_Number);
        void add_Note(int contact_Number, QString note);
        void refresh_Notes(int contact_Number);
        void update_Notes(int contact_Number);

    private slots:
        void on_Button_Contact_01_clicked();
        void on_Button_Contact_02_clicked();
        void on_Button_Contact_03_clicked();
        void on_Button_Contact_04_clicked();
        void on_Button_Contact_05_clicked();
        void on_Button_Contact_06_clicked();
        void on_Button_Contact_07_clicked();
        void on_Button_Contact_08_clicked();
        void on_Button_Contact_09_clicked();
        void on_Button_Contact_10_clicked();
        void on_Button_Close_clicked();
        void on_Button_Save_clicked();
        void on_Button_Clear_clicked();

};

#endif // MAINWINDOW_H
