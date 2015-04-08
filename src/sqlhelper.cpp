#include <QtSql>

#include "sqlhelper.h"


sqlHelper::~sqlHelper()
{
    closeConnection();
}

bool sqlHelper::createConnection(void)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Driver={SQL Server};Server=rosebloom.arvixe.com;Database=AnimeGuide");
    db.setUserName("umaine");
    db.setPassword("blackbear");
    bool ok = db.open();


    return ok;
}

QSqlDatabase sqlHelper::getInstance(void)
{
    return this->db;
}

bool sqlHelper::closeConnection(void)
{
    qDebug() << "closeConnection() called";
    this->db.close();


    return true;
}
