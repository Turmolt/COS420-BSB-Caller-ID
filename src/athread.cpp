#include "athread.h"
#include "mainwindow.h"

#include <QDebug>
#include <QSqlDatabase>


aThread::aThread(qintptr ID, QObject *parent, MainWindow *w) :
    QThread(parent)
{
    this->socketDescriptor = ID;
    this->window = w;
}

void aThread::run()
{
    //Lets do this
    qDebug() << "Thread Started";

    socket = new QTcpSocket();

    //if there is an error, we will catch it here
    if(!socket->setSocketDescriptor(this->socketDescriptor))
    {
        //uh oh
        emit error(socket->error());
        return;
    }

    //otherwise we can connect!
    //Qt::DirectConnection is used because its multithreaded
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));

    //Which client is connected?
    qDebug() << socketDescriptor << " Client connected";

    exec();
}

void aThread::readyRead()
{
    //get the info!
    QByteArray data = socket->readLine();

    qDebug() << "Data: " << data;

    populate_Contacts(QString(data.data()));

    socket->write(data);
}

void aThread::disconnected()
{
    qDebug() << socketDescriptor << " disconnected.";

    socket->deleteLater();


    exit(0);
}

void aThread::populate_Contacts(QString phone_Number)
{
    QSqlDatabase db = window->dbconn.getInstance();
    QSqlQuery query(db);
    int size = 0;
    QString name = "";
    QString dob_ss = "";

    query.prepare("select c.FirstName, c.LastName, c.TaxID, c.DateOfBirth, co.Contact, lo.Value as ContactType, acc.AccountNumber, loo.Value as AccountType, c.Notes from dbo.Customers c left join dbo.Contacts co on c.id = co.CustomerID left join dbo.Lookups lo on lo.ID = co.ContactTypeID left join dbo.Accounts acc on acc.CustomerID = c.id left join dbo.Lookups loo on loo.ID = acc.AccountTypeID where c.TaxID in ( select c.TaxID from dbo.Customers c left join dbo.Contacts co on c.id = co.CustomerID left join dbo.Lookups lo on lo.ID = co.ContactTypeID where co.Contact = :phone_Number)");
    query.bindValue(":phone_Number", phone_Number);
    query.exec();

    // Get the number of records
    query.last();
    size = query.at() + 1;
    qDebug() << size << " records";
    window->num_Contacts = size;

    // Iterate through all ten contact spaces
    query.first();
    for (int i = 0; i < window->all_Buttons.size(); i++)
    {
        // Hide all buttons that don't have info
        // Set info for the contacts that do have info
        if (i < size)
        {
            if (window->all_Shown) {
                window->all_Buttons[i]->setVisible(true);
                window->all_Labels[i]->setVisible(true);
            } else
            {
                window->all_Buttons[window->displayed_Contact]->setVisible(true);
                window->all_Labels[window->displayed_Contact]->setVisible(true);
            }

            name = query.value(1).toString();
            name += " " + query.value(2).toString();
            window->all_Buttons[i]->setText(name);

            dob_ss = query.value(4).toString();
            dob_ss += " / " + query.value(3).toString();
            window->all_Labels[i]->setText(dob_ss);

            query.next();
        } else
        {
            window->all_Buttons[i]->setVisible(false);
            window->all_Labels[i]->setVisible(false);
        }
    }
}
