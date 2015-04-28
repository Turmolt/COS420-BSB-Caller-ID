#ifndef ANDROIDRECEIVER_H
#define ANDROIDRECEIVER_H

#include <QString>
#include <QTcpServer>
#include <QTcpSocket>
#include <athread.h>
#include "mainwindow.h"


class androidReceiver : public QTcpServer
{
    Q_OBJECT

    public:
        explicit androidReceiver (QObject *parent = 0, MainWindow *w = NULL);
        void startServer();

    public slots:
        void incomingConnection(qintptr socketDescriptor);

    private:
        MainWindow *window;
        QTcpServer *server;
};

#endif // ANDROIDRECIEVER_H
