#include "nav.h"
#include "ui_nav.h"

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
