#ifndef CONTACTS_H
#define CONTACTS_H

#include <QSignalMapper>
#include <QWidget>

class contacts : public QWidget
{
    Q_OBJECT
public:
    contacts(QStringList texts, QWidget *parent = 0);

signals:
    void clicked(const QString &text);

private:
    QSignalMapper *signalMapper;
};

#endif // CONTACTS_H
