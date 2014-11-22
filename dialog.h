#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtSql>
#include"admin.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    bool checkUser();

private slots:
    void on_login_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
