#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->stackedWidget->setCurrentIndex(0);

    connect(ui->fetchButton, SIGNAL (pressed()), this, SLOT (fetchPressed()));
    connect(ui->fetchButton, SIGNAL (hovered()), this, SLOT (fetchPressed()));

    connect(ui->settingButton, SIGNAL (pressed()), this, SLOT (settingsPressed()));
    connect(ui->settingButton, SIGNAL (hovered()), this, SLOT (settingsPressed()));

    connect(ui->tutorialButton, SIGNAL (pressed()), this, SLOT (tutorialPressed()));
    connect(ui->tutorialButton, SIGNAL (hovered()), this, SLOT (tutorialPressed()));

    connect(ui->backButton, SIGNAL (pressed()), this, SLOT (backPressed()));
    connect(ui->backButton, SIGNAL (hovered()), this, SLOT (backPressed()));

}

MainWindow* MainWindow::mainInstance = 0;

MainWindow* MainWindow::GetInstance(QWidget *parent)
{
    if(mainInstance == NULL)
    {
        mainInstance = new MainWindow(parent);
    }
    return mainInstance;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::fetchPressed(){
    qDebug() << "Fetch button pressed";
}

void MainWindow::tutorialPressed(){
    qDebug() << "Tutorial button pressed";
}

void MainWindow::settingsPressed(){
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::backPressed(){
    ui->stackedWidget->setCurrentIndex(0);
}
