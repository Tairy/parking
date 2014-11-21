#ifndef CONFIG_H
#define CONFIG_H

#include <QString>
#include <QtSql>
#include <database.h>

class config
{
public:
    config();
    void setConfigOption(QString key, QString value);
    QString getConfigOption(QString key);
    //bool getConfigOption(QString key);


//    QString xmlFilePath;
//    QString isLoaded;
};

#endif // CONFIG_H
