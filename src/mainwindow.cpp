#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sqlhelper.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->widget_notes->setVisible(false);

    // This vector should be populated with data from the database
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

    // This vector should be populated with data from the database
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

    // This vector should be populated with notes from the database
    contact_Notes.push_back(new QStack<QString>);
    contact_Notes.push_back(new QStack<QString>);
    contact_Notes.push_back(new QStack<QString>);
    contact_Notes.push_back(new QStack<QString>);
    contact_Notes.push_back(new QStack<QString>);
    contact_Notes.push_back(new QStack<QString>);
    contact_Notes.push_back(new QStack<QString>);
    contact_Notes.push_back(new QStack<QString>);
    contact_Notes.push_back(new QStack<QString>);
    contact_Notes.push_back(new QStack<QString>);

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

void MainWindow::on_Button_Close_clicked()
{
    show_All(displayed_Contact);
}

void MainWindow::on_Button_Save_clicked()
{
    // Push the new note to the stack
    contact_Notes[displayed_Contact]->push(ui->text_notes->toPlainText());
    // Throw out the oldest notes if more than five
    // Kind of a hack but it works
    while (contact_Notes[displayed_Contact]->size() > 5) {
        contact_Notes[displayed_Contact]->pop_front();
    }

    show_All(displayed_Contact);
}

void MainWindow::toggle_Contacts(int contact_Number)
{
    // Use the structure from before
    // Each button is a check box
    if (all_Buttons[contact_Number]->isChecked()) {
        display_Contact(contact_Number);
    } else {
        show_All(contact_Number);
    }
}

void MainWindow::display_Contact(int contact_Number)
{
    QStack<QString> temp_Stack;
    QString temp_String;

    all_Buttons[contact_Number]->setChecked(true);
    // Record the current contact so the save button can reference it
    displayed_Contact = contact_Number;

    // Make all buttons and labels invisible
    for (int i = 0; i < all_Buttons.size(); i++) {
       if (i != contact_Number) {
           all_Labels[i]->setVisible(false);
           all_Buttons[i]->setVisible(false);
       }
    }

    // Clear the notes box and populate it from the stack for the current contact
    ui->text_log->clear();
    ui->text_notes->clear();
    while (!contact_Notes[contact_Number]->empty()) {
        temp_String = contact_Notes[contact_Number]->pop();
        ui->text_log->append(temp_String);
        temp_Stack.push(temp_String);
    }

    // Move the elements back to the permanent stack
    while (!temp_Stack.empty()) {
        temp_String = temp_Stack.pop();
        contact_Notes[contact_Number]->push(temp_String);
    }

    ui->widget_notes->show();
}

void MainWindow::show_All(int contact_Number)
{
    // Set all contact buttons as visible, and as unchecked
    for (int i = 0; i < all_Buttons.size(); i++) {
        all_Labels[i]->setVisible(true);
        all_Buttons[i]->setVisible(true);
        all_Buttons[i]->setChecked(false);
    }

    ui->widget_notes->hide();
}
