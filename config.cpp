#include "config.h"

config::config(){
    //this -> xmlFilePath = this -> getConfigOption("xmlpath");
    //this -> isLoaded = this -> getConfigOption("maploaded");
}

QString config::getConfigOption(QString key){
//    new database();

    QSqlQuery configQuery;
    QString configSql = "SELECT `value` FROM `config` WHERE `key`='"+ key +"' LIMIT 1";
    configQuery.prepare(configSql);

    if( !configQuery.exec() ){
        qDebug() << configQuery.lastError();
        QMessageBox msgBox;
        msgBox.setText("加载配置"+key+"时出错!");
        msgBox.exec();
        return NULL;
    }

    if(configQuery.next()){
        return configQuery.value(0).toString();
    } else {
        return NULL;
    }
}

void config::setConfigOption(QString key, QString value){
    QSqlQuery configQuery;
    QString configSql = "INSERT INTO `config` (`key`, `value`) VALUES ('" + key + "','" + value + "')";
    configQuery.prepare(configSql);

    if( !configQuery.exec() ){
        QMessageBox msgBox;
        msgBox.setText("Database Error!");
        msgBox.exec();
    }
}
