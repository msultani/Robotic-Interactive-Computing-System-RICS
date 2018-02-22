/********************************************************************************
** Form generated from reading UI file 'release.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RELEASE_H
#define UI_RELEASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Release
{
public:
    QLabel *countdownLabel2;
    QLabel *countdownLabel;

    void setupUi(QDialog *Release)
    {
        if (Release->objectName().isEmpty())
            Release->setObjectName(QStringLiteral("Release"));
        Release->resize(400, 300);
        Release->setStyleSheet(QStringLiteral("background: rgb(67, 83, 106);"));
        countdownLabel2 = new QLabel(Release);
        countdownLabel2->setObjectName(QStringLiteral("countdownLabel2"));
        countdownLabel2->setGeometry(QRect(10, 150, 391, 71));
        QFont font;
        font.setPointSize(30);
        countdownLabel2->setFont(font);
        countdownLabel2->setStyleSheet(QLatin1String("background: rgb(67, 83, 106);\n"
"qproperty-alignment: AlignCenter;"));
        countdownLabel = new QLabel(Release);
        countdownLabel->setObjectName(QStringLiteral("countdownLabel"));
        countdownLabel->setGeometry(QRect(0, 60, 391, 81));
        QFont font1;
        font1.setPointSize(100);
        font1.setBold(true);
        font1.setWeight(75);
        countdownLabel->setFont(font1);
        countdownLabel->setStyleSheet(QLatin1String("background: rgb(67, 83, 106);\n"
"qproperty-alignment: AlignCenter;"));

        retranslateUi(Release);

        QMetaObject::connectSlotsByName(Release);
    } // setupUi

    void retranslateUi(QDialog *Release)
    {
        Release->setWindowTitle(QApplication::translate("Release", "Dialog", nullptr));
        countdownLabel2->setText(QApplication::translate("Release", "SECONDS REMAINING", nullptr));
        countdownLabel->setText(QApplication::translate("Release", "5", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Release: public Ui_Release {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RELEASE_H
