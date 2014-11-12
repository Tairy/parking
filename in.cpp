#include "in.h"
#include "ui_in.h"
#include "mainwindow.h"
#include <QDateTime>
#include <QTimer>
#include <QtSql>
#include <QtDebug>
#include <QMessageBox>

in::in(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::in)
{
    ui->setupUi(this);
    setWindowTitle("停车场管理系统");
    this -> initWindow();
}

in::~in()
{
    delete ui;
}

void in::on_back_clicked()
{
    MainWindow *m;
    m = new MainWindow();
    this -> close();
    m -> show();
}

void in::initWindow(){

    QTimer *timer = new QTimer(this);
    displayTime();
    connect(timer, SIGNAL(timeout()), this, SLOT(displayTime()));
    timer->start(1000);

    QString car_pos = this -> allocationPos();

    if(car_pos == "false") {
        ui -> pos -> setAlignment(Qt::AlignCenter);
        ui -> pos -> setStyleSheet("border: 1px solid red;");
        ui -> pos -> setText("车库已满");
        ui -> car_num -> setEnabled(false);
    } else {
        ui -> pos -> setAlignment(Qt::AlignCenter);
        ui -> pos -> setStyleSheet("border: 1px solid green;");
        ui -> pos -> setText(car_pos);
    }
}

void in::displayTime(){
    QDateTime dt;
    QTime time;
    QDate date;

    dt.setTime(time.currentTime());
    dt.setDate(date.currentDate());

    QString currentDate = dt.toString("yyyy-MM-dd hh:mm:ss");
    ui -> in_time -> setAlignment(Qt::AlignCenter);
    ui -> in_time -> setStyleSheet("border: 1px solid green;");
    ui->in_time->setText(currentDate);
}

QString in::allocationPos(){
    QSqlQuery qry;
    qry.prepare( "SELECT * FROM `car_pos` WHERE `status` = 'free' LIMIT 1" );
    if( !qry.exec() ){
        qDebug() << qry.lastError();
        return "DB ERROR";
    } else {
        while( qry.next() ){
            return qry.value(0).toString();
        }
        return "false";
    }
}

void in::on_enter_clicked()
{
    if(ui -> car_num -> isEnabled()){
        QString input_car_num = ui -> car_num -> toPlainText();
        QString input_in_time = ui -> in_time -> text();
        QString input_place_id = ui -> pos -> text();

        QSqlQuery qry;
        QString sql = "INSERT INTO `spaces` (`car_num`, `place_id`, `in_time`) VALUES ('";
        sql += input_car_num;
        sql += "','";
        sql += input_place_id;
        sql += "','";
        sql += input_in_time;
        sql +="')";

        qry.prepare(sql);

        if( !qry.exec() ) {
            qDebug() << qry.lastError();
        } else {
            QString  sql_up = "UPDATE `car_pos` SET `status` = 'full' WHERE id = ";
            sql_up += input_place_id;
            qry.prepare(sql_up);
            if( !qry.exec() )
                qDebug() << qry.lastError();
        }
        QMessageBox msgBox;
        msgBox.setText("入库成功!");
        msgBox.exec();
        this -> initWindow();
    } else {
        QMessageBox msgBox;
        msgBox.setText("车库已满,不要乱点!!");
        msgBox.exec();
    }
}
