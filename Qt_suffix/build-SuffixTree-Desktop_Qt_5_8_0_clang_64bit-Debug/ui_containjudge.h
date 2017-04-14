/********************************************************************************
** Form generated from reading UI file 'containjudge.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTAINJUDGE_H
#define UI_CONTAINJUDGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_containjudge
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *stringS;
    QLineEdit *stringT;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *containjudge)
    {
        if (containjudge->objectName().isEmpty())
            containjudge->setObjectName(QStringLiteral("containjudge"));
        containjudge->resize(400, 300);
        buttonBox = new QDialogButtonBox(containjudge);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        stringS = new QLineEdit(containjudge);
        stringS->setObjectName(QStringLiteral("stringS"));
        stringS->setGeometry(QRect(110, 30, 161, 20));
        stringT = new QLineEdit(containjudge);
        stringT->setObjectName(QStringLiteral("stringT"));
        stringT->setGeometry(QRect(110, 70, 161, 20));
        pushButton = new QPushButton(containjudge);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 30, 91, 30));
        pushButton_2 = new QPushButton(containjudge);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 70, 91, 30));
        pushButton_3 = new QPushButton(containjudge);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 120, 141, 32));

        retranslateUi(containjudge);
        QObject::connect(buttonBox, SIGNAL(accepted()), containjudge, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), containjudge, SLOT(reject()));

        QMetaObject::connectSlotsByName(containjudge);
    } // setupUi

    void retranslateUi(QDialog *containjudge)
    {
        containjudge->setWindowTitle(QApplication::translate("containjudge", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("containjudge", "string S", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("containjudge", "string T", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("containjudge", "Containing Judge", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class containjudge: public Ui_containjudge {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTAINJUDGE_H
