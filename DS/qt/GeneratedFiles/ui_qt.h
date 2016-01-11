/********************************************************************************
** Form generated from reading UI file 'qt.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_H
#define UI_QT_H

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
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qtClass
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QTextBrowser *textBrowser;
    QTextBrowser *textBrowser_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *qtClass)
    {
        if (qtClass->objectName().isEmpty())
            qtClass->setObjectName(QStringLiteral("qtClass"));
        qtClass->resize(600, 400);
        centralWidget = new QWidget(qtClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(90, 230, 93, 28));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 70, 71, 51));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(330, 230, 93, 28));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(80, 140, 71, 51));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(180, 80, 251, 31));
        textBrowser_2 = new QTextBrowser(centralWidget);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(180, 150, 251, 31));
        qtClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(qtClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 26));
        qtClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(qtClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        qtClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(qtClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        qtClass->setStatusBar(statusBar);

        retranslateUi(qtClass);

        QMetaObject::connectSlotsByName(qtClass);
    } // setupUi

    void retranslateUi(QMainWindow *qtClass)
    {
        qtClass->setWindowTitle(QApplication::translate("qtClass", "qt", 0));
        pushButton->setText(QApplication::translate("qtClass", "Login", 0));
        label->setText(QApplication::translate("qtClass", "username", 0));
        pushButton_2->setText(QApplication::translate("qtClass", "Cancel", 0));
        label_2->setText(QApplication::translate("qtClass", "password", 0));
    } // retranslateUi

};

namespace Ui {
    class qtClass: public Ui_qtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_H
