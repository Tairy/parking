#include "nav.h"
#include "ui_nav.h"
#include <QDebug>

nav::nav(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::nav)
{
    ui->setupUi(this);
    setWindowTitle("停车场导航图");
}

nav::~nav()
{
    delete ui;
}

void nav::showImage(QImage image){
    label = new QLabel();
    label -> setPixmap(QPixmap::fromImage(image));
    ui -> scrollArea->setWidget(label);
    ui -> scrollArea -> setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui -> scrollArea ->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui -> scrollArea->viewport()->setBackgroundRole(QPalette::Dark);
    this -> show();
}

void nav::on_go_clicked() {
    QString xmlpath = this -> adminConfig ->getConfigOption("xmlpath");
    QString to_pos_num = ui -> pos_num ->text();

    drawMap *map = new drawMap(xmlpath);
    QImage mapShow = map -> draw_widh_nav(to_pos_num);
    this -> showImage(mapShow);
}
