#include "androidreceiver.h"
#include "mainwindow.h"
#include <QString>


static QString incNumb;
bool messaged = false;

androidReceiver::androidReceiver(QObject *parent, MainWindow *w) :
    QTcpServer(parent)
{
    this->window = w;
}

void androidReceiver::startServer()
{
    int port = 23;

    if (!this->listen(QHostAddress::Any, port))
    {
        qDebug() << "Server could not start.";
    }
    else
    {
        qDebug() << "Server started! Waiting for number...";
    }
}

void androidReceiver::incomingConnection(qintptr socketDescriptor)
{
    qDebug() << socketDescriptor << " Connecting...";

    //Run new connection in a new thread :)
    aThread *thread = new aThread(socketDescriptor, this, window);

    //connect the signal to the slot

    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    thread->run();
}
