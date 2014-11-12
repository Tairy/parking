#ifndef ADMIN_H
#define ADMIN_H

#include <QMainWindow>

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

private:
    Ui::admin *ui;
};

#endif // ADMIN_H
