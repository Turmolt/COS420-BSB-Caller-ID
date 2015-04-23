#include "mainwindow.h"
#include "sqlhelper.h"
#include "ui_mainwindow.h"
#include "contact.h"


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

    qDebug() << "Connecting to database...";
    bool connResult = dbconn.createConnection();
    QSqlDatabase db = dbconn.getInstance();
    if (!connResult)
    {
        qDebug() << "SQL Error" << db.lastError();
    }

    hide_All();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Button_Contact_01_clicked() { toggle_Contacts(0); }
void MainWindow::on_Button_Contact_02_clicked() { toggle_Contacts(1); }
void MainWindow::on_Button_Contact_03_clicked() { toggle_Contacts(2); }
void MainWindow::on_Button_Contact_04_clicked() { toggle_Contacts(3); }
void MainWindow::on_Button_Contact_05_clicked() { toggle_Contacts(4); }
void MainWindow::on_Button_Contact_06_clicked() { toggle_Contacts(5); }
void MainWindow::on_Button_Contact_07_clicked() { toggle_Contacts(6); }
void MainWindow::on_Button_Contact_08_clicked() { toggle_Contacts(7); }
void MainWindow::on_Button_Contact_09_clicked() { toggle_Contacts(8); }
void MainWindow::on_Button_Contact_10_clicked() { toggle_Contacts(9); }

void MainWindow::on_Button_Close_clicked()
{
    show_All();
}

void MainWindow::on_Button_Save_clicked()
{
    QString temp_String = ui->text_notes->toPlainText();
    {
        // Push the new note to the stack and refresh the text box
        contacts[displayed_Contact].add_Note(temp_String);
    }
    refresh_Notes(displayed_Contact);
}

void MainWindow::on_Button_Clear_clicked() {
    qDebug() << "on_Button_Clear_clicked()";

    ui->textEdit_number->clear();
    hide_All();

    ui->label_NoContact->show();
}

void MainWindow::toggle_Contacts(int contact_Number)
{
    // Use the structure from before
    // Each button is a check box
    if (contacts[contact_Number].pbutton->isChecked())
    {
        show_Contact(contact_Number);
    } else
    {
        show_All();
    }
}

void MainWindow::show_Contact(int contact_Number)
{
    displayed_Contact = contact_Number;

    contacts[contact_Number].pbutton->setChecked(true);
    // Record the current contact so the save button can reference it

    // Make all buttons and labels invisible
    // except the pressed button
    for (int i = 0; i < all_Buttons.size(); i++)
    {
        all_Buttons[i]->setVisible(false);
        all_Labels[i]->setVisible(false);
    }

    contacts[contact_Number].setVisible(true);

    ui->widget_notes->setVisible(true);

    all_Shown = false;

    refresh_Notes(contact_Number);
}

void MainWindow::show_All(void)
{
    // Set all contact buttons as visible, and as unchecked
    for (int i = 0; i < contacts.size(); i++)
    {
        contacts[i].setVisible(true);
        contacts[i].pbutton->setChecked(false);
    }

    all_Shown = true;

    ui->widget_notes->hide();
}

void MainWindow::hide_All(void)
{
    for (int i = 0; i < all_Buttons.size(); i++)
    {
        all_Buttons[i]->setChecked(false);
        all_Buttons[i]->setVisible(false);
        all_Labels[i]->setVisible(false);
    }

    all_Shown = true;

    ui->widget_notes->hide();
}

void MainWindow::refresh_Notes(int contact_Number)
{
    QStack<QString> temp_Stack;
    QString temp_String;

    // Clear the notes box and populate it from the stack for the current contact
    ui->text_notes->clear();
    contacts[contact_Number].pnotes->clear();
    while (!contacts[contact_Number].notes.empty())
    {
        temp_String = contacts[contact_Number].notes.pop();
        contacts[contact_Number].pnotes->append(temp_String);
        temp_Stack.push(temp_String);
    }

    // Move the elements back to the permanent stack
    while (!temp_Stack.empty())
    {
        temp_String = temp_Stack.pop();
        contacts[contact_Number].notes.push(temp_String);
    }
}

void MainWindow::update_Notes(void)
{
    QSqlDatabase db = dbconn.getInstance();
}

void MainWindow::populate_Contacts(QString phone_Number)
{
    contacts.clear();

    QSqlDatabase db = dbconn.getInstance();
    int size = 0;
    QString name = "";
    QString dob = "";
    QString ss = "";

    QSqlQuery query(db);
    query.prepare("select c.FirstName, c.LastName, c.TaxID, c.DateOfBirth, co.Contact, lo.Value as ContactType, acc.AccountNumber, loo.Value as AccountType, c.Notes from dbo.Customers c left join dbo.Contacts co on c.id = co.CustomerID left join dbo.Lookups lo on lo.ID = co.ContactTypeID left join dbo.Accounts acc on acc.CustomerID = c.id left join dbo.Lookups loo on loo.ID = acc.AccountTypeID where c.TaxID in ( select c.TaxID from dbo.Customers c left join dbo.Contacts co on c.id = co.CustomerID left join dbo.Lookups lo on lo.ID = co.ContactTypeID where co.Contact = :phone_Number)");
    query.bindValue(":phone_Number", phone_Number);
    query.exec();

    // Get the number of contacts
    query.last();
    size = query.at() + 1;
    qDebug() << size << " records";
    num_Contacts = size;

    // Iterate through all ten contact spaces
    query.first();
    for (int i = 0; i < size; i++)
    {
        // Get accounts for contact
        contact temp = contact(all_Buttons[i], all_Labels[i], ui->text_log, ui->textEdit_CIF);

        name = query.value(0).toString();
        name += " " + query.value(1).toString();
        temp.name = name;

        ss = query.value(2).toString();
        dob = query.value(3).toString();
        temp.social_Security = ss;
        temp.date_Of_Birth = dob;

        contacts.push_back(temp);

        query.next();
    }

    if (size != 0)
    {
        ui->label_NoContact->hide();
    }
}

void MainWindow::display_Contacts(void)
{
    for (int i = 0; i < contacts.size(); i++)
    {
        contacts[i].plabel->setText(contacts[i].social_Security + " / " + contacts[i].date_Of_Birth);
        contacts[i].pbutton->setText(contacts[i].name);
        contacts[i].setVisible(true);
    }
}

void MainWindow::set_Number(QString number)
{
    ui->textEdit_number->setText(number);
    qDebug() << "number is " << number;
}
