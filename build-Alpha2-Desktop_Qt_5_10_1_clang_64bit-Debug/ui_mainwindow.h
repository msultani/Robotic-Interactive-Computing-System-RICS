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
#include <QtWidgets/QTabWidget>
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
    QWidget *settingsPage;
    QLabel *label_3;
    QHoverSensitiveButton *backButton;
    QHoverSensitiveButton *hoverButton;
    QLabel *label_4;
    QLabel *hover_time_label;
    QHoverSensitiveButton *hover_time_up_button;
    QHoverSensitiveButton *hover_time_down_button;
    QLabel *label_6;
    QWidget *tutorialPage;
    QHoverSensitiveButton *backButton_2;
    QLabel *label_7;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *widget;
    QHoverSensitiveButton *fetchButton_2;
    QLabel *label_5;
    QLabel *label_8;
    QWidget *widget_2;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QWidget *tab_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(406, 326);
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
        fetchButton->setGeometry(QRect(90, 60, 211, 61));
        QFont font;
        font.setFamily(QStringLiteral("Arial Rounded MT Bold"));
        font.setPointSize(30);
        font.setBold(true);
        font.setWeight(75);
        fetchButton->setFont(font);
        fetchButton->setMouseTracking(true);
        fetchButton->setStyleSheet(QLatin1String("background-color: rgb(63, 76, 255);\n"
"border-style: solid;\n"
"\n"
""));
        settingButton = new QHoverSensitiveButton(startPage);
        settingButton->setObjectName(QStringLiteral("settingButton"));
        settingButton->setGeometry(QRect(240, 160, 100, 100));
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
        label->setGeometry(QRect(160, 10, 71, 20));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial Narrow"));
        font2.setPointSize(15);
        font2.setUnderline(true);
        label->setFont(font2);
        label_2 = new QLabel(startPage);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(170, 30, 51, 16));
        QFont font3;
        font3.setFamily(QStringLiteral("Arial Narrow"));
        font3.setPointSize(15);
        label_2->setFont(font3);
        tutorialButton = new QHoverSensitiveButton(startPage);
        tutorialButton->setObjectName(QStringLiteral("tutorialButton"));
        tutorialButton->setGeometry(QRect(50, 160, 100, 100));
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
        releaseButton->setGeometry(QRect(250, 170, 122, 102));
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
        forwardButton->setGeometry(QRect(20, 160, 131, 61));
        forwardButton->setStyleSheet(QLatin1String("background-color: rgb(240, 223, 51);\n"
"border: solid;"));
        backwardButton = new QHoverSensitiveButton(movementPage);
        backwardButton->setObjectName(QStringLiteral("backwardButton"));
        backwardButton->setGeometry(QRect(20, 230, 131, 61));
        backwardButton->setStyleSheet(QLatin1String("background-color: rgb(29, 241, 240);\n"
"border: solid;"));
        upButton = new QHoverSensitiveButton(movementPage);
        upButton->setObjectName(QStringLiteral("upButton"));
        upButton->setGeometry(QRect(160, 10, 81, 41));
        upButton->setStyleSheet(QLatin1String("background-color: rgb(205, 205, 205);\n"
"border: solid;"));
        leftButton = new QHoverSensitiveButton(movementPage);
        leftButton->setObjectName(QStringLiteral("leftButton"));
        leftButton->setGeometry(QRect(100, 60, 81, 41));
        leftButton->setStyleSheet(QLatin1String("background-color: rgb(205, 205, 205);\n"
"border: solid;"));
        rightButton = new QHoverSensitiveButton(movementPage);
        rightButton->setObjectName(QStringLiteral("rightButton"));
        rightButton->setGeometry(QRect(220, 60, 81, 41));
        rightButton->setStyleSheet(QLatin1String("background-color: rgb(205, 205, 205);\n"
"border: solid;"));
        downButton = new QHoverSensitiveButton(movementPage);
        downButton->setObjectName(QStringLiteral("downButton"));
        downButton->setGeometry(QRect(160, 110, 81, 41));
        downButton->setStyleSheet(QLatin1String("background-color: rgb(205, 205, 205);\n"
"border: solid;"));
        stackedWidget->addWidget(movementPage);
        settingsPage = new QWidget();
        settingsPage->setObjectName(QStringLiteral("settingsPage"));
        settingsPage->setStyleSheet(QStringLiteral("background: rgb(67, 83, 106)"));
        label_3 = new QLabel(settingsPage);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(6, 30, 391, 41));
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
        hoverButton->setGeometry(QRect(31, 90, 161, 51));
        label_4 = new QLabel(settingsPage);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(240, 100, 91, 21));
        QFont font5;
        font5.setFamily(QStringLiteral("Arial Rounded MT Bold"));
        font5.setPointSize(15);
        label_4->setFont(font5);
        label_4->setLayoutDirection(Qt::LeftToRight);
        label_4->setStyleSheet(QStringLiteral("qproperty-alignment: AlignCenter;"));
        hover_time_label = new QLabel(settingsPage);
        hover_time_label->setObjectName(QStringLiteral("hover_time_label"));
        hover_time_label->setGeometry(QRect(40, 155, 81, 31));
        QFont font6;
        font6.setPointSize(20);
        hover_time_label->setFont(font6);
        hover_time_label->setStyleSheet(QStringLiteral("qproperty-alignment: AlignCenter;"));
        hover_time_up_button = new QHoverSensitiveButton(settingsPage);
        hover_time_up_button->setObjectName(QStringLiteral("hover_time_up_button"));
        hover_time_up_button->setGeometry(QRect(130, 150, 51, 32));
        hover_time_up_button->setStyleSheet(QLatin1String("background-color: rgb(240, 223, 51);\n"
"border: 1px solid black;\n"
""));
        hover_time_down_button = new QHoverSensitiveButton(settingsPage);
        hover_time_down_button->setObjectName(QStringLiteral("hover_time_down_button"));
        hover_time_down_button->setGeometry(QRect(130, 180, 51, 32));
        hover_time_down_button->setStyleSheet(QLatin1String("background-color: rgb(127, 169, 255);\n"
"border: 1px solid black;"));
        label_6 = new QLabel(settingsPage);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(230, 170, 101, 21));
        label_6->setFont(font5);
        label_6->setLayoutDirection(Qt::LeftToRight);
        label_6->setStyleSheet(QStringLiteral("qproperty-alignment: AlignCenter;"));
        stackedWidget->addWidget(settingsPage);
        tutorialPage = new QWidget();
        tutorialPage->setObjectName(QStringLiteral("tutorialPage"));
        backButton_2 = new QHoverSensitiveButton(tutorialPage);
        backButton_2->setObjectName(QStringLiteral("backButton_2"));
        backButton_2->setGeometry(QRect(10, 10, 51, 21));
        backButton_2->setStyleSheet(QLatin1String("background-color: red;\n"
"border: solid;"));
        label_7 = new QLabel(tutorialPage);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(0, 30, 391, 41));
        label_7->setFont(font4);
        label_7->setLayoutDirection(Qt::LeftToRight);
        label_7->setStyleSheet(QStringLiteral("qproperty-alignment: AlignCenter;"));
        tabWidget = new QTabWidget(tutorialPage);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 90, 381, 211));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        widget = new QWidget(tab);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 0, 351, 181));
        widget->setStyleSheet(QStringLiteral("background-color: rgb(107, 164, 227)"));
        fetchButton_2 = new QHoverSensitiveButton(widget);
        fetchButton_2->setObjectName(QStringLiteral("fetchButton_2"));
        fetchButton_2->setGeometry(QRect(20, 90, 101, 41));
        QFont font7;
        font7.setPointSize(14);
        font7.setBold(false);
        font7.setItalic(false);
        font7.setWeight(50);
        fetchButton_2->setFont(font7);
        fetchButton_2->setMouseTracking(true);
        fetchButton_2->setStyleSheet(QLatin1String("background-color: rgb(63, 76, 255);\n"
"border: 1px solid black;\n"
"font: 14pt ;\n"
""));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 20, 91, 20));
        QFont font8;
        font8.setPointSize(18);
        font8.setBold(false);
        font8.setItalic(false);
        font8.setWeight(50);
        label_5->setFont(font8);
        label_5->setStyleSheet(QStringLiteral("font: 18pt ;"));
        label_8 = new QLabel(widget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(40, 40, 61, 16));
        label_8->setFont(font8);
        label_8->setStyleSheet(QStringLiteral("font: 18pt;"));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(170, 10, 171, 151));
        widget_2->setStyleSheet(QStringLiteral("background: rgb(212, 212, 212)"));
        label_9 = new QLabel(widget_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 0, 171, 31));
        label_10 = new QLabel(widget_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 30, 171, 21));
        label_11 = new QLabel(widget_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 80, 171, 21));
        label_12 = new QLabel(widget_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 100, 171, 21));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());
        stackedWidget->addWidget(tutorialPage);

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(3);
        tabWidget->setCurrentIndex(0);


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
        label_3->setText(QApplication::translate("MainWindow", "SETTINGS", nullptr));
        backButton->setText(QApplication::translate("MainWindow", "Back", nullptr));
        hoverButton->setText(QApplication::translate("MainWindow", "ON/OFF", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Hover Mode", nullptr));
        hover_time_label->setText(QApplication::translate("MainWindow", "3 secs", nullptr));
        hover_time_up_button->setText(QApplication::translate("MainWindow", "U", nullptr));
        hover_time_down_button->setText(QApplication::translate("MainWindow", "D", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Hover Time", nullptr));
        backButton_2->setText(QApplication::translate("MainWindow", "Back", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "TUTORIALS", nullptr));
        fetchButton_2->setText(QApplication::translate("MainWindow", "Fetch", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Hover + Hold", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "to Select", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "Move cursor over buttons", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "Hold for ~3 secs", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "Fetch will call the arm", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "to fetch the wand", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Controls", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
