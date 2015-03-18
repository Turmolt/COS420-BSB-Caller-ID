#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sqlhelper.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->widget_notes->setVisible(false);

    all_Buttons.push_back(ui->Button_Contact_01);
    all_Buttons.push_back(ui->Button_Contact_02);
    all_Buttons.push_back(ui->Button_Contact_03);
    all_Buttons.push_back(ui->Button_Contact_04);
    all_Buttons.push_back(ui->Button_Contact_05);
    all_Buttons.push_back(ui->Button_Contact_06);
    all_Buttons.push_back(ui->Button_Contact_07);
    all_Buttons.push_back(ui->Button_Contact_08);
    all_Buttons.push_back(ui->Button_Contact_09);
    all_Buttons.push_back(ui->Button_Contact_10);

    all_Labels.push_back(ui->label_Contact_01);
    all_Labels.push_back(ui->label_Contact_02);
    all_Labels.push_back(ui->label_Contact_03);
    all_Labels.push_back(ui->label_Contact_04);
    all_Labels.push_back(ui->label_Contact_05);
    all_Labels.push_back(ui->label_Contact_06);
    all_Labels.push_back(ui->label_Contact_07);
    all_Labels.push_back(ui->label_Contact_08);
    all_Labels.push_back(ui->label_Contact_09);
    all_Labels.push_back(ui->label_Contact_10);

    qDebug() << "Connecting to database...";
    sqlHelper sqlconn;
    bool connResult = sqlconn.createConnection();
    QSqlDatabase db = sqlconn.getInstance();
    if (!connResult) {
        qDebug() << "SQL Error" << db.lastError();
    }
    sqlconn.closeConnection();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Button_Contact_01_clicked()
{
    toggle_Contacts(0);
}

void MainWindow::on_Button_Contact_02_clicked()
{
    toggle_Contacts(1);
}
void MainWindow::on_Button_Contact_03_clicked()
{
    toggle_Contacts(2);
}

void MainWindow::on_Button_Contact_04_clicked()
{
    toggle_Contacts(3);
}

void MainWindow::on_Button_Contact_05_clicked()
{
    toggle_Contacts(4);
}

void MainWindow::on_Button_Contact_06_clicked()
{
    toggle_Contacts(5);
}
void MainWindow::on_Button_Contact_07_clicked()
{
    toggle_Contacts(6);
}
void MainWindow::on_Button_Contact_08_clicked()
{
    toggle_Contacts(7);
}
void MainWindow::on_Button_Contact_09_clicked()
{
    toggle_Contacts(8);
}

void MainWindow::on_Button_Contact_10_clicked()
{
    toggle_Contacts(9);
}

void MainWindow::on_Button_Close_clicked() {
    show_All();
}

void MainWindow::on_Button_Save_clicked() {
    show_All();
}

void MainWindow::toggle_Contacts(int contact_Number) {
    if (all_Buttons[contact_Number]->isChecked()) {
        hide_Others(contact_Number);
    } else {
        show_All();
    }
}

void MainWindow::hide_Others(int contact_Number) {
    all_Buttons[contact_Number]->setChecked(true);

    for (int i = 0; i < all_Buttons.size(); i++) {
       if (i != contact_Number) {
           all_Labels[i]->setVisible(false);
           all_Buttons[i]->setVisible(false);
       }
    }

    ui->widget_notes->show();
}

void MainWindow::show_All() {
    for (int i = 0; i < all_Buttons.size(); i++) {
        // Set all contact buttons as visible, and as unchecked
        all_Labels[i]->setVisible(true);
        all_Buttons[i]->setVisible(true);
        all_Buttons[i]->setChecked(false);
    }

    ui->widget_notes->hide();
}
