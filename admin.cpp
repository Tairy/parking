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

}

void admin::on_open_fille_clicked() {
    QString fileName = QFileDialog::getOpenFileName(this,
             tr("Open XML File"), "/home", tr("XML Files (*.xml)"));
        ui->FilePath->setText(fileName);
}

void admin::on_import_2_clicked() {
    QString xmlFilePath = ui -> FilePath ->text();

    drawMap *map = new drawMap(xmlFilePath);
    QImage mapImage = map -> convertXmlToImage();
    nav *navShow = new nav();
    navShow -> showImage(mapImage);

    this -> adminConfig ->setConfigOption("xmlpath", xmlFilePath);
}

void admin::on_viewmap_clicked() {
    QString xmlpath = this -> adminConfig ->getConfigOption("xmlpath");
    drawMap *map = new drawMap(xmlpath);
    QImage mapImage = map -> convertXmlToImage();
    nav *navShow = new nav();
    navShow -> showImage(mapImage);
}

void admin::on_go_clicked() {

    QString xmlpath = this -> adminConfig ->getConfigOption("xmlpath");
    QString to_pos_num = ui -> to_pos_num ->text();

    drawMap *map = new drawMap(xmlpath);
    QImage mapImage = map -> draw_widh_nav(to_pos_num);
    nav *navShow = new nav();
    navShow -> showImage(mapImage);
}

void admin::on_back_clicked() {
    MainWindow *m;
    m = new MainWindow();
    this -> close();
    m -> show();
}
