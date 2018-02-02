#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

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
    delete ui;
}

void Widget::leftPressed(){
    ui->lineEdit->setText("LEFT BUTTON PRESSED");
}

void Widget::rightPressed(){
    ui->lineEdit->setText("RIGHT BUTTON PRESSED");
}

void Widget::upPressed(){
    ui->lineEdit->setText("UP BUTTON PRESSED");
}

void Widget::downPressed(){
    ui->lineEdit->setText("DOWN BUTTON PRESSED");
}
