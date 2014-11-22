#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this -> adminConfig = new config();
    setWindowTitle("停车场管理系统");
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_in_clicked() {
    in *inWindow;
    inWindow = new in();
    this -> close();
    inWindow -> show();
}

void MainWindow::on_out_clicked() {
    out *outWindow;
    outWindow = new out();
    this -> hide();
    outWindow -> show();
}

void MainWindow::on_admin_clicked() {
    Dialog *loginDialog = new Dialog();
    loginDialog -> show();
    this ->close();
}

void MainWindow::on_nav_clicked() {
    QString xmlpath = this -> adminConfig ->getConfigOption("xmlpath");
    drawMap *map = new drawMap(xmlpath);
    map -> draw();
}
