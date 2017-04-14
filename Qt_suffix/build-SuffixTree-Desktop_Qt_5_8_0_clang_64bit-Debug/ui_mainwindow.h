/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *ContainJudgeButton;
    QPlainTextEdit *stringS;
    QPlainTextEdit *stringT;
    QLabel *label;
    QLabel *label_2;
    QLabel *Direction;
    QLabel *Result;
    QPushButton *RepeatingCountButton;
    QPushButton *LongestRepeatButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(545, 464);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ContainJudgeButton = new QPushButton(centralWidget);
        ContainJudgeButton->setObjectName(QStringLiteral("ContainJudgeButton"));
        ContainJudgeButton->setGeometry(QRect(30, 220, 160, 32));
        stringS = new QPlainTextEdit(centralWidget);
        stringS->setObjectName(QStringLiteral("stringS"));
        stringS->setGeometry(QRect(30, 50, 200, 150));
        stringT = new QPlainTextEdit(centralWidget);
        stringT->setObjectName(QStringLiteral("stringT"));
        stringT->setGeometry(QRect(270, 50, 200, 150));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 30, 60, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(340, 30, 60, 16));
        Direction = new QLabel(centralWidget);
        Direction->setObjectName(QStringLiteral("Direction"));
        Direction->setGeometry(QRect(270, 220, 250, 100));
        Result = new QLabel(centralWidget);
        Result->setObjectName(QStringLiteral("Result"));
        Result->setGeometry(QRect(270, 330, 250, 61));
        RepeatingCountButton = new QPushButton(centralWidget);
        RepeatingCountButton->setObjectName(QStringLiteral("RepeatingCountButton"));
        RepeatingCountButton->setGeometry(QRect(30, 260, 160, 32));
        LongestRepeatButton = new QPushButton(centralWidget);
        LongestRepeatButton->setObjectName(QStringLiteral("LongestRepeatButton"));
        LongestRepeatButton->setGeometry(QRect(30, 300, 160, 32));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 545, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        ContainJudgeButton->setText(QApplication::translate("MainWindow", "Containing Judge", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "String S", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "String T", Q_NULLPTR));
        Direction->setText(QString());
        Result->setText(QString());
        RepeatingCountButton->setText(QApplication::translate("MainWindow", "Repeating Count", Q_NULLPTR));
        LongestRepeatButton->setText(QApplication::translate("MainWindow", "Longest Repeated Str", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
