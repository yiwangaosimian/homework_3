/********************************************************************************
** Form generated from reading UI file 'mw1.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MW1_H
#define UI_MW1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MW1
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MW1)
    {
        if (MW1->objectName().isEmpty())
            MW1->setObjectName(QStringLiteral("MW1"));
        MW1->resize(1032, 1172);
        centralwidget = new QWidget(MW1);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(60, 0, 51, 31));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(0, 0, 51, 31));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(300, 230, 60, 16));
        MW1->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MW1);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1032, 22));
        MW1->setMenuBar(menubar);
        statusbar = new QStatusBar(MW1);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MW1->setStatusBar(statusbar);

        retranslateUi(MW1);

        QMetaObject::connectSlotsByName(MW1);
    } // setupUi

    void retranslateUi(QMainWindow *MW1)
    {
        MW1->setWindowTitle(QApplication::translate("MW1", "MainWindow", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MW1", "save", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MW1", "exit", Q_NULLPTR));
        label->setText(QApplication::translate("MW1", "emmmm", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MW1: public Ui_MW1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MW1_H
