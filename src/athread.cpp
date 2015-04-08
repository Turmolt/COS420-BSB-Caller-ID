#include "athread.h"

#include <QDebug>


aThread::aThread(qintptr ID,QObject *parent) :
    QThread(parent)
{
    this->socketDescriptor = ID;
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
