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

    window->populate_Contacts(QString(data.data()));
    window->populate_Contacts("2078526155");
    window->display_Contacts();

    socket->write(data);
}

void aThread::disconnected()
{
    qDebug() << socketDescriptor << " disconnected.";

    socket->deleteLater();


    exit(0);
}
