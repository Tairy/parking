#include "mainwindow.h"
#include "database.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    new database(); // Connect Databse
    //new config(); // Load config option

    MainWindow w;
    w.show();

    return a.exec();
}
