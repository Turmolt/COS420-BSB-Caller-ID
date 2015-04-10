#ifndef CONTACT_H
#define CONTACT_H

#include <QMainWindow>

#include <QLabel>
#include <QPushButton>
#include <QStack>
#include <QString>
#include <QTextEdit>


class contact
{
public:
    contact();
    contact(QPushButton *button, QLabel *label, QTextEdit *notes);
    ~contact();

    void add_Note(QString note);
    void setVisible(bool visible);
    QString name;
    QString phone_Number;
    QString date_Of_Birth;
    QString social_Security;
    QStack<QString> notes;

    QPushButton *pbutton;
    QLabel *plabel;
    QTextEdit *pnotes;
};

#endif // CONTACT_H
