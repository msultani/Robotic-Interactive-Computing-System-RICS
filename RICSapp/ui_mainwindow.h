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
    QHoverSensitiveButton *backButton_3;
    QPushButton *pushButton_3;
    QWidget *movementPage;
    QHoverSensitiveButton *releaseButton;
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
    QHoverSensitiveButton *stopButton;
    QHoverSensitiveButton *fetchButton;
    QLabel *voice_label;
    QHoverSensitiveButton *tutorialButton;
    QHoverSensitiveButton *settingButton;
    QLabel *ready_label_6;
    QLabel *ready_label_7;
    QLabel *redDot;
    QLabel *no_red_dot;
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
    QHoverSensitiveButton *settingsTutorial;
    QLabel *label_8;
    QHoverSensitiveButton *reset_button;
    QWidget *tutorialPage;
    QHoverSensitiveButton *backButton_2;
    QPushButton *pushButton;
    QWidget *countdown;
    QLabel *countdownLabel;
    QLabel *countdownLabel2;
    QHoverSensitiveButton *retract_cancel_button;

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
        backButton_3 = new QHoverSensitiveButton(startPage);
        backButton_3->setObjectName(QStringLiteral("backButton_3"));
        backButton_3->setGeometry(QRect(730, 10, 51, 51));
        backButton_3->setStyleSheet(QLatin1String("background-color: rgba(0, 0, 0, 0%);\n"
"border: solid;\n"
""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/X.png"), QSize(), QIcon::Normal, QIcon::Off);
        backButton_3->setIcon(icon);
        backButton_3->setIconSize(QSize(40, 40));
        pushButton_3 = new QPushButton(startPage);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(110, 0, 661, 491));
        pushButton_3->setStyleSheet(QLatin1String("background-color: rgba(0, 0, 0, 0%);\n"
"border: solid;\n"
""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/settings-w-reset.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon1);
        pushButton_3->setIconSize(QSize(600, 500));
        stackedWidget->addWidget(startPage);
        pushButton_3->raise();
        backButton_3->raise();
        movementPage = new QWidget();
        movementPage->setObjectName(QStringLiteral("movementPage"));
        releaseButton = new QHoverSensitiveButton(movementPage);
        releaseButton->setObjectName(QStringLiteral("releaseButton"));
        releaseButton->setGeometry(QRect(750, 390, 162, 102));
        QFont font;
        font.setFamily(QStringLiteral("Helvetica"));
        font.setPointSize(29);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        releaseButton->setFont(font);
        releaseButton->setStyleSheet(QLatin1String("background-color: rgba(90, 225, 143, 0%);\n"
"border-style: solid;\n"
""));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/retract.png"), QSize(), QIcon::Normal, QIcon::Off);
        releaseButton->setIcon(icon2);
        releaseButton->setIconSize(QSize(120, 120));
        forwardButton = new QHoverSensitiveButton(movementPage);
        forwardButton->setObjectName(QStringLiteral("forwardButton"));
        forwardButton->setGeometry(QRect(0, 280, 251, 101));
        forwardButton->setStyleSheet(QLatin1String("background-color: rgba(38, 48, 71, 0%);\n"
"font: 29pt \"Helvetica\";\n"
"border: solid;"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/forward.png"), QSize(), QIcon::Normal, QIcon::Off);
        forwardButton->setIcon(icon3);
        forwardButton->setIconSize(QSize(200, 200));
        backwardButton = new QHoverSensitiveButton(movementPage);
        backwardButton->setObjectName(QStringLiteral("backwardButton"));
        backwardButton->setGeometry(QRect(0, 390, 251, 101));
        backwardButton->setStyleSheet(QLatin1String("background-color: rgba(38, 48, 71, 0%);\n"
"font: 29pt \"Helvetica\";\n"
"border: solid;"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/backward.png"), QSize(), QIcon::Normal, QIcon::Off);
        backwardButton->setIcon(icon4);
        backwardButton->setIconSize(QSize(200, 200));
        upButton = new QHoverSensitiveButton(movementPage);
        upButton->setObjectName(QStringLiteral("upButton"));
        upButton->setGeometry(QRect(400, 100, 171, 71));
        upButton->setStyleSheet(QLatin1String("background-color: rgba(38, 48, 71, 0%);\n"
"font: 20pt \"Helvetica\";\n"
"border: solid;"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/up.png"), QSize(), QIcon::Normal, QIcon::Off);
        upButton->setIcon(icon5);
        upButton->setIconSize(QSize(120, 120));
        leftButton = new QHoverSensitiveButton(movementPage);
        leftButton->setObjectName(QStringLiteral("leftButton"));
        leftButton->setGeometry(QRect(310, 160, 91, 131));
        leftButton->setStyleSheet(QLatin1String("background-color: rgba(38, 48, 71, 0%);\n"
"font: 20pt \"Helvetica\";\n"
"border: solid;"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/left.png"), QSize(), QIcon::Normal, QIcon::Off);
        leftButton->setIcon(icon6);
        leftButton->setIconSize(QSize(100, 120));
        rightButton = new QHoverSensitiveButton(movementPage);
        rightButton->setObjectName(QStringLiteral("rightButton"));
        rightButton->setGeometry(QRect(570, 160, 91, 131));
        rightButton->setStyleSheet(QLatin1String("background-color: rgba(38, 48, 71, 0%);\n"
"font: 20pt \"Helvetica\";\n"
"border: solid;"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/images/right.png"), QSize(), QIcon::Normal, QIcon::Off);
        rightButton->setIcon(icon7);
        rightButton->setIconSize(QSize(100, 120));
        downButton = new QHoverSensitiveButton(movementPage);
        downButton->setObjectName(QStringLiteral("downButton"));
        downButton->setGeometry(QRect(400, 260, 171, 71));
        downButton->setStyleSheet(QLatin1String("background-color: rgba(38, 48, 71, 0%);\n"
"font: 20pt \"Helvetica\";\n"
"border: solid;"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/images/down.png"), QSize(), QIcon::Normal, QIcon::Off);
        downButton->setIcon(icon8);
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
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/images/away.png"), QSize(), QIcon::Normal, QIcon::Off);
        clawLeft->setIcon(icon9);
        clawLeft->setIconSize(QSize(120, 120));
        clawRight = new QHoverSensitiveButton(movementPage);
        clawRight->setObjectName(QStringLiteral("clawRight"));
        clawRight->setGeometry(QRect(590, 340, 121, 131));
        clawRight->setStyleSheet(QLatin1String("background-color: rgba(38, 48, 71, 0%);\n"
"font: 29pt \"Helvetica\";\n"
"border: solid;\n"
""));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/images/near.png"), QSize(), QIcon::Normal, QIcon::Off);
        clawRight->setIcon(icon10);
        clawRight->setIconSize(QSize(120, 120));
        ready_label_2 = new QLabel(movementPage);
        ready_label_2->setObjectName(QStringLiteral("ready_label_2"));
        ready_label_2->setGeometry(QRect(440, 60, 91, 31));
        ready_label_2->setStyleSheet(QLatin1String("qproperty-alignment: AlignCenter;\n"
"font: 20pt \".Helvetica Neue DeskInterface\";\n"
"color: white;\n"
""));
        ready_label_3 = new QLabel(movementPage);
        ready_label_3->setObjectName(QStringLiteral("ready_label_3"));
        ready_label_3->setGeometry(QRect(680, 210, 61, 31));
        ready_label_3->setStyleSheet(QLatin1String("qproperty-alignment: AlignCenter;\n"
"font: 20pt \".Helvetica Neue DeskInterface\";\n"
"color: white;\n"
""));
        ready_label_4 = new QLabel(movementPage);
        ready_label_4->setObjectName(QStringLiteral("ready_label_4"));
        ready_label_4->setGeometry(QRect(440, 350, 91, 21));
        ready_label_4->setStyleSheet(QLatin1String("qproperty-alignment: AlignCenter;\n"
"font: 20pt \".Helvetica Neue DeskInterface\";\n"
"color: white;\n"
""));
        ready_label_5 = new QLabel(movementPage);
        ready_label_5->setObjectName(QStringLiteral("ready_label_5"));
        ready_label_5->setGeometry(QRect(240, 210, 61, 31));
        ready_label_5->setStyleSheet(QLatin1String("qproperty-alignment: AlignCenter;\n"
"font: 20pt \".Helvetica Neue DeskInterface\";\n"
"color: white;\n"
""));
        stopButton = new QHoverSensitiveButton(movementPage);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        stopButton->setGeometry(QRect(400, 170, 171, 91));
        stopButton->setStyleSheet(QLatin1String("background-color: rgba(90, 225, 143, 0%);\n"
"border: solid;"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/images/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        stopButton->setIcon(icon11);
        stopButton->setIconSize(QSize(150, 100));
        fetchButton = new QHoverSensitiveButton(movementPage);
        fetchButton->setObjectName(QStringLiteral("fetchButton"));
        fetchButton->setGeometry(QRect(760, 280, 141, 101));
        fetchButton->setStyleSheet(QLatin1String("background-color: rgba(90, 225, 143, 0%);\n"
"border-style: solid;\n"
""));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/images/extend.png"), QSize(), QIcon::Normal, QIcon::Off);
        fetchButton->setIcon(icon12);
        fetchButton->setIconSize(QSize(120, 120));
        voice_label = new QLabel(movementPage);
        voice_label->setObjectName(QStringLiteral("voice_label"));
        voice_label->setGeometry(QRect(20, 80, 211, 151));
        voice_label->setStyleSheet(QLatin1String("qproperty-alignment: AlignCenter;\n"
"font: 20pt \".Helvetica Neue DeskInterface\";\n"
"color: white;\n"
""));
        tutorialButton = new QHoverSensitiveButton(movementPage);
        tutorialButton->setObjectName(QStringLiteral("tutorialButton"));
        tutorialButton->setGeometry(QRect(850, 0, 61, 101));
        tutorialButton->setStyleSheet(QLatin1String("background-color: rgba(183, 183, 183, 0);\n"
"border: solid;"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/images/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        tutorialButton->setIcon(icon13);
        tutorialButton->setIconSize(QSize(80, 60));
        settingButton = new QHoverSensitiveButton(movementPage);
        settingButton->setObjectName(QStringLiteral("settingButton"));
        settingButton->setGeometry(QRect(840, 100, 81, 91));
        settingButton->setStyleSheet(QLatin1String("background-color: rgba(183, 183, 183, 0%);\n"
"border: solid;"));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/images/gear.png"), QSize(), QIcon::Normal, QIcon::Off);
        settingButton->setIcon(icon14);
        settingButton->setIconSize(QSize(80, 80));
        ready_label_6 = new QLabel(movementPage);
        ready_label_6->setObjectName(QStringLiteral("ready_label_6"));
        ready_label_6->setGeometry(QRect(280, 470, 91, 21));
        ready_label_6->setStyleSheet(QLatin1String("qproperty-alignment: AlignCenter;\n"
"font: 20pt \".Helvetica Neue DeskInterface\";\n"
"color: white;\n"
""));
        ready_label_7 = new QLabel(movementPage);
        ready_label_7->setObjectName(QStringLiteral("ready_label_7"));
        ready_label_7->setGeometry(QRect(610, 470, 91, 21));
        ready_label_7->setStyleSheet(QLatin1String("qproperty-alignment: AlignCenter;\n"
"font: 20pt \".Helvetica Neue DeskInterface\";\n"
"color: white;\n"
""));
        redDot = new QLabel(movementPage);
        redDot->setObjectName(QStringLiteral("redDot"));
        redDot->setGeometry(QRect(10, 0, 41, 51));
        redDot->setPixmap(QPixmap(QString::fromUtf8(":/images/red-dot.png")));
        no_red_dot = new QLabel(movementPage);
        no_red_dot->setObjectName(QStringLiteral("no_red_dot"));
        no_red_dot->setGeometry(QRect(10, 0, 41, 51));
        no_red_dot->setPixmap(QPixmap(QString::fromUtf8(":/images/no-red-dot.png")));
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
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/images/back.png"), QSize(), QIcon::Normal, QIcon::Off);
        backButton->setIcon(icon15);
        backButton->setIconSize(QSize(100, 100));
        hoverButton = new QHoverSensitiveButton(settingsPage);
        hoverButton->setObjectName(QStringLiteral("hoverButton"));
        hoverButton->setGeometry(QRect(60, 290, 141, 71));
        hoverButton->setStyleSheet(QLatin1String("background-color: rgba(29, 241, 240, 0%);\n"
"font: 30pt \".Helvetica Neue DeskInterface\";\n"
"border: solid"));
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/images/off.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon16.addFile(QStringLiteral(":/images/on.png"), QSize(), QIcon::Normal, QIcon::On);
        hoverButton->setIcon(icon16);
        hoverButton->setIconSize(QSize(100, 100));
        label_4 = new QLabel(settingsPage);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(230, 300, 181, 41));
        label_4->setFont(font);
        label_4->setLayoutDirection(Qt::LeftToRight);
        label_4->setStyleSheet(QLatin1String("qproperty-alignment: AlignCenter;\n"
"font: 29pt \"Helvetica\";\n"
"color: white;"));
        hover_time_label = new QLabel(settingsPage);
        hover_time_label->setObjectName(QStringLiteral("hover_time_label"));
        hover_time_label->setGeometry(QRect(10, 420, 111, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Helvetica"));
        font1.setPointSize(24);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        hover_time_label->setFont(font1);
        hover_time_label->setStyleSheet(QLatin1String("qproperty-alignment: AlignCenter;\n"
"font: 24pt \"Helvetica\";\n"
"color: white;"));
        hover_time_up_button = new QHoverSensitiveButton(settingsPage);
        hover_time_up_button->setObjectName(QStringLiteral("hover_time_up_button"));
        hover_time_up_button->setGeometry(QRect(130, 370, 71, 61));
        hover_time_up_button->setStyleSheet(QLatin1String("background-color: rgba(255, 248, 102, 0%);\n"
"font: 30pt \".Helvetica Neue DeskInterface\";\n"
"border: solid;"));
        QIcon icon17;
        icon17.addFile(QStringLiteral(":/images/plus.png"), QSize(), QIcon::Normal, QIcon::Off);
        hover_time_up_button->setIcon(icon17);
        hover_time_up_button->setIconSize(QSize(60, 60));
        hover_time_down_button = new QHoverSensitiveButton(settingsPage);
        hover_time_down_button->setObjectName(QStringLiteral("hover_time_down_button"));
        hover_time_down_button->setGeometry(QRect(130, 430, 71, 61));
        hover_time_down_button->setStyleSheet(QLatin1String("background-color: rgba(29, 241, 240, 0%);\n"
"font: 30pt \".Helvetica Neue DeskInterface\";\n"
"border: solid"));
        QIcon icon18;
        icon18.addFile(QStringLiteral(":/images/minus.png"), QSize(), QIcon::Normal, QIcon::Off);
        hover_time_down_button->setIcon(icon18);
        hover_time_down_button->setIconSize(QSize(60, 60));
        label_6 = new QLabel(settingsPage);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(240, 420, 151, 41));
        label_6->setFont(font);
        label_6->setLayoutDirection(Qt::LeftToRight);
        label_6->setStyleSheet(QLatin1String("qproperty-alignment: AlignCenter;\n"
"font: 29pt \"Helvetica\";\n"
"color: white;"));
        pushButton_2 = new QPushButton(settingsPage);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(380, 0, 221, 91));
        pushButton_2->setStyleSheet(QLatin1String("background-color: rgba(0,0,0,0%);\n"
"border: solid;\n"
""));
        QIcon icon19;
        icon19.addFile(QStringLiteral(":/images/settings-title.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon19);
        pushButton_2->setIconSize(QSize(150, 100));
        change_fetch_vals_button = new QHoverSensitiveButton(settingsPage);
        change_fetch_vals_button->setObjectName(QStringLiteral("change_fetch_vals_button"));
        change_fetch_vals_button->setGeometry(QRect(60, 130, 141, 71));
        change_fetch_vals_button->setStyleSheet(QLatin1String("background-color: rgba(29, 241, 240, 0%);\n"
"font: 30pt \".Helvetica Neue DeskInterface\";\n"
"border: solid"));
        change_fetch_vals_button->setIcon(icon16);
        change_fetch_vals_button->setIconSize(QSize(100, 100));
        label_7 = new QLabel(settingsPage);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(220, 140, 201, 61));
        label_7->setFont(font);
        label_7->setLayoutDirection(Qt::LeftToRight);
        label_7->setStyleSheet(QLatin1String("qproperty-alignment: AlignCenter;\n"
"font: 29pt \"Helvetica\";\n"
"color: white;"));
        label_5 = new QLabel(settingsPage);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(680, 120, 221, 41));
        label_5->setFont(font);
        label_5->setLayoutDirection(Qt::LeftToRight);
        label_5->setStyleSheet(QLatin1String("qproperty-alignment: AlignCenter;\n"
"font: 29pt \"Helvetica\";\n"
"color: white;"));
        claw_rotation_up_button = new QHoverSensitiveButton(settingsPage);
        claw_rotation_up_button->setObjectName(QStringLiteral("claw_rotation_up_button"));
        claw_rotation_up_button->setGeometry(QRect(600, 90, 71, 61));
        claw_rotation_up_button->setStyleSheet(QLatin1String("background-color: rgba(29, 241, 240, 0%);\n"
"font: 30pt \".Helvetica Neue DeskInterface\";\n"
"border: solid"));
        claw_rotation_up_button->setIcon(icon17);
        claw_rotation_up_button->setIconSize(QSize(60, 60));
        claw_rotation_down_button = new QHoverSensitiveButton(settingsPage);
        claw_rotation_down_button->setObjectName(QStringLiteral("claw_rotation_down_button"));
        claw_rotation_down_button->setGeometry(QRect(600, 150, 71, 61));
        claw_rotation_down_button->setStyleSheet(QLatin1String("background-color: rgba(29, 241, 240, 0%);\n"
"font: 30pt \".Helvetica Neue DeskInterface\";\n"
"border: solid"));
        claw_rotation_down_button->setIcon(icon18);
        claw_rotation_down_button->setIconSize(QSize(71, 61));
        move_delay_up_button = new QHoverSensitiveButton(settingsPage);
        move_delay_up_button->setObjectName(QStringLiteral("move_delay_up_button"));
        move_delay_up_button->setGeometry(QRect(600, 370, 71, 61));
        move_delay_up_button->setStyleSheet(QLatin1String("background-color: rgba(29, 241, 240, 0%);\n"
"font: 30pt \".Helvetica Neue DeskInterface\";\n"
"border: solid"));
        move_delay_up_button->setIcon(icon17);
        move_delay_up_button->setIconSize(QSize(60, 60));
        move_delay_down_button = new QHoverSensitiveButton(settingsPage);
        move_delay_down_button->setObjectName(QStringLiteral("move_delay_down_button"));
        move_delay_down_button->setGeometry(QRect(600, 430, 71, 61));
        move_delay_down_button->setStyleSheet(QLatin1String("background-color: rgba(29, 241, 240, 0%);\n"
"font: 30pt \".Helvetica Neue DeskInterface\";\n"
"border: solid"));
        move_delay_down_button->setIcon(icon18);
        move_delay_down_button->setIconSize(QSize(60, 60));
        label_9 = new QLabel(settingsPage);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(700, 410, 171, 41));
        label_9->setFont(font);
        label_9->setLayoutDirection(Qt::LeftToRight);
        label_9->setStyleSheet(QLatin1String("qproperty-alignment: AlignCenter;\n"
"font: 29pt \"Helvetica\";\n"
"color: white;"));
        claw_rotation_label = new QLabel(settingsPage);
        claw_rotation_label->setObjectName(QStringLiteral("claw_rotation_label"));
        claw_rotation_label->setGeometry(QRect(460, 120, 131, 31));
        claw_rotation_label->setFont(font1);
        claw_rotation_label->setStyleSheet(QLatin1String("qproperty-alignment: AlignCenter;\n"
"font: 24pt \"Helvetica\";\n"
"color: white;"));
        move_delay_label = new QLabel(settingsPage);
        move_delay_label->setObjectName(QStringLiteral("move_delay_label"));
        move_delay_label->setGeometry(QRect(460, 420, 131, 31));
        move_delay_label->setFont(font1);
        move_delay_label->setStyleSheet(QLatin1String("qproperty-alignment: AlignCenter;\n"
"font: 24pt \"Helvetica\";\n"
"color: white;"));
        arm_rotation_label = new QLabel(settingsPage);
        arm_rotation_label->setObjectName(QStringLiteral("arm_rotation_label"));
        arm_rotation_label->setGeometry(QRect(460, 270, 131, 31));
        arm_rotation_label->setFont(font1);
        arm_rotation_label->setStyleSheet(QLatin1String("qproperty-alignment: AlignCenter;\n"
"font: 24pt \"Helvetica\";\n"
"color: white;"));
        arm_rotation_up_button = new QHoverSensitiveButton(settingsPage);
        arm_rotation_up_button->setObjectName(QStringLiteral("arm_rotation_up_button"));
        arm_rotation_up_button->setGeometry(QRect(600, 230, 71, 61));
        arm_rotation_up_button->setStyleSheet(QLatin1String("background-color: rgba(29, 241, 240, 0%);\n"
"font: 30pt \".Helvetica Neue DeskInterface\";\n"
"border: solid"));
        arm_rotation_up_button->setIcon(icon17);
        arm_rotation_up_button->setIconSize(QSize(60, 60));
        label_10 = new QLabel(settingsPage);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(690, 270, 191, 41));
        label_10->setFont(font);
        label_10->setLayoutDirection(Qt::LeftToRight);
        label_10->setStyleSheet(QLatin1String("qproperty-alignment: AlignCenter;\n"
"font: 29pt \"Helvetica\";\n"
"color: white;"));
        arm_rotation_down_button = new QHoverSensitiveButton(settingsPage);
        arm_rotation_down_button->setObjectName(QStringLiteral("arm_rotation_down_button"));
        arm_rotation_down_button->setGeometry(QRect(600, 290, 71, 61));
        arm_rotation_down_button->setStyleSheet(QLatin1String("background-color: rgba(29, 241, 240, 0%);\n"
"font: 30pt \".Helvetica Neue DeskInterface\";\n"
"border: solid"));
        arm_rotation_down_button->setIcon(icon18);
        arm_rotation_down_button->setIconSize(QSize(60, 60));
        settingsTutorial = new QHoverSensitiveButton(settingsPage);
        settingsTutorial->setObjectName(QStringLiteral("settingsTutorial"));
        settingsTutorial->setGeometry(QRect(840, 10, 81, 81));
        settingsTutorial->setStyleSheet(QLatin1String("background-color: rgba(29, 241, 240, 0%);\n"
"font: 30pt \".Helvetica Neue DeskInterface\";\n"
"border: solid"));
        settingsTutorial->setIcon(icon13);
        settingsTutorial->setIconSize(QSize(80, 60));
        label_8 = new QLabel(settingsPage);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(220, 230, 201, 41));
        label_8->setFont(font);
        label_8->setLayoutDirection(Qt::LeftToRight);
        label_8->setStyleSheet(QLatin1String("qproperty-alignment: AlignCenter;\n"
"font: 29pt \"Helvetica\";\n"
"color: white;"));
        reset_button = new QHoverSensitiveButton(settingsPage);
        reset_button->setObjectName(QStringLiteral("reset_button"));
        reset_button->setGeometry(QRect(60, 210, 141, 71));
        reset_button->setStyleSheet(QLatin1String("background-color: rgba(29, 241, 240, 0%);\n"
"font: 30pt \".Helvetica Neue DeskInterface\";\n"
"border: solid"));
        QIcon icon20;
        icon20.addFile(QStringLiteral(":/images/reset.png"), QSize(), QIcon::Normal, QIcon::Off);
        reset_button->setIcon(icon20);
        reset_button->setIconSize(QSize(100, 100));
        stackedWidget->addWidget(settingsPage);
        tutorialPage = new QWidget();
        tutorialPage->setObjectName(QStringLiteral("tutorialPage"));
        backButton_2 = new QHoverSensitiveButton(tutorialPage);
        backButton_2->setObjectName(QStringLiteral("backButton_2"));
        backButton_2->setGeometry(QRect(730, 10, 71, 61));
        backButton_2->setStyleSheet(QLatin1String("background-color: rgba(0,0,0,0%);\n"
"border: solid;"));
        backButton_2->setIcon(icon);
        backButton_2->setIconSize(QSize(40, 40));
        pushButton = new QPushButton(tutorialPage);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(130, 20, 671, 461));
        pushButton->setStyleSheet(QLatin1String("background: rgba(0, 0, 0, 0%);\n"
"border-style: solid;\n"
""));
        QIcon icon21;
        icon21.addFile(QStringLiteral(":/images/tutorial_new.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon21);
        pushButton->setIconSize(QSize(600, 500));
        stackedWidget->addWidget(tutorialPage);
        pushButton->raise();
        backButton_2->raise();
        countdown = new QWidget();
        countdown->setObjectName(QStringLiteral("countdown"));
        countdownLabel = new QLabel(countdown);
        countdownLabel->setObjectName(QStringLiteral("countdownLabel"));
        countdownLabel->setGeometry(QRect(180, 90, 601, 151));
        QFont font2;
        font2.setPointSize(150);
        font2.setBold(true);
        font2.setWeight(75);
        countdownLabel->setFont(font2);
        countdownLabel->setStyleSheet(QLatin1String("background: rgb(67, 83, 106);\n"
"qproperty-alignment: AlignCenter;\n"
"color: white;\n"
""));
        countdownLabel2 = new QLabel(countdown);
        countdownLabel2->setObjectName(QStringLiteral("countdownLabel2"));
        countdownLabel2->setGeometry(QRect(180, 240, 611, 151));
        QFont font3;
        font3.setPointSize(50);
        countdownLabel2->setFont(font3);
        countdownLabel2->setStyleSheet(QLatin1String("background: rgb(67, 83, 106);\n"
"qproperty-alignment: AlignCenter;\n"
"color: white;"));
        retract_cancel_button = new QHoverSensitiveButton(countdown);
        retract_cancel_button->setObjectName(QStringLiteral("retract_cancel_button"));
        retract_cancel_button->setGeometry(QRect(380, 360, 211, 118));
        retract_cancel_button->setIcon(icon11);
        retract_cancel_button->setIconSize(QSize(205, 125));
        stackedWidget->addWidget(countdown);

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        backButton_3->setText(QString());
        pushButton_3->setText(QString());
        releaseButton->setText(QString());
        forwardButton->setText(QString());
        backwardButton->setText(QString());
        upButton->setText(QString());
        leftButton->setText(QString());
        rightButton->setText(QString());
        downButton->setText(QString());
        ready_label->setText(QApplication::translate("MainWindow", "Voice Commands Deactivated", nullptr));
        clawLeft->setText(QString());
        clawRight->setText(QString());
        ready_label_2->setText(QApplication::translate("MainWindow", "Rise", nullptr));
        ready_label_3->setText(QApplication::translate("MainWindow", "Right", nullptr));
        ready_label_4->setText(QApplication::translate("MainWindow", "Down", nullptr));
        ready_label_5->setText(QApplication::translate("MainWindow", "Left", nullptr));
        stopButton->setText(QString());
        fetchButton->setText(QString());
        voice_label->setText(QString());
        tutorialButton->setText(QString());
        settingButton->setText(QString());
        ready_label_6->setText(QApplication::translate("MainWindow", "Away", nullptr));
        ready_label_7->setText(QApplication::translate("MainWindow", "Near", nullptr));
        redDot->setText(QString());
        no_red_dot->setText(QString());
        backButton->setText(QString());
        hoverButton->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "Hover Mode", nullptr));
        hover_time_label->setText(QApplication::translate("MainWindow", "3.0 secs", nullptr));
        hover_time_up_button->setText(QString());
        hover_time_down_button->setText(QString());
        label_6->setText(QApplication::translate("MainWindow", "Hover Time", nullptr));
        pushButton_2->setText(QString());
        change_fetch_vals_button->setText(QString());
        label_7->setText(QApplication::translate("MainWindow", "Save Current\n"
"Position", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Claw Rotation", nullptr));
        claw_rotation_up_button->setText(QString());
        claw_rotation_down_button->setText(QString());
        move_delay_up_button->setText(QString());
        move_delay_down_button->setText(QString());
        label_9->setText(QApplication::translate("MainWindow", "Move Delay", nullptr));
        claw_rotation_label->setText(QApplication::translate("MainWindow", "VAL", nullptr));
        move_delay_label->setText(QApplication::translate("MainWindow", " VAL", nullptr));
        arm_rotation_label->setText(QApplication::translate("MainWindow", " VAL", nullptr));
        arm_rotation_up_button->setText(QString());
        label_10->setText(QApplication::translate("MainWindow", "Arm Rotation", nullptr));
        arm_rotation_down_button->setText(QString());
        settingsTutorial->setText(QString());
        label_8->setText(QApplication::translate("MainWindow", "Reset Settings", nullptr));
        reset_button->setText(QString());
        backButton_2->setText(QString());
        pushButton->setText(QString());
        countdownLabel->setText(QApplication::translate("MainWindow", "5", nullptr));
        countdownLabel2->setText(QApplication::translate("MainWindow", "SECONDS REMAINING", nullptr));
        retract_cancel_button->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
