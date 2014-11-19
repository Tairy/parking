#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QMessageBox>

#include "in.h"
#include "out.h"
#include "admin.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    bool db_connect();
    ~MainWindow();

private slots:
    void on_in_clicked();

    void on_out_clicked();

    void on_admin_clicked();

    void on_nav_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
