#include "androidreciever.h"
#include <QString>


static QString incNumb;
bool messaged = false;

androidReciever::androidReciever(QObject *parent) :
    QTcpServer(parent)
{

}

void androidReciever::startServer()
{
    int port = 8888;

    if (!this->listen(QHostAddress::Any,port))
    {
        qDebug() << "Server could not start.";
    }
    else
    {
        qDebug() << "Server started! Waiting for number...";
    }
}

void androidReciever::incomingConnection(qintptr socketDescriptor)
{
    qDebug()<<socketDescriptor<<" Connecting...";

    //Run new connection in a new thread :)
    aThread *thread = new aThread(socketDescriptor, this);

    //connect the signal to the slot

    connect(thread,SIGNAL(finished()), thread, SLOT(deleteLater()));

    thread->run();
}
