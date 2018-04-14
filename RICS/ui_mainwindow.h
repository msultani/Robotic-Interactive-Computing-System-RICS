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
    QHoverSensitiveButton *fetchButton;
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
    QWidget *settingsPage;
    QLabel *label_3;
    QHoverSensitiveButton *backButton;
    QHoverSensitiveButton *hoverButton;
    QLabel *label_4;
    QLabel *hover_time_label;
    QHoverSensitiveButton *hover_time_up_button;
    QHoverSensitiveButton *hover_time_down_button;
    QLabel *label_6;
    QHoverSensitiveButton *autoButton;
    QLabel *label_8;
    QWidget *tutorialPage;
    QLabel *label_5;
    QHoverSensitiveButton *backButton_2;
    QLabel *label_7;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(406, 355);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral("background: rgb(67, 83, 106);"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setStyleSheet(QStringLiteral("background: rgb(67, 83, 106);"));
        startPage = new QWidget();
        startPage->setObjectName(QStringLiteral("startPage"));
        startPage->setStyleSheet(QStringLiteral("background: rgb(67, 83, 106)"));
        fetchButton = new QHoverSensitiveButton(startPage);
        fetchButton->setObjectName(QStringLiteral("fetchButton"));
        fetchButton->setGeometry(QRect(90, 90, 211, 61));
        QFont font;
        font.setFamily(QStringLiteral("Arial Rounded MT Bold"));
        font.setPointSize(30);
        font.setBold(true);
        font.setWeight(75);
        fetchButton->setFont(font);
        fetchButton->setMouseTracking(true);
        fetchButton->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 255);\n"
"border-style: solid;\n"
"\n"
""));
        settingButton = new QHoverSensitiveButton(startPage);
        settingButton->setObjectName(QStringLiteral("settingButton"));
        settingButton->setGeometry(QRect(240, 190, 100, 100));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial Rounded MT Bold"));
        font1.setPointSize(20);
        settingButton->setFont(font1);
        settingButton->setStyleSheet(QLatin1String("background-color: rgb(255, 233, 39);\n"
"border-style: solid;\n"
"max-width:100px;\n"
"max-height:100px;\n"
"min-width:100px;\n"
"min-height:100px;\n"
""));
        label = new QLabel(startPage);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 20, 71, 20));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial Narrow"));
        font2.setPointSize(15);
        font2.setUnderline(true);
        label->setFont(font2);
        label_2 = new QLabel(startPage);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(170, 40, 51, 16));
        QFont font3;
        font3.setFamily(QStringLiteral("Arial Narrow"));
        font3.setPointSize(15);
        label_2->setFont(font3);
        tutorialButton = new QHoverSensitiveButton(startPage);
        tutorialButton->setObjectName(QStringLiteral("tutorialButton"));
        tutorialButton->setGeometry(QRect(50, 190, 100, 100));
        tutorialButton->setFont(font1);
        tutorialButton->setStyleSheet(QLatin1String("background-color: rgb(90, 225, 143);\n"
"border-style: solid;\n"
"max-width:100px;\n"
"max-height:100px;\n"
"min-width:100px;\n"
"min-height:100px;\n"
""));
        stackedWidget->addWidget(startPage);
        movementPage = new QWidget();
        movementPage->setObjectName(QStringLiteral("movementPage"));
        releaseButton = new QHoverSensitiveButton(movementPage);
        releaseButton->setObjectName(QStringLiteral("releaseButton"));
        releaseButton->setGeometry(QRect(230, 200, 122, 102));
        releaseButton->setFont(font1);
        releaseButton->setStyleSheet(QLatin1String("background-color: rgb(90, 225, 143);\n"
"border-style: solid;\n"
" border-width:1px;\n"
" border-radius:50px;\n"
" border-color: rgb(18, 121, 65);\n"
" max-width:120px;\n"
" max-height:100px;\n"
" min-width:120px;\n"
" min-height:100px;"));
        backButton_3 = new QHoverSensitiveButton(movementPage);
        backButton_3->setObjectName(QStringLiteral("backButton_3"));
        backButton_3->setGeometry(QRect(10, 10, 51, 21));
        backButton_3->setStyleSheet(QLatin1String("background-color: red;\n"
"border: solid;"));
        forwardButton = new QHoverSensitiveButton(movementPage);
        forwardButton->setObjectName(QStringLiteral("forwardButton"));
        forwardButton->setGeometry(QRect(20, 190, 131, 61));
        forwardButton->setStyleSheet(QLatin1String("background-color: rgb(240, 223, 51);\n"
"border: solid;"));
        backwardButton = new QHoverSensitiveButton(movementPage);
        backwardButton->setObjectName(QStringLiteral("backwardButton"));
        backwardButton->setGeometry(QRect(20, 260, 131, 61));
        backwardButton->setStyleSheet(QLatin1String("background-color: rgb(29, 241, 240);\n"
"border: solid;"));
        upButton = new QHoverSensitiveButton(movementPage);
        upButton->setObjectName(QStringLiteral("upButton"));
        upButton->setGeometry(QRect(160, 30, 81, 41));
        upButton->setStyleSheet(QLatin1String("background-color: rgb(205, 205, 205);\n"
"border: solid;"));
        leftButton = new QHoverSensitiveButton(movementPage);
        leftButton->setObjectName(QStringLiteral("leftButton"));
        leftButton->setGeometry(QRect(100, 80, 81, 41));
        leftButton->setStyleSheet(QLatin1String("background-color: rgb(205, 205, 205);\n"
"border: solid;"));
        rightButton = new QHoverSensitiveButton(movementPage);
        rightButton->setObjectName(QStringLiteral("rightButton"));
        rightButton->setGeometry(QRect(220, 80, 81, 41));
        rightButton->setStyleSheet(QLatin1String("background-color: rgb(205, 205, 205);\n"
"border: solid;"));
        downButton = new QHoverSensitiveButton(movementPage);
        downButton->setObjectName(QStringLiteral("downButton"));
        downButton->setGeometry(QRect(160, 130, 81, 41));
        downButton->setStyleSheet(QLatin1String("background-color: rgb(205, 205, 205);\n"
"border: solid;"));
        ready_label = new QLabel(movementPage);
        ready_label->setObjectName(QStringLiteral("ready_label"));
        ready_label->setGeometry(QRect(100, 0, 201, 20));
        ready_label->setStyleSheet(QStringLiteral("qproperty-alignment: AlignCenter;"));
        stackedWidget->addWidget(movementPage);
        settingsPage = new QWidget();
        settingsPage->setObjectName(QStringLiteral("settingsPage"));
        settingsPage->setStyleSheet(QStringLiteral("background: rgb(67, 83, 106)"));
        label_3 = new QLabel(settingsPage);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(-4, 30, 401, 41));
        QFont font4;
        font4.setFamily(QStringLiteral("Arial Rounded MT Bold"));
        font4.setPointSize(25);
        label_3->setFont(font4);
        label_3->setLayoutDirection(Qt::LeftToRight);
        label_3->setStyleSheet(QStringLiteral("qproperty-alignment: AlignCenter;"));
        backButton = new QHoverSensitiveButton(settingsPage);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setGeometry(QRect(10, 10, 51, 21));
        backButton->setStyleSheet(QLatin1String("background-color: red;\n"
"border: solid;"));
        hoverButton = new QHoverSensitiveButton(settingsPage);
        hoverButton->setObjectName(QStringLiteral("hoverButton"));
        hoverButton->setGeometry(QRect(30, 150, 121, 51));
        label_4 = new QLabel(settingsPage);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(240, 160, 91, 21));
        QFont font5;
        font5.setFamily(QStringLiteral("Arial Rounded MT Bold"));
        font5.setPointSize(15);
        label_4->setFont(font5);
        label_4->setLayoutDirection(Qt::LeftToRight);
        label_4->setStyleSheet(QStringLiteral("qproperty-alignment: AlignCenter;"));
        hover_time_label = new QLabel(settingsPage);
        hover_time_label->setObjectName(QStringLiteral("hover_time_label"));
        hover_time_label->setGeometry(QRect(40, 220, 101, 31));
        QFont font6;
        font6.setPointSize(20);
        hover_time_label->setFont(font6);
        hover_time_label->setStyleSheet(QStringLiteral("qproperty-alignment: AlignCenter;"));
        hover_time_up_button = new QHoverSensitiveButton(settingsPage);
        hover_time_up_button->setObjectName(QStringLiteral("hover_time_up_button"));
        hover_time_up_button->setGeometry(QRect(150, 200, 51, 32));
        hover_time_up_button->setStyleSheet(QLatin1String("background-color: rgb(240, 223, 51);\n"
"border: 1px solid black;"));
        hover_time_down_button = new QHoverSensitiveButton(settingsPage);
        hover_time_down_button->setObjectName(QStringLiteral("hover_time_down_button"));
        hover_time_down_button->setGeometry(QRect(150, 230, 51, 32));
        hover_time_down_button->setStyleSheet(QLatin1String("background-color: rgb(29, 241, 240);\n"
"border: 1px solid black;"));
        label_6 = new QLabel(settingsPage);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(230, 220, 111, 21));
        label_6->setFont(font5);
        label_6->setLayoutDirection(Qt::LeftToRight);
        label_6->setStyleSheet(QStringLiteral("qproperty-alignment: AlignCenter;"));
        autoButton = new QHoverSensitiveButton(settingsPage);
        autoButton->setObjectName(QStringLiteral("autoButton"));
        autoButton->setGeometry(QRect(30, 100, 121, 51));
        label_8 = new QLabel(settingsPage);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(230, 110, 121, 21));
        label_8->setFont(font5);
        label_8->setLayoutDirection(Qt::LeftToRight);
        label_8->setStyleSheet(QStringLiteral("qproperty-alignment: AlignCenter;"));
        stackedWidget->addWidget(settingsPage);
        tutorialPage = new QWidget();
        tutorialPage->setObjectName(QStringLiteral("tutorialPage"));
        label_5 = new QLabel(tutorialPage);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(170, 30, 57, 16));
        backButton_2 = new QHoverSensitiveButton(tutorialPage);
        backButton_2->setObjectName(QStringLiteral("backButton_2"));
        backButton_2->setGeometry(QRect(10, 10, 51, 21));
        backButton_2->setStyleSheet(QLatin1String("background-color: red;\n"
"border: solid;"));
        label_7 = new QLabel(tutorialPage);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(130, 130, 57, 16));
        stackedWidget->addWidget(tutorialPage);

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        fetchButton->setText(QApplication::translate("MainWindow", "Fetch", nullptr));
        settingButton->setText(QApplication::translate("MainWindow", "Settings", nullptr));
        label->setText(QApplication::translate("MainWindow", "Hover + Hold", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "to Select", nullptr));
        tutorialButton->setText(QApplication::translate("MainWindow", "Tutorials", nullptr));
        releaseButton->setText(QApplication::translate("MainWindow", "Release", nullptr));
        backButton_3->setText(QApplication::translate("MainWindow", "Back", nullptr));
        forwardButton->setText(QApplication::translate("MainWindow", "Forward", nullptr));
        backwardButton->setText(QApplication::translate("MainWindow", "Backward", nullptr));
        upButton->setText(QApplication::translate("MainWindow", "Up", nullptr));
        leftButton->setText(QApplication::translate("MainWindow", "Left", nullptr));
        rightButton->setText(QApplication::translate("MainWindow", "Right", nullptr));
        downButton->setText(QApplication::translate("MainWindow", "Down", nullptr));
        ready_label->setText(QApplication::translate("MainWindow", "Ready for commands!", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "SETTINGS", nullptr));
        backButton->setText(QApplication::translate("MainWindow", "Back", nullptr));
        hoverButton->setText(QApplication::translate("MainWindow", "ON", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Hover Mode", nullptr));
        hover_time_label->setText(QApplication::translate("MainWindow", "3.0 secs", nullptr));
        hover_time_up_button->setText(QApplication::translate("MainWindow", "U", nullptr));
        hover_time_down_button->setText(QApplication::translate("MainWindow", "D", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Hover Time", nullptr));
        autoButton->setText(QApplication::translate("MainWindow", "ON", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "Auto Movement", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Tutorials", nullptr));
        backButton_2->setText(QApplication::translate("MainWindow", "Back", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
