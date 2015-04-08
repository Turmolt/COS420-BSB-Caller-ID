#ifndef ATHREAD_H
#define ATHREAD_H
#include "androidreciever.h"
#include <QThread>
#include <QTextEdit>
#include <QString>
#include <QTcpServer>
#include <QTcpSocket>

class aThread : public QThread
{
    Q_OBJECT
public:
    explicit aThread(qintptr ID, QObject *parent =0);
    void run();


signals:
    void error(QTcpSocket::SocketError socketError);
    void valueChanged(QString);

public slots:
    void readyRead();
    void disconnected();

private:
    QTcpSocket *socket;
    qintptr socketDescriptor;



};

#endif // ATHREAD_H
