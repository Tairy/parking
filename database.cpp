#include "database.h"

database::database(){
    this -> db = QSqlDatabase::addDatabase("QMYSQL");
    this -> db.setHostName("localhost");
    this -> db.setDatabaseName("parking");
    this -> db.setUserName("root");
    this -> db.setPassword("123456");
    bool conn = this -> db.open();
    if (!conn) {
        QMessageBox msgBox;
        msgBox.setText("无法连接数据库,请检查数据库是否启动,数据库服务器地址是否正确!");
        msgBox.exec();
    }
}

database::~database(){
    this -> db.close();
}
