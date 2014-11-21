#ifndef ADMIN_H
#define ADMIN_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QMessageBox>
#include <QFileDialog>
#include <QPoint>
#include "config.h"
#include "drawmap.h"
#include "mainwindow.h"

namespace Ui {
class admin;
}

class admin : public QMainWindow
{
    Q_OBJECT

public:
    explicit admin(QWidget *parent = 0);
    ~admin();

    void initWindow();

private slots:
    void on_open_fille_clicked();

    void on_import_2_clicked();

    void on_viewmap_clicked();

    void on_go_clicked();

    void on_back_clicked();

private:
    Ui::admin *ui;
    config *adminConfig;
};

#endif // ADMIN_H
