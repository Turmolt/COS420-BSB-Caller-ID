#include <QtSql>

#include "sqlhelper.h"


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
    this->db.close();


    return true;
}
