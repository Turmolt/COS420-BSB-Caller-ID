#ifndef SQLHELPER
#define SQLHELPER

#include <QtSql>


class sqlHelper
{
    public:
        ~sqlHelper();
        bool createConnection(void);
        bool closeConnection(void);
        QSqlDatabase getInstance(void);

    private:
        QSqlDatabase db;
};


#endif // SQLHELPER
