#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include "widget.h"
#include <QtWidgets>
#include <QTime>

#include <QWidget>
#include <QDebug>
#include <QPushButton>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QEnterEvent>

#include <QtCore>
#include <QMessageBox>


class QHoverSensitiveButton : public QPushButton
{
    Q_OBJECT
public:
    explicit QHoverSensitiveButton(QWidget *parent = 0);
    static bool hoverMode;

private:
    QTime t;

protected:
    void hoverEnter(QHoverEvent *event);
    void hoverLeave(QHoverEvent *event);
    bool event(QEvent *event);

signals:

public slots:
};



#endif // CUSTOMBUTTON_H
