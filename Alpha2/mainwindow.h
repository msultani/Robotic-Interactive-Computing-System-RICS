#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int countdown = 10;


public slots:
    void fetchPressed();
    void tutorialPressed();
    void settingsPressed();
    void backPressed();
    void hover_time_up();
    void hover_time_down();
    void changeLabel();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
