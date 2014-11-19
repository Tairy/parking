#ifndef NAV_H
#define NAV_H

#include <QMainWindow>

namespace Ui {
class nav;
}

class nav : public QMainWindow
{
    Q_OBJECT

public:
    explicit nav(QWidget *parent = 0);
    ~nav();

private:
    Ui::nav *ui;
};

#endif // NAV_H
