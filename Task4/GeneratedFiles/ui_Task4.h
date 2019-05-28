/********************************************************************************
** Form generated from reading UI file 'Task4.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASK4_H
#define UI_TASK4_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Task4Class
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QTreeView *treeView;
    QMenuBar *menuBar;
    QMenu *menutest;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Task4Class)
    {
        if (Task4Class->objectName().isEmpty())
            Task4Class->setObjectName(QString::fromUtf8("Task4Class"));
        Task4Class->resize(600, 400);
        centralWidget = new QWidget(Task4Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(160, 100, 75, 23));
        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(70, 230, 70, 17));
        checkBox_2 = new QCheckBox(centralWidget);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(70, 260, 70, 17));
        treeView = new QTreeView(centralWidget);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setGeometry(QRect(290, 30, 256, 192));
        Task4Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Task4Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        menutest = new QMenu(menuBar);
        menutest->setObjectName(QString::fromUtf8("menutest"));
        Task4Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Task4Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Task4Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Task4Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Task4Class->setStatusBar(statusBar);

        menuBar->addAction(menutest->menuAction());

        retranslateUi(Task4Class);

        QMetaObject::connectSlotsByName(Task4Class);
    } // setupUi

    void retranslateUi(QMainWindow *Task4Class)
    {
        Task4Class->setWindowTitle(QApplication::translate("Task4Class", "Task4", nullptr));
        pushButton->setText(QApplication::translate("Task4Class", "PushButton", nullptr));
        checkBox->setText(QApplication::translate("Task4Class", "CheckBox", nullptr));
        checkBox_2->setText(QApplication::translate("Task4Class", "CheckBox", nullptr));
        menutest->setTitle(QApplication::translate("Task4Class", "test", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Task4Class: public Ui_Task4Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASK4_H
