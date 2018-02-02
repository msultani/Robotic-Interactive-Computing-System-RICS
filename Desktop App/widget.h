#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void leftPressed();
    void rightPressed();
    void upPressed();
    void downPressed();



private:
    Ui::Widget *ui;
    QPushButton *left_button;
    QPushButton *right_button;
    QPushButton *up_button;
    QPushButton *down_button;
};

#endif // WIDGET_H
