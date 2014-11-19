#ifndef IN_H
#define IN_H

#include <QMainWindow>
#include <QDateTime>
#include <QTimer>
#include <QtSql>
#include <QtDebug>
#include <QMessageBox>
#include "mainwindow.h"

namespace Ui {
class in;
}

class in : public QMainWindow
{
    Q_OBJECT

public:
    explicit in(QWidget *parent = 0);
    ~in();

    void initWindow();
    QString allocationPos();

private slots:
    void on_back_clicked();
    void displayTime();

    void on_enter_clicked();

private:
    Ui::in *ui;
};

#endif // IN_H
