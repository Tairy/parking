#include "admin.h"
#include "ui_admin.h"

admin::admin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::admin) {
    ui->setupUi(this);
    this -> adminConfig = new config();
    this -> initWindow();
    setWindowTitle("停车场管理系统");
}

admin::~admin() {
    delete ui;
}

void admin::initWindow(){
//    ui -> po_statu -> setColumnCount(4);
//    ui-> po_statu -> horizontalHeader()->setDefaultSectionSize(150);

//    QStringList header;
//    header<<tr("车位")<<tr("状态")<<tr("车牌号")<<tr("入库时间");
//    ui-> po_statu ->setHorizontalHeaderLabels(header);
//    ui-> po_statu -> horizontalHeader()->setStretchLastSection(true);



//    for(int i = 0; i < 8; i++) {
//        int row_count = ui-> po_statu ->rowCount(); //获取表单行数
//        ui-> po_statu -> insertRow(row_count);

//        QTableWidgetItem *item = new QTableWidgetItem();
//        QTableWidgetItem *item1 = new QTableWidgetItem();
//        QTableWidgetItem *item2 = new QTableWidgetItem();
//        QTableWidgetItem *item3 = new QTableWidgetItem();

//        item -> setText("1");
//        item1 -> setText("2");
//        item2 -> setText("3");
//        item3 -> setText("4");

//        ui-> po_statu ->setItem(row_count, 0, item);
//        ui-> po_statu ->setItem(row_count, 1, item1);
//        ui-> po_statu ->setItem(row_count, 2, item2);
//        ui-> po_statu ->setItem(row_count, 3, item3);
//    }
}

void admin::on_open_fille_clicked() {
    QString fileName = QFileDialog::getOpenFileName(this,
             tr("Open XML File"), "/home", tr("XML Files (*.xml)"));
        ui->FilePath->setText(fileName);
}

void admin::on_import_2_clicked() {
    QString xmlFilePath = ui -> FilePath ->text();
    drawMap *map = new drawMap(xmlFilePath);
    map -> draw();

    this -> adminConfig ->setConfigOption("xmlpath", xmlFilePath);
}

void admin::on_viewmap_clicked() {
    QString xmlpath = this -> adminConfig ->getConfigOption("xmlpath");
    drawMap *map = new drawMap(xmlpath);
    map -> draw();
}

void admin::on_go_clicked() {
    QSqlQuery qry_xmlpath;
    QString sql_xmlpath = "SELECT `value` FROM `config` WHERE `key`='xmlpath' LIMIT 1";
    qry_xmlpath.prepare(sql_xmlpath);
    if( !qry_xmlpath.exec() ){
        qDebug() << qry_xmlpath.lastError();
        return;
    }
    if( qry_xmlpath.next() ){
        QString xmlpath = qry_xmlpath.value(0).toString();
    }

    QString to_pos_num = ui -> to_pos_num ->text();
    QSqlQuery qry, qry_door;
    QString sql = "SELECT * FROM `car_pos` WHERE `pos_num`='";
    sql += to_pos_num;
    sql += "' LIMIT 1";
    qry.prepare(sql);
    if( !qry.exec() ){
        qDebug() << qry.lastError();
        return;
    }
    if( qry.next() ){
        QString x = qry.value(1).toString();
        QString y = qry.value(2).toString();
        QString width = qry.value(3).toString();
        QString height = qry.value(4).toString();

        QString door_pos_sql = "SELECT * FROM `car_pos` WHERE `type`='door'";
        qry_door.prepare(door_pos_sql);
        if( !qry_door.exec() ){
            qDebug() << qry_door.lastError();
            return;
        }
        if(qry_door.next()) {
            QString door_x = qry.value(1).toString();
            QString door_y = qry.value(2).toString();

//            drawMap *map = new drawMap(xmlpath);
//            map -> draw_widh_nav();
        }
    }

}
