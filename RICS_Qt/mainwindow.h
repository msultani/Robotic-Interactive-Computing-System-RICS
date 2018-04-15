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
#include <QSettings>

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
    static int target_x;
    static int target_y;
    static int target_z;
    static int claw_pos;
    static int target_claw;
    static int arm_movement_degrees;
    static int claw_movement_degrees;
    static int move_delay;
    static int fetch_x;
    static int fetch_y;
    static int fetch_z;
    static int fetch_claw;
    QStringList voice_commands;
    QStringList directional_commands;
    static QVector<QPair<QString, int> > command_queue;
    void reset_targets();


public slots:
    void readTCPData();
    void connection();
    void fetchPressed();
    void backPressed();
    void tutorialPressed();
    void settingsPressed();
    void hover_time_up();
    void hover_time_down();
    void move_delay_up();
    void move_delay_down();
    void arm_movement_degrees_up();
    void arm_movement_degrees_down();
    void claw_movement_degrees_up();
    void claw_movement_degrees_down();
    void changeLabel();
    void hoverButtonEntered();
    void toggle_change_to_fetch_vals();
    //void hover_pressed();

    void move_up();
    void move_backward();
    void move_down();
    void move_forward();
    void move_left();
    void move_right();
    void move_finished();
    void invalid_commands(QByteArray TCP_data);
    void message_too_long_error();
    void parsing_error();
    void received_confimation();
    void stopPressed();

private slots:
    void on_clawLeft_pressed();

    void on_clawRight_pressed();


private:
    QProcess p;
    Ui::MainWindow *ui;
    QSerialPort port;
    QByteArray ard_data;
    static bool voice_command_given;
    static QByteArray TCP_data;
    static QString move_direction;
    static bool change_hover_vals;

    QTcpSocket *sock;
    void parse_TCP_command(QByteArray TCP_data);
    void write_to_arduino();
    void send_next_command();
    static bool ready_to_send;
    QTcpServer * t;

    void establish_TCP_connection();

    void read_settings();
    void write_settings();

};

#endif // MAINWINDOW_H
