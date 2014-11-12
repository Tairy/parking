#ifndef OUT_H
#define OUT_H

#include <QMainWindow>

namespace Ui {
class out;
}

class out : public QMainWindow
{
    Q_OBJECT

public:
    explicit out(QWidget *parent = 0);
    ~out();
    void initWindow();

private slots:
    void on_back_clicked();
    void displayTime();

    void on_textEdit_2_textChanged();

    void on_leave_clicked();

private:
    Ui::out *ui;
};

#endif // OUT_H
