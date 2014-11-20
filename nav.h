#ifndef NAV_H
#define NAV_H

#include <QMainWindow>
#include <QScrollArea>
#include <QLabel>

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

private:
    Ui::nav *ui;
    QScrollArea *scrollArea;
    QLabel *label;
};

#endif // NAV_H
