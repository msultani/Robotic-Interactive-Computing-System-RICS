#ifndef QHOVERSENSATIVEBUTTON_H
#define QHOVERSENSATIVEBUTTON_H
#include "mainwindow.h"
#include "functions.h"
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

#include <QWaitCondition>


class QHoverSensitiveButton : public QPushButton
{
    friend class MainWindow;
    Q_OBJECT
public:
    explicit QHoverSensitiveButton(QWidget *parent = 0);
    static bool hoverMode;
    static bool hoverPending;
    static QString hoverButton;
    static int hoverTime;

    void hoverWait();

signals:
    void hovered();
    void changeLabel();


private:
    void hoverButtonEntered();
    void buttonEntered();
    static QTime t;

protected:
    void hoverEnter(QHoverEvent *event);
    void hoverLeave(QHoverEvent *event);
    bool event(QEvent *event);


signals:

public slots:
};

#endif // QHOVERSENSATIVEBUTTON_H
