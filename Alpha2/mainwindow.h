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
    static MainWindow* GetInstance(QWidget* parent = 0);
    int countdown = 10;

public slots:
    void fetchPressed();
    void tutorialPressed();
    void settingsPressed();
    void backPressed();

private:
    Ui::MainWindow *ui;
    static MainWindow* mainInstance;
};

#endif // MAINWINDOW_H
