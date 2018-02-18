#ifndef QHOVERSENSATIVEBUTTON_H
#define QHOVERSENSATIVEBUTTON_H
#include "mainwindow.h"
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
    friend class MainWindow;
    Q_OBJECT
public:
    explicit QHoverSensitiveButton(QWidget *parent = 0);
    static bool hoverMode;

signals:
    void hovered();


private:
    void emitHovered();
    QTime t;

protected:
    void hoverEnter(QHoverEvent *event);
    void hoverLeave(QHoverEvent *event);
    bool event(QEvent *event);

    void hoverFetch();
    void hoverBack();

signals:

public slots:
};
#endif // QHOVERSENSATIVEBUTTON_H
