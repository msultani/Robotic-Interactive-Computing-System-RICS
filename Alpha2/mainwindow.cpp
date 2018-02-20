#include "mainwindow.h"
#include "ui_mainwindow.h"

QSerialPort serial;
QElapsedTimer timer;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    // List of signals and the appropriate slot that they should connect to
    connect(ui->fetchButton, SIGNAL (pressed()), this, SLOT (fetchPressed()));
    connect(ui->fetchButton, SIGNAL (hovered()), this, SLOT (fetchPressed()));

    connect(ui->settingButton, SIGNAL (pressed()), this, SLOT (settingsPressed()));
    connect(ui->settingButton, SIGNAL (hovered()), this, SLOT (settingsPressed()));

    connect(ui->tutorialButton, SIGNAL (pressed()), this, SLOT (tutorialPressed()));
    connect(ui->tutorialButton, SIGNAL (hovered()), this, SLOT (tutorialPressed()));

    connect(ui->backButton, SIGNAL (pressed()), this, SLOT (backPressed()));
    connect(ui->backButton, SIGNAL (hovered()), this, SLOT (backPressed()));
    connect(ui->backButton_2, SIGNAL (pressed()), this, SLOT (backPressed()));
    connect(ui->backButton_2, SIGNAL (hovered()), this, SLOT (backPressed()));
    connect(ui->backButton_3, SIGNAL (pressed()), this, SLOT (backPressed()));
    connect(ui->backButton_3, SIGNAL (hovered()), this, SLOT (backPressed()));

    connect(ui->tutorialButton, SIGNAL (pressed()), this, SLOT (tutorialPressed()));
    connect(ui->tutorialButton, SIGNAL (hovered()), this, SLOT (tutorialPressed()));

    connect(ui->hover_time_up_button, SIGNAL (pressed()), this, SLOT (hover_time_up()));
    connect(ui->hover_time_up_button, SIGNAL (hovered()), this, SLOT (hover_time_up()));

    connect(ui->hover_time_down_button, SIGNAL (pressed()), this, SLOT (hover_time_down()));
    connect(ui->hover_time_down_button, SIGNAL (hovered()), this, SLOT (hover_time_down()));

    connect(ui->hoverButton, SIGNAL (changeLabel()), this, SLOT (changeLabel()));

    connect(ui->upButton, SIGNAL (pressed()), this, SLOT (move_up()));
    connect(ui->upButton, SIGNAL (hovered()), this, SLOT (move_up()));

    connect(ui->downButton, SIGNAL (pressed()), this, SLOT (move_down()));
    connect(ui->downButton, SIGNAL (hovered()), this, SLOT (move_down()));

    connect(ui->leftButton, SIGNAL (pressed()), this, SLOT (move_left()));
    connect(ui->leftButton, SIGNAL (hovered()), this, SLOT (move_left()));

    connect(ui->rightButton, SIGNAL (pressed()), this, SLOT (move_right()));
    connect(ui->rightButton, SIGNAL (hovered()), this, SLOT (move_right()));

    connect(ui->forwardButton, SIGNAL (pressed()), this, SLOT (move_forward()));
    connect(ui->forwardButton, SIGNAL (hovered()), this, SLOT (move_forward()));

    connect(ui->backwardButton, SIGNAL (pressed()), this, SLOT (move_backward()));
    connect(ui->backwardButton, SIGNAL (hovered()), this, SLOT (move_backward()));


    serial.setPortName("COM21");

        serial.setBaudRate(QSerialPort::Baud115200);
        serial.setDataBits(QSerialPort::Data8);
        serial.setParity(QSerialPort::NoParity);
        serial.setStopBits(QSerialPort::OneStop);
        serial.setFlowControl(QSerialPort::NoFlowControl);

        serial.open(QIODevice::ReadWrite);

        if (serial.isOpen()){
            qDebug() << "OPEN!!!";
        }
        else{
            qDebug() << "Serial port could not open";
            qDebug() << serial.errorString();
        }


}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::fetchPressed(){
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::tutorialPressed(){
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::settingsPressed(){
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::backPressed(){
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::hover_time_down(){

    QHoverSensitiveButton::hoverTime -= 1000;

    if (QHoverSensitiveButton::hoverTime <= 0){
        QHoverSensitiveButton::hoverTime = 0;
    }
    QString display = QString::number(QHoverSensitiveButton::hoverTime / 1000) + " secs";
    ui->hover_time_label->setText(display);
}

void MainWindow::hover_time_up(){
    QHoverSensitiveButton::hoverTime += 1000;

    QString display = QString::number(QHoverSensitiveButton::hoverTime / 1000) + " secs";
    ui->hover_time_label->setText(display);
}

void MainWindow::changeLabel(){
    if (ui->label->text() == "Hover + Hold"){
        ui->label->setText("Press Button");
    }
    else{
        ui->label->setText("Hover + Hold");
    }
}

void MainWindow::move_up(){
    qDebug() << "Move up";
}
void MainWindow::move_down(){
    qDebug() << "Move down";
}
void MainWindow::move_left(){
    qDebug() << "Move left";
}
void MainWindow::move_right(){
    qDebug() << "Move right";
}
void MainWindow::move_forward(){
    qDebug() << "Move forward";
}
void MainWindow::move_backward(){
    qDebug() << "Move backward";
}
