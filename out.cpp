#include "out.h"
#include "ui_out.h"

out::out(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::out)
{
    ui->setupUi(this);
    setWindowTitle("停车场管理系统");
    this -> initWindow();
}

out::~out()
{
    delete ui;
}

void out::on_back_clicked()
{
    MainWindow *w;
    w = new MainWindow();
    this -> close();
    w -> show();
}

void out::initWindow(){
    QTimer *timer = new QTimer(this);
    displayTime();
    connect(timer, SIGNAL(timeout()), this, SLOT(displayTime()));
    timer->start(1000);
    ui -> in_time -> setStyleSheet("border: 1px solid green;");
    ui -> car_pos -> setStyleSheet("border: 1px solid green;");
    ui -> change -> setStyleSheet("border: 1px solid green;");
}

void out::displayTime(){
    QDateTime dt;
    QTime time;
    QDate date;

    dt.setTime(time.currentTime());
    dt.setDate(date.currentDate());

    QString currentDate = dt.toString("yyyy-MM-dd hh:mm:ss");
    ui -> out_time -> setAlignment(Qt::AlignCenter);
    ui -> out_time -> setStyleSheet("border: 1px solid green;");
    ui->out_time->setText(currentDate);
}

void out::on_textEdit_2_textChanged()
{
    QString input_car_num = ui -> textEdit_2 -> toPlainText();
    QSqlQuery qry;
    QString sql = "SELECT * FROM `spaces` WHERE `car_num`='";
    sql += input_car_num;
    sql += "' LIMIT 1";
    qry.prepare(sql);
    if( !qry.exec() ){
        qDebug() << qry.lastError();
    } else {
        if( qry.next() ){
            ui -> car_pos -> setAlignment(Qt::AlignCenter);
            ui -> car_pos -> setText(qry.value(2).toString());
            ui -> in_time -> setAlignment(Qt::AlignCenter);
            ui -> in_time -> setText(qry.value(3).toString());

            QTime time;
            QDate date;
            QDateTime dt = QDateTime::fromString(qry.value(3).toString(),"yyyy-MM-ddThh:mm:ss");
            QDateTime dt_now;
            dt_now.setTime(time.currentTime());
            dt_now.setDate(date.currentDate());

            float should_change = (dt.msecsTo(dt_now) /3600000.0) * 11;
            QString tr_timeDiff = QString("%1").arg(should_change);
            tr_timeDiff += "元";
            ui -> change -> setAlignment(Qt::AlignCenter);
            ui -> change -> setText(tr_timeDiff);
        } else {
            ui -> car_pos -> setText("");
            ui -> in_time -> setText("");
            ui -> change -> setText("");
        }
    }
}

void out::on_leave_clicked()
{
    QString input_car_num = ui -> textEdit_2 -> toPlainText();
    QString input_pos_id = ui -> car_pos -> text();
    QSqlQuery qry;
    QString sql = "DELETE FROM `spaces` WHERE `car_num` = '";
    sql += input_car_num;
    sql += "'";
    qry.prepare(sql);
    if( !qry.exec() ){
        qDebug() << qry.lastError();
    } else {
        QString  sql_up = "UPDATE `car_pos` SET `status` = 'free' WHERE id = ";
        sql_up += input_pos_id;
        qry.prepare(sql_up);
        if( !qry.exec() ){
            qDebug() << qry.lastError();
        } else {
            QMessageBox msgBox;
            msgBox.setText("出库成功，欢迎下次再来！");
            msgBox.exec();
            ui -> textEdit_2 ->setText("");
            ui -> car_pos -> setText("");
            ui -> in_time -> setText("");
            ui -> change -> setText("");
        }
    }

}
