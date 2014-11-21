#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QMessageBox>

class database
{
public:
    database();
    ~database();
private:
    QSqlDatabase db;
};

#endif // DATABASE_H
