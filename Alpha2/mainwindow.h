#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "release.h"
#include "functions.h"

#include <QMainWindow>
#include <QTcpSocket>
#include <QTcpServer>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

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
    void readTCPData();
    void connection();
    void fetchPressed();
    void tutorialPressed();
    void settingsPressed();
    void backPressed();
    void hover_time_up();
    void hover_time_down();
    void changeLabel();
    //void hover_pressed();

    void move_up();
    void move_backward();
    void move_down();
    void move_forward();
    void move_left();
    void move_right();
    void move_finished();
    void auto_move();

private:

    Ui::MainWindow *ui;
    QSerialPort port;
    QByteArray ard_data;
    static bool auto_movement;

    QByteArray TCP_data;
    QTcpSocket *sock;
    void create_arduino_command(QByteArray TCP_data);
    void write_to_arduino(QString data);
    QTcpServer * t;

    void establish_TCP_connection();

};

#endif // MAINWINDOW_H
