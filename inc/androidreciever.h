#ifndef ANDROIDRECIEVER_H
#define ANDROIDRECIEVER_H
#include <QString>
#include <QTcpServer>
#include <QTcpSocket>
#include <athread.h>


class androidReciever : public QTcpServer
{
    Q_OBJECT


    public:
        explicit androidReciever (QObject *parent = 0);
        void startServer();


    public slots:
        void incomingConnection(qintptr socketDescriptor);

    private:
        QTcpServer *server;
};

#endif // ANDROIDRECIEVER_H
