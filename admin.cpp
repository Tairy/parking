#include "admin.h"
#include "ui_admin.h"
#include <QtSql>
#include <QtDebug>
#include <QMessageBox>

admin::admin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);
    this -> initWindow();
}

admin::~admin()
{
    delete ui;
}

void admin::initWindow(){
    ui -> po_statu -> setColumnCount(4);
    ui-> po_statu -> horizontalHeader()->setDefaultSectionSize(150);

    QStringList header;
    header<<tr("车位")<<tr("状态")<<tr("车牌号")<<tr("入库时间");
    ui-> po_statu ->setHorizontalHeaderLabels(header);
    ui-> po_statu -> horizontalHeader()->setStretchLastSection(true);



    for(int i = 0; i < 8; i++) {
        int row_count = ui-> po_statu ->rowCount(); //获取表单行数
        ui-> po_statu -> insertRow(row_count);

        QTableWidgetItem *item = new QTableWidgetItem();
        QTableWidgetItem *item1 = new QTableWidgetItem();
        QTableWidgetItem *item2 = new QTableWidgetItem();
        QTableWidgetItem *item3 = new QTableWidgetItem();

        item -> setText("1");
        item1 -> setText("2");
        item2 -> setText("3");
        item3 -> setText("4");

        ui-> po_statu ->setItem(row_count, 0, item);
        ui-> po_statu ->setItem(row_count, 1, item1);
        ui-> po_statu ->setItem(row_count, 2, item2);
        ui-> po_statu ->setItem(row_count, 3, item3);
    }
}
