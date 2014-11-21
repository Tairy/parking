#ifndef NAV_H
#define NAV_H

#include <QMainWindow>
#include <QScrollArea>
#include <QLabel>
#include "config.h"
#include "drawmap.h"
#include "mainwindow.h"

namespace Ui {
class nav;
}

class nav : public QMainWindow
{
    Q_OBJECT

public:
    explicit nav(QWidget *parent = 0);
    void showImage(QImage image);
    ~nav();

private slots:
    void on_go_clicked();

private:
    Ui::nav *ui;
    QScrollArea *scrollArea;
    QLabel *label;
    config *adminConfig;
};

#endif // NAV_H
