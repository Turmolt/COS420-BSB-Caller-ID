#ifndef ANDROIDRECIEVER_H
#define ANDROIDRECIEVER_H

#include <QString>
#include <QTcpServer>
#include <QTcpSocket>
#include <athread.h>
#include "mainwindow.h"


class androidReciever : public QTcpServer
{
    Q_OBJECT

    public:
        explicit androidReciever (QObject *parent = 0, MainWindow *w = NULL);
        void startServer();

    public slots:
        void incomingConnection(qintptr socketDescriptor);

    private:
        MainWindow *window;
        QTcpServer *server;
};

#endif // ANDROIDRECIEVER_H
