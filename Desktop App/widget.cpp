#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    found_port = false; // Set to true if the correct port is found

    qDebug() << "There are " << QSerialPortInfo::availablePorts().length() << " ports available.";

    // TODO - set value of Ard_identifier

    foreach (const QSerialPortInfo port_info, QSerialPortInfo::availablePorts()){
        if (port_info.hasProductIdentifier()){
            if (port_info.productIdentifier() == Ard_identifier){
                qDebug() << "Found the correct port";
                found_port = true;
                Ard_port_name = port_info.portName();
            }
        }
    }

    if (found_port){
        Ard.open(QSerialPort::WriteOnly);
        Ard.setBaudRate(QSerialPort::Baud9600);
        Ard.setDataBits(QSerialPort::Data8);
        Ard.setParity(QSerialPort::NoParity);
        Ard.setStopBits(QSerialPort::OneStop);
        Ard.setFlowControl(QSerialPort::NoFlowControl);

        // TODO - properly set up communication
    }
    else {
        qDebug() << "Error - could not find Arduino";
    }


    left_button = ui->leftButton;
    connect(left_button, SIGNAL (pressed()), this, SLOT (leftPressed()));

    right_button = ui->rightButton;
    connect(right_button, SIGNAL (pressed()), this, SLOT (rightPressed()));

    up_button = ui->upButton;
    connect(up_button, SIGNAL (pressed()), this, SLOT (upPressed()));

    down_button = ui->downButton;
    connect(down_button, SIGNAL (pressed()), this, SLOT (downPressed()));

}

Widget::~Widget()
{
    if (Ard.isOpen()){
        Ard.close();
    }
    delete ui;
}

void Widget::write_to_arduino(){

    if (!Ard.isOpen()){
        //QMessageBox::critical(this,"Device Not Found","<font color='red'>The Transmiting Arduino Device is not Found.</font>");
        qDebug() << "Error: Arduino not found";
        return;
    }

    Ard_data.clear();

    Ard_data.push_back(Command);
    Ard.write(Ard_data);
}

void Widget::leftPressed(){
    ui->lineEdit->setText("LEFT BUTTON PRESSED");
    Command = left;
    write_to_arduino();
}

void Widget::rightPressed(){
    ui->lineEdit->setText("RIGHT BUTTON PRESSED");
    Command = right;
    write_to_arduino();
}

void Widget::upPressed(){
    ui->lineEdit->setText("UP BUTTON PRESSED");
    Command = up;
    write_to_arduino();
}

void Widget::downPressed(){
    ui->lineEdit->setText("DOWN BUTTON PRESSED");
    Command = down;
    write_to_arduino();
}
