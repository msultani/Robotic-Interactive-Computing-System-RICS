#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QPushButton>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QEnterEvent>

#include <QtCore>
#include <QMessageBox>

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
    void released();

private slots:
    void on_beginButton_clicked();
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;

    QPushButton *left_button;
    QPushButton *right_button;
    QPushButton *up_button;
    QPushButton *down_button;
    QPushButton *button;

    bool found_port;

    QSerialPort Ard;
    QByteArray Ard_data;

    const qint16 Ard_identifier = -1;
    QString Ard_port_name;

    enum Robot_cmd{up=1, down, left, right, forward, backward, stop} Command;

    void write_to_arduino();
};


#endif // WIDGET_H
