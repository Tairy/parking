#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "in.h"
#include "out.h"

#include <QSqlDatabase>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("停车场管理系统");
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::db_connect(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("parking");
    db.setUserName("root");
    db.setPassword("123456");
    bool conn = db.open();
    if (conn) {
        return true;
    } else {
        return false;
    }
}

void MainWindow::on_in_clicked()
{
    if(this -> db_connect()){
        in *inWindow;
        inWindow = new in();
        this -> close();
        inWindow -> show();
    } else {
        QMessageBox msgBox;
        msgBox.setText("无法连接数据库,请检查数据库是否启动,数据库服务器地址是否正确!");
        msgBox.exec();
    }
}

void MainWindow::on_out_clicked()
{
    if(this -> db_connect()){
        out *outWindow;
        outWindow = new out();
        this -> close();
        outWindow -> show();
    } else {
        QMessageBox msgBox;
        msgBox.setText("无法连接数据库,请检查数据库是否启动,数据库服务器地址是否正确!");
        msgBox.exec();
    }
}

void MainWindow::on_admin_clicked()
{

}

void MainWindow::on_nav_clicked()
{

}
