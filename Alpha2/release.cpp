#include "release.h"
#include "ui_release.h"
#include "functions.cpp"

Release::Release(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Release)
{
    ui->setupUi(this);
    qDebug() << "HERE";
    int countdown = 5;
    QString display = QString::number(countdown);
    ui->countdownLabel->setText(display);

    while (countdown > 0){
        qDebug() << "loop";
        delay(1000);
        countdown--;
        ui->countdownLabel->setText(display);
    }
}


Release::~Release()
{
    delete ui;
}
