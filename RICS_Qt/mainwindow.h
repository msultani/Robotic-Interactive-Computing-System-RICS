#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "functions.h"

#include <QMainWindow>
#include <QTcpSocket>
#include <QTcpServer>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QPair>

#include <QDebug>
#include <QPushButton>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QEnterEvent>
#include <QDir>
#include <QIODevice>

#include <QCoreApplication>
#include <iostream>

#include <QtCore>
#include <QMessageBox>

#include <QString>
#include <QStringList>
#include <string>
#include <QProcess>

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
    static int rotation_degrees;
    ~MainWindow();
    int countdown = 10;
    static int x_pos;
    static int y_pos;
    static int z_pos;
    static int claw_pos;
    QStringList voice_commands;
    QStringList directional_commands;
    static QVector<QPair<QString, int> > command_queue;


public slots:
    void readTCPData();
    void connection();
    void fetchPressed();
    void commandsPressed();
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
    void invalid_commands(QByteArray TCP_data);

private slots:
    void on_clawLeft_pressed();

    void on_clawRight_pressed();

private:
    QProcess p;
    Ui::MainWindow *ui;
    QSerialPort port;
    QByteArray ard_data;
    static bool auto_movement;
    static bool voice_command_given;
    static QByteArray TCP_data;
    static QString move_direction;

    QTcpSocket *sock;
    void parse_TCP_command(QByteArray TCP_data);
    void write_to_arduino();
    void send_next_command();
    void wait_for_confimation();
    static bool ready_to_send;
    QTcpServer * t;

    void establish_TCP_connection();

};

#endif // MAINWINDOW_H
