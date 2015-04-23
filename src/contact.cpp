#include "contact.h"

#include <QDate>


contact::contact()
{
}

contact::contact(QPushButton *button, QLabel *label, QTextEdit *notes, QTextEdit *CIF)
{
    this->pbutton = button;
    this->plabel = label;
    this->pnotes = notes;
    this->pCIF = cif;

    this->notes = QStack<QString>();
}

contact::~contact()
{
}

void contact::add_Note(QString note)
{
    if (note.size() != 0)
    {
        // Date in front of the message
        QString temp_String;
        temp_String += "[" + QDate::currentDate().toString("MM/dd/yy") + "]: ";

        notes.push_back(temp_String + note + "\n");

        // Throw out the oldest notes if more than five
        // Kind of a hack but it works
        while (notes.size() > 5)
        {
            notes.pop_front();
        }
    }
}

void contact::setVisible(bool visible)
{
    this->pbutton->setVisible(visible);
    this->plabel->setVisible(visible);
}
