#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "release.h"
#include "functions.h"

#include <QMainWindow>

#include <QDebug>
#include <QPushButton>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QEnterEvent>

#include <QIODevice>

#include <QCoreApplication>
#include <iostream>

#include <QtCore>
#include <QMessageBox>

#include <QString>
#include <string>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    friend class QHoverSensitiveButton;
    friend class Release;
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    static bool popup_open;
    static int move_speed;
    ~MainWindow();
    int countdown = 10;
    static int x_pos;
    static int y_pos;
    static int z_pos;


public slots:
    void fetchPressed();
    void tutorialPressed();
    void settingsPressed();
    void backPressed();
    void hover_time_up();
    void hover_time_down();
    void changeLabel();

    void move_up();
    void move_backward();
    void move_down();
    void move_forward();
    void move_left();
    void move_right();
    void move_finished();

private:
    Ui::MainWindow *ui;
    QSerialPort port;
    QByteArray ard_data;

    void write_to_arduino(QString data);

};

#endif // MAINWINDOW_H
