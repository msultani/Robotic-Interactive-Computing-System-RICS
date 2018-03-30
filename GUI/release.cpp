#include "release.h"
#include "ui_release.h"
#include "functions.cpp"

Release::Release(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Release)
{
    ui->setupUi(this);
}

void Release::countdown(){
    int countdown = 5;
    QString display = QString::number(countdown);
    this->ui->countdownLabel->setText(display);

    while (countdown > 0){
        delay(1000);
        countdown--;
        display = QString::number(countdown);
        this->ui->countdownLabel->setText(display);
    }
}


Release::~Release()
{
    delete ui;
}
