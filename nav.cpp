#include "nav.h"
#include "ui_nav.h"
#include <QDebug>

nav::nav(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::nav)
{
    ui->setupUi(this);
}

nav::~nav()
{
    delete ui;
}

void nav::showImage(QImage image){
//    ui -> mapView -> setPixmap(QPixmap::fromImage(image));
//    ui -> mapView -> resize(image.width(), image.height());
    label = new QLabel();
    label -> setPixmap(QPixmap::fromImage(image));
//    qDebug() << image.width();
    ui -> scrollArea->setWidget(label);
    ui -> scrollArea -> setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui -> scrollArea ->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui -> scrollArea->viewport()->setBackgroundRole(QPalette::Dark);
    this -> show();
//      this -> label = new QLabel;
//      this -> label -> setPixmap(QPixmap::fromImage(image));
//      this -> scrollArea
//    QLabel *label = new QLabel;
//    label -> setPixmap(QPixmap::fromImage(image));
//    QScrollArea *scrollArea = new QScrollArea;
//      this -> scrollArea->setWindowTitle("停车场平面图");
//      this -> scrollArea->setWidget(label);
//      this -> scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
//      this -> scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
//      this -> scrollArea->viewport()->setBackgroundRole(QPalette::Dark);

//      this -> scrollArea -> show();
}
