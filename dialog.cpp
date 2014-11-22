#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}
bool Dialog::checkUser(){
    QString username = ui->username->text();
    QString password = ui->password->text();
    qDebug() << username;
    QSqlQuery qry;
    qry.prepare( "SELECT * FROM `user` WHERE `username` = '"+username+"' and `password` = '"+password+"' LIMIT 1" );
    if( !qry.exec() ){
        qDebug() << qry.lastError();
        return false;
    } else {
        if( qry.next() ){
            qDebug()<<qry.value(0).toString();
            return true;
        } else {
            return false;
        }
    }
}

void Dialog::on_login_clicked()
{
    if(this -> checkUser()) {
        admin *adminWindow;
        adminWindow = new admin();
        this -> close();
        adminWindow -> show();
    } else {
        QMessageBox msgBox;
        msgBox.setText("用户名密码错误!");
        msgBox.exec();
    }
}
