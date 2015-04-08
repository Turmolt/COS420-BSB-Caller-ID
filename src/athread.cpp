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
    connect(socket,SIGNAL(readyRe()),this,SLOT(readyRead()),Qt::DirectConnection);
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()));

    //Which client is connected?
    qDebug() << socketDescriptor << " Client connected";

    QString phone_Number = "5158641478";
    populate_Contacts(phone_Number);

    exec();
}

void aThread::readyRead()
{
    //get the info!
    QByteArray data = socket->readAll();

    qDebug() << "Data: " << data;

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

    query.prepare("select c.FirstName, c.LastName, c.TaxID, c.DateOfBirth, co.Contact, lo.Value, acc.AccountNumber, loo.Value from dbo.Customers c left join dbo.Contacts co on c.id = co.CustomerID left join dbo.Lookups lo on lo.ID = co.ContactTypeID left join dbo.Accounts acc on acc.CustomerID = c.id left join dbo.Lookups loo on loo.ID = acc.AccountTypeID where co.Contact = ?");
    query.bindValue(0, phone_Number);
    query.last();
    size = query.at() + 1;
    qDebug() << size << " records";

    query.first();
    for (int i = 0; i < window->all_Buttons.size(); i++) {
        if (i < size)
        {
            window->all_Buttons[i]->setVisible(true);
            window->all_Labels[i]->setVisible(true);

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
