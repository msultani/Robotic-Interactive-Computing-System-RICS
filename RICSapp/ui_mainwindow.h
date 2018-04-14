/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>
#include "qhoversensitivebutton.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *startPage;
    QHoverSensitiveButton *commandButton;
    QHoverSensitiveButton *settingButton;
    QLabel *label;
    QLabel *label_2;
    QHoverSensitiveButton *tutorialButton;
    QWidget *movementPage;
    QHoverSensitiveButton *releaseButton;
    QHoverSensitiveButton *backButton_3;
    QHoverSensitiveButton *forwardButton;
    QHoverSensitiveButton *backwardButton;
    QHoverSensitiveButton *upButton;
    QHoverSensitiveButton *leftButton;
    QHoverSensitiveButton *rightButton;
    QHoverSensitiveButton *downButton;
    QLabel *ready_label;
    QHoverSensitiveButton *clawLeft;
    QHoverSensitiveButton *clawRight;
    QLabel *ready_label_2;
    QLabel *ready_label_3;
    QLabel *ready_label_4;
    QLabel *ready_label_5;
    QPushButton *stopButton;
    QPushButton *fetchButton;
    QLabel *voice_label;
    QWidget *settingsPage;
    QHoverSensitiveButton *backButton;
    QHoverSensitiveButton *hoverButton;
    QLabel *label_4;
    QLabel *hover_time_label;
    QHoverSensitiveButton *hover_time_up_button;
    QHoverSensitiveButton *hover_time_down_button;
    QLabel *label_6;
    QPushButton *pushButton_2;
    QHoverSensitiveButton *change_fetch_vals_button;
    QLabel *label_7;
    QLabel *label_5;
    QHoverSensitiveButton *claw_rotation_up_button;
    QHoverSensitiveButton *claw_rotation_down_button;
    QHoverSensitiveButton *move_delay_up_button;
    QHoverSensitiveButton *move_delay_down_button;
    QLabel *label_9;
    QLabel *claw_rotation_label;
    QLabel *move_delay_label;
    QLabel *arm_rotation_label;
    QHoverSensitiveButton *arm_rotation_up_button;
    QLabel *label_10;
    QHoverSensitiveButton *arm_rotation_down_button;
    QWidget *tutorialPage;
    QHoverSensitiveButton *backButton_2;
    QPushButton *pushButton;
    QWidget *countdown;
    QLabel *countdownLabel;
    QLabel *countdownLabel2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(943, 520);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral("background: rgb(67, 83, 106);"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setStyleSheet(QStringLiteral("background: rgba(51, 64, 88, 0%);"));
        startPage = new QWidget();
        startPage->setObjectName(QStringLiteral("startPage"));
        startPage->setStyleSheet(QStringLiteral("background: rgb(67, 83, 106)"));
        commandButton = new QHoverSensitiveButton(startPage);
        commandButton->setObjectName(QStringLiteral("commandButton"));
        commandButton->setGeometry(QRect(230, 80, 451, 151));
        QFont font;
        font.setFamily(QStringLiteral("Arial Rounded MT Bold"));
        font.setPointSize(30);
        font.setBold(true);
        font.setWeight(75);
        commandButton->setFont(font);
        commandButton->setMouseTracking(true);
        commandButton->setStyleSheet(QLatin1String("background: rgba(51, 64, 88, 0%);\n"
"border-style: solid;\n"
"\n"
""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/controls.png"), QSize(), QIcon::Normal, QIcon::Off);
        commandButton->setIcon(icon);
        commandButton->setIconSize(QSize(450, 400));
        settingButton = new QHoverSensitiveButton(startPage);
        settingButton->setObjectName(QStringLiteral("settingButton"));
        settingButton->setGeometry(QRect(520, 270, 171, 161));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial Rounded MT Bold"));
        font1.setPointSize(20);
        settingButton->setFont(font1);
        settingButton->setStyleSheet(QLatin1String("background: rgba(51, 64, 88, 0%);\n"
"border-style: solid;\n"
"\n"
""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        settingButton->setIcon(icon1);
        settingButton->setIconSize(QSize(150, 170));
        label = new QLabel(startPage);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(400, 10, 121, 20));
        QFont font2;
        font2.setFamily(QStringLiteral(".Helvetica Neue DeskInterface"));
        font2.setPointSize(20);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        label->setFont(font2);
        label->setStyleSheet(QLatin1String("font: 20pt \".Helvetica Neue DeskInterface\";\n"
"color: white;"));
        label_2 = new QLabel(startPage);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(420, 40, 81, 20));
        label_2->setFont(font2);
        label_2->setStyleSheet(QLatin1String("font: 20pt \".Helvetica Neue DeskInterface\";\n"
"color: white;"));
        tutorialButton = new QHoverSensitiveButton(startPage);
        tutorialButton->setObjectName(QStringLiteral("tutorialButton"));
        tutorialButton->setGeometry(QRect(230, 270, 171, 171));
        tutorialButton->setFont(font1);
        tutorialButton->setStyleSheet(QLatin1String("background: rgba(51, 64, 88, 0%);\n"
"border-style: solid;\n"
"\n"
""));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/tutorials.png"), QSize(), QIcon::Normal, QIcon::Off);
        tutorialButton->setIcon(icon2);
        tutorialButton->setIconSize(QSize(150, 200));
        stackedWidget->addWidget(startPage);
        movementPage = new QWidget();
        movementPage->setObjectName(QStringLiteral("movementPage"));
        releaseButton = new QHoverSensitiveButton(movementPage);
        releaseButton->setObjectName(QStringLiteral("releaseButton"));
        releaseButton->setGeometry(QRect(720, 370, 162, 102));
        QFont font3;
        font3.setFamily(QStringLiteral("Helvetica"));
        font3.setPointSize(29);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        releaseButton->setFont(font3);
        releaseButton->setStyleSheet(QLatin1String("background-color: rgba(90, 225, 143, 0%);\n"
"border-style: solid;\n"
""));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/retract.png"), QSize(), QIcon::Normal, QIcon::Off);
        releaseButton->setIcon(icon3);
        releaseButton->setIconSize(QSize(120, 120));
        backButton_3 = new QHoverSensitiveButton(movementPage);
        backButton_3->setObjectName(QStringLiteral("backButton_3"));
        backButton_3->setGeometry(QRect(20, 10, 141, 71));
        backButton_3->setStyleSheet(QLatin1String("background-color: rgba(0, 0, 0, 0%);\n"
"border: solid;"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/back.png"), QSize(), QIcon::Normal, QIcon::Off);
        backButton_3->setIcon(icon4);
        backButton_3->setIconSize(QSize(100, 100));
        forwardButton = new QHoverSensitiveButton(movementPage);
        forwardButton->setObjectName(QStringLiteral("forwardButton"));
        forwardButton->setGeometry(QRect(0, 270, 281, 131));
        forwardButton->setStyleSheet(QLatin1String("background-color: rgba(38, 48, 71, 0%);\n"
"font: 29pt \"Helvetica\";\n"
"border: solid;"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/forward.png"), QSize(), QIcon::Normal, QIcon::Off);
        forwardButton->setIcon(icon5);
        forwardButton->setIconSize(QSize(200, 200));
        backwardButton = new QHoverSensitiveButton(movementPage);
        backwardButton->setObjectName(QStringLiteral("backwardButton"));
        backwardButton->setGeometry(QRect(0, 380, 281, 121));
        backwardButton->setStyleSheet(QLatin1String("background-color: rgba(38, 48, 71, 0%);\n"
"font: 29pt \"Helvetica\";\n"
"border: solid;"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/backward.png"), QSize(), QIcon::Normal, QIcon::Off);
        backwardButton->setIcon(icon6);
        backwardButton->setIconSize(QSize(200, 200));
        upButton = new QHoverSensitiveButton(movementPage);
        upButton->setObjectName(QStringLiteral("upButton"));
        upButton->setGeometry(QRect(400, 100, 171, 71));
        upButton->setStyleSheet(QLatin1String("background-color: rgba(38, 48, 71, 0%);\n"
"font: 20pt \"Helvetica\";\n"
"border: solid;"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/images/up.png"), QSize(), QIcon::Normal, QIcon::Off);
        upButton->setIcon(icon7);
        upButton->setIconSize(QSize(120, 120));
        leftButton = new QHoverSensitiveButton(movementPage);
        leftButton->setObjectName(QStringLiteral("leftButton"));
        leftButton->setGeometry(QRect(310, 160, 91, 131));
        leftButton->setStyleSheet(QLatin1String("background-color: rgba(38, 48, 71, 0%);\n"
"font: 20pt \"Helvetica\";\n"
"border: solid;"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/images/left.png"), QSize(), QIcon::Normal, QIcon::Off);
        leftButton->setIcon(icon8);
        leftButton->setIconSize(QSize(100, 120));
        rightButton = new QHoverSensitiveButton(movementPage);
        rightButton->setObjectName(QStringLiteral("rightButton"));
        rightButton->setGeometry(QRect(580, 160, 91, 131));
        rightButton->setStyleSheet(QLatin1String("background-color: rgba(38, 48, 71, 0%);\n"
"font: 20pt \"Helvetica\";\n"
"border: solid;"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/images/right.png"), QSize(), QIcon::Normal, QIcon::Off);
        rightButton->setIcon(icon9);
        rightButton->setIconSize(QSize(100, 120));
        downButton = new QHoverSensitiveButton(movementPage);
        downButton->setObjectName(QStringLiteral("downButton"));
        downButton->setGeometry(QRect(400, 270, 171, 81));
        downButton->setStyleSheet(QLatin1String("background-color: rgba(38, 48, 71, 0%);\n"
"font: 20pt \"Helvetica\";\n"
"border: solid;"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/images/down.png"), QSize(), QIcon::Normal, QIcon::Off);
        downButton->setIcon(icon10);
        downButton->setIconSize(QSize(120, 120));
        ready_label = new QLabel(movementPage);
        ready_label->setObjectName(QStringLiteral("ready_label"));
        ready_label->setGeometry(QRect(140, 0, 711, 31));
        ready_label->setStyleSheet(QLatin1String("qproperty-alignment: AlignCenter;\n"
"font: 20pt \".Helvetica Neue DeskInterface\";\n"
"color: white;\n"
""));
        clawLeft = new QHoverSensitiveButton(movementPage);
        clawLeft->setObjectName(QStringLiteral("clawLeft"));
        clawLeft->setGeometry(QRect(270, 340, 111, 131));
        clawLeft->setStyleSheet(QLatin1String("background-color: rgba(38, 48, 71, 0%);\n"
"font: 29pt \"Helvetica\";\n"
"border: solid;"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/images/away.png"), QSize(), QIcon::Normal, QIcon::Off);
        clawLeft->setIcon(icon11);
        clawLeft->setIconSize(QSize(120, 120));
        clawRight = new QHoverSensitiveButton(movementPage);
        clawRight->setObjectName(QStringLiteral("clawRight"));
        clawRight->setGeometry(QRect(590, 340, 121, 131));
        clawRight->setStyleSheet(QLatin1String("background-color: rgba(38, 48, 71, 0%);\n"
"font: 29pt \"Helvetica\";\n"
"border: solid;\n"
""));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/images/near.png"), QSize(), QIcon::Normal, QIcon::Off);
        clawRight->setIcon(icon12);
        clawRight->setIconSize(QSize(120, 120));
        ready_label_2 = new QLabel(movementPage);
        ready_label_2->setObjectName(QStringLiteral("ready_label_2"));
        ready_label_2->setGeometry(QRect(440, 70, 91, 31));
        ready_label_2->setStyleSheet(QLatin1String("qproperty-alignment: AlignCenter;\n"
"font: 20pt \".Helvetica Neue DeskInterface\";\n"
"color: white;\n"
""));
        ready_label_3 = new QLabel(movementPage);
        ready_label_3->setObjectName(QStringLiteral("ready_label_3"));
        ready_label_3->setGeometry(QRect(680, 210, 91, 31));
        ready_label_3->setStyleSheet(QLatin1String("qproperty-alignment: AlignCenter;\n"
"font: 20pt \".Helvetica Neue DeskInterface\";\n"
"color: white;\n"
""));
        ready_label_4 = new QLabel(movementPage);
        ready_label_4->setObjectName(QStringLiteral("ready_label_4"));
        ready_label_4->setGeometry(QRect(440, 350, 91, 31));
        ready_label_4->setStyleSheet(QLatin1String("qproperty-alignment: AlignCenter;\n"
"font: 20pt \".Helvetica Neue DeskInterface\";\n"
"color: white;\n"
""));
        ready_label_5 = new QLabel(movementPage);
        ready_label_5->setObjectName(QStringLiteral("ready_label_5"));
        ready_label_5->setGeometry(QRect(210, 210, 91, 31));
        ready_label_5->setStyleSheet(QLatin1String("qproperty-alignment: AlignCenter;\n"
"font: 20pt \".Helvetica Neue DeskInterface\";\n"
"color: white;\n"
""));
        stopButton = new QPushButton(movementPage);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        stopButton->setGeometry(QRect(410, 170, 161, 101));
        stopButton->setStyleSheet(QLatin1String("background-color: rgba(90, 225, 143, 0%);\n"
"border: solid;"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/images/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        stopButton->setIcon(icon13);
        stopButton->setIconSize(QSize(150, 100));
        fetchButton = new QPushButton(movementPage);
        fetchButton->setObjectName(QStringLiteral("fetchButton"));
        fetchButton->setGeometry(QRect(730, 250, 141, 101));
        fetchButton->setStyleSheet(QLatin1String("background-color: rgba(90, 225, 143, 0%);\n"
"border-style: solid;\n"
""));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/images/fetch-2.png"), QSize(), QIcon::Normal, QIcon::Off);
        fetchButton->setIcon(icon14);
        fetchButton->setIconSize(QSize(120, 120));
        voice_label = new QLabel(movementPage);
        voice_label->setObjectName(QStringLiteral("voice_label"));
        voice_label->setGeometry(QRect(150, 40, 731, 31));
        voice_label->setStyleSheet(QLatin1String("qproperty-alignment: AlignCenter;\n"
"font: 20pt \".Helvetica Neue DeskInterface\";\n"
"color: white;\n"
""));
        stackedWidget->addWidget(movementPage);
        settingsPage = new QWidget();
        settingsPage->setObjectName(QStringLiteral("settingsPage"));
        settingsPage->setStyleSheet(QStringLiteral("background: rgb(67, 83, 106)"));
        backButton = new QHoverSensitiveButton(settingsPage);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setGeometry(QRect(20, 10, 141, 71));
        backButton->setStyleSheet(QLatin1String("background-color: rgba(0, 0, 0, 0%);\n"
"border: solid;\n"
""));
        backButton->setIcon(icon4);
        backButton->setIconSize(QSize(100, 100));
        hoverButton = new QHoverSensitiveButton(settingsPage);
        hoverButton->setObjectName(QStringLiteral("hoverButton"));
        hoverButton->setGeometry(QRect(20, 190, 141, 71));
        hoverButton->setStyleSheet(QStringLiteral("font: 36pt \".Helvetica Neue DeskInterface\";"));
        label_4 = new QLabel(settingsPage);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(170, 210, 191, 41));
        label_4->setFont(font3);
        label_4->setLayoutDirection(Qt::LeftToRight);
        label_4->setStyleSheet(QLatin1String("qproperty-alignment: AlignCenter;\n"
"font: 29pt \"Helvetica\";\n"
"color: white;"));
        hover_time_label = new QLabel(settingsPage);
        hover_time_label->setObjectName(QStringLiteral("hover_time_label"));
        hover_time_label->setGeometry(QRect(0, 340, 101, 31));
        QFont font4;
        font4.setFamily(QStringLiteral("Helvetica"));
        font4.setPointSize(24);
        font4.setBold(false);
        font4.setItalic(false);
        font4.setWeight(50);
        hover_time_label->setFont(font4);
        hover_time_label->setStyleSheet(QLatin1String("qproperty-alignment: AlignCenter;\n"
"font: 24pt \"Helvetica\";\n"
"color: white;"));
        hover_time_up_button = new QHoverSensitiveButton(settingsPage);
        hover_time_up_button->setObjectName(QStringLiteral("hover_time_up_button"));
        hover_time_up_button->setGeometry(QRect(120, 280, 71, 71));
        hover_time_up_button->setStyleSheet(QLatin1String("background-color: rgb(255, 248, 102);\n"
"font: 30pt \".Helvetica Neue DeskInterface\";\n"
"border: 1px solid black;"));
        hover_time_down_button = new QHoverSensitiveButton(settingsPage);
        hover_time_down_button->setObjectName(QStringLiteral("hover_time_down_button"));
        hover_time_down_button->setGeometry(QRect(120, 360, 71, 71));
        hover_time_down_button->setStyleSheet(QLatin1String("background-color: rgb(29, 241, 240);\n"
"font: 30pt \".Helvetica Neue DeskInterface\";\n"
"border: 1px solid black;"));
        label_6 = new QLabel(settingsPage);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(240, 330, 151, 41));
        label_6->setFont(font3);
        label_6->setLayoutDirection(Qt::LeftToRight);
        label_6->setStyleSheet(QLatin1String("qproperty-alignment: AlignCenter;\n"
"font: 29pt \"Helvetica\";\n"
"color: white;"));
        pushButton_2 = new QPushButton(settingsPage);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(330, 0, 331, 91));
        pushButton_2->setStyleSheet(QLatin1String("background-color: rgba(0,0,0,0%);\n"
"border: solid;\n"
""));
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/images/settings-title.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon15);
        pushButton_2->setIconSize(QSize(100, 100));
        change_fetch_vals_button = new QHoverSensitiveButton(settingsPage);
        change_fetch_vals_button->setObjectName(QStringLiteral("change_fetch_vals_button"));
        change_fetch_vals_button->setGeometry(QRect(450, 90, 161, 71));
        label_7 = new QLabel(settingsPage);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(630, 110, 291, 41));
        label_7->setFont(font3);
        label_7->setLayoutDirection(Qt::LeftToRight);
        label_7->setStyleSheet(QLatin1String("qproperty-alignment: AlignCenter;\n"
"font: 29pt \"Helvetica\";\n"
"color: white;"));
        label_5 = new QLabel(settingsPage);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(630, 190, 291, 41));
        label_5->setFont(font3);
        label_5->setLayoutDirection(Qt::LeftToRight);
        label_5->setStyleSheet(QLatin1String("qproperty-alignment: AlignCenter;\n"
"font: 29pt \"Helvetica\";\n"
"color: white;"));
        claw_rotation_up_button = new QHoverSensitiveButton(settingsPage);
        claw_rotation_up_button->setObjectName(QStringLiteral("claw_rotation_up_button"));
        claw_rotation_up_button->setGeometry(QRect(510, 180, 71, 61));
        claw_rotation_down_button = new QHoverSensitiveButton(settingsPage);
        claw_rotation_down_button->setObjectName(QStringLiteral("claw_rotation_down_button"));
        claw_rotation_down_button->setGeometry(QRect(580, 180, 71, 61));
        move_delay_up_button = new QHoverSensitiveButton(settingsPage);
        move_delay_up_button->setObjectName(QStringLiteral("move_delay_up_button"));
        move_delay_up_button->setGeometry(QRect(510, 370, 71, 61));
        move_delay_down_button = new QHoverSensitiveButton(settingsPage);
        move_delay_down_button->setObjectName(QStringLiteral("move_delay_down_button"));
        move_delay_down_button->setGeometry(QRect(580, 370, 71, 61));
        label_9 = new QLabel(settingsPage);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(650, 380, 251, 41));
        label_9->setFont(font3);
        label_9->setLayoutDirection(Qt::LeftToRight);
        label_9->setStyleSheet(QLatin1String("qproperty-alignment: AlignCenter;\n"
"font: 29pt \"Helvetica\";\n"
"color: white;"));
        claw_rotation_label = new QLabel(settingsPage);
        claw_rotation_label->setObjectName(QStringLiteral("claw_rotation_label"));
        claw_rotation_label->setGeometry(QRect(350, 180, 161, 31));
        claw_rotation_label->setFont(font4);
        claw_rotation_label->setStyleSheet(QLatin1String("qproperty-alignment: AlignCenter;\n"
"font: 24pt \"Helvetica\";\n"
"color: white;"));
        move_delay_label = new QLabel(settingsPage);
        move_delay_label->setObjectName(QStringLiteral("move_delay_label"));
        move_delay_label->setGeometry(QRect(350, 380, 161, 31));
        move_delay_label->setFont(font4);
        move_delay_label->setStyleSheet(QLatin1String("qproperty-alignment: AlignCenter;\n"
"font: 24pt \"Helvetica\";\n"
"color: white;"));
        arm_rotation_label = new QLabel(settingsPage);
        arm_rotation_label->setObjectName(QStringLiteral("arm_rotation_label"));
        arm_rotation_label->setGeometry(QRect(350, 290, 161, 31));
        arm_rotation_label->setFont(font4);
        arm_rotation_label->setStyleSheet(QLatin1String("qproperty-alignment: AlignCenter;\n"
"font: 24pt \"Helvetica\";\n"
"color: white;"));
        arm_rotation_up_button = new QHoverSensitiveButton(settingsPage);
        arm_rotation_up_button->setObjectName(QStringLiteral("arm_rotation_up_button"));
        arm_rotation_up_button->setGeometry(QRect(510, 280, 71, 61));
        label_10 = new QLabel(settingsPage);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(630, 290, 291, 41));
        label_10->setFont(font3);
        label_10->setLayoutDirection(Qt::LeftToRight);
        label_10->setStyleSheet(QLatin1String("qproperty-alignment: AlignCenter;\n"
"font: 29pt \"Helvetica\";\n"
"color: white;"));
        arm_rotation_down_button = new QHoverSensitiveButton(settingsPage);
        arm_rotation_down_button->setObjectName(QStringLiteral("arm_rotation_down_button"));
        arm_rotation_down_button->setGeometry(QRect(580, 280, 71, 61));
        stackedWidget->addWidget(settingsPage);
        tutorialPage = new QWidget();
        tutorialPage->setObjectName(QStringLiteral("tutorialPage"));
        backButton_2 = new QHoverSensitiveButton(tutorialPage);
        backButton_2->setObjectName(QStringLiteral("backButton_2"));
        backButton_2->setGeometry(QRect(12, 12, 151, 61));
        backButton_2->setStyleSheet(QLatin1String("background-color: rgba(0,0,0,0%);\n"
"border: solid;"));
        backButton_2->setIcon(icon4);
        backButton_2->setIconSize(QSize(100, 100));
        pushButton = new QPushButton(tutorialPage);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(160, -20, 731, 541));
        pushButton->setStyleSheet(QLatin1String("background: rgba(0, 0, 0, 0%);\n"
"border-style: solid;\n"
""));
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/images/tutorial-new.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon16);
        pushButton->setIconSize(QSize(600, 600));
        stackedWidget->addWidget(tutorialPage);
        countdown = new QWidget();
        countdown->setObjectName(QStringLiteral("countdown"));
        countdownLabel = new QLabel(countdown);
        countdownLabel->setObjectName(QStringLiteral("countdownLabel"));
        countdownLabel->setGeometry(QRect(180, 90, 601, 151));
        QFont font5;
        font5.setPointSize(150);
        font5.setBold(true);
        font5.setWeight(75);
        countdownLabel->setFont(font5);
        countdownLabel->setStyleSheet(QLatin1String("background: rgb(67, 83, 106);\n"
"qproperty-alignment: AlignCenter;\n"
"color: white;\n"
""));
        countdownLabel2 = new QLabel(countdown);
        countdownLabel2->setObjectName(QStringLiteral("countdownLabel2"));
        countdownLabel2->setGeometry(QRect(180, 240, 611, 151));
        QFont font6;
        font6.setPointSize(50);
        countdownLabel2->setFont(font6);
        countdownLabel2->setStyleSheet(QLatin1String("background: rgb(67, 83, 106);\n"
"qproperty-alignment: AlignCenter;\n"
"color: white;"));
        stackedWidget->addWidget(countdown);

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        commandButton->setText(QString());
        settingButton->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Hover + Hold", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "to Select", nullptr));
        tutorialButton->setText(QString());
        releaseButton->setText(QString());
        backButton_3->setText(QString());
        forwardButton->setText(QString());
        backwardButton->setText(QString());
        upButton->setText(QString());
        leftButton->setText(QString());
        rightButton->setText(QString());
        downButton->setText(QString());
        ready_label->setText(QApplication::translate("MainWindow", "Ready for commands!", nullptr));
        clawLeft->setText(QString());
        clawRight->setText(QString());
        ready_label_2->setText(QApplication::translate("MainWindow", "Rise", nullptr));
        ready_label_3->setText(QApplication::translate("MainWindow", "Right", nullptr));
        ready_label_4->setText(QApplication::translate("MainWindow", "Down", nullptr));
        ready_label_5->setText(QApplication::translate("MainWindow", "Left", nullptr));
        stopButton->setText(QString());
        fetchButton->setText(QString());
        voice_label->setText(QString());
        backButton->setText(QString());
        hoverButton->setText(QApplication::translate("MainWindow", "ON", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Hover Mode", nullptr));
        hover_time_label->setText(QApplication::translate("MainWindow", "3.0 secs", nullptr));
        hover_time_up_button->setText(QApplication::translate("MainWindow", "+", nullptr));
        hover_time_down_button->setText(QApplication::translate("MainWindow", "-", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Hover Time", nullptr));
        pushButton_2->setText(QString());
        change_fetch_vals_button->setText(QString());
        label_7->setText(QApplication::translate("MainWindow", "Set New Fetch Values", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Claw Rotation", nullptr));
        claw_rotation_up_button->setText(QApplication::translate("MainWindow", "+", nullptr));
        claw_rotation_down_button->setText(QApplication::translate("MainWindow", "-", nullptr));
        move_delay_up_button->setText(QApplication::translate("MainWindow", "+", nullptr));
        move_delay_down_button->setText(QApplication::translate("MainWindow", "-", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "Move Delay", nullptr));
        claw_rotation_label->setText(QApplication::translate("MainWindow", "VAL", nullptr));
        move_delay_label->setText(QApplication::translate("MainWindow", " VAL", nullptr));
        arm_rotation_label->setText(QApplication::translate("MainWindow", " VAL", nullptr));
        arm_rotation_up_button->setText(QApplication::translate("MainWindow", "+", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "Arm Rotation", nullptr));
        arm_rotation_down_button->setText(QApplication::translate("MainWindow", "-", nullptr));
        backButton_2->setText(QString());
        pushButton->setText(QString());
        countdownLabel->setText(QApplication::translate("MainWindow", "5", nullptr));
        countdownLabel2->setText(QApplication::translate("MainWindow", "SECONDS REMAINING", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
