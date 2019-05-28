/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionShow;
    QAction *actionForm_Model;
    QAction *actionSaveToFile;
    QWidget *centralWidget;
    QMdiArea *mdiArea;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuModel;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1095, 830);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionShow = new QAction(MainWindow);
        actionShow->setObjectName(QString::fromUtf8("actionShow"));
        actionForm_Model = new QAction(MainWindow);
        actionForm_Model->setObjectName(QString::fromUtf8("actionForm_Model"));
        actionSaveToFile = new QAction(MainWindow);
        actionSaveToFile->setObjectName(QString::fromUtf8("actionSaveToFile"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        mdiArea = new QMdiArea(centralWidget);
        mdiArea->setObjectName(QString::fromUtf8("mdiArea"));
        mdiArea->setGeometry(QRect(0, 0, 1121, 771));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1095, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuModel = new QMenu(menuBar);
        menuModel->setObjectName(QString::fromUtf8("menuModel"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuModel->menuAction());
        menuFile->addAction(actionOpen);
        menuModel->addAction(actionShow);
        menuModel->addAction(actionSaveToFile);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", nullptr));
        actionSave->setText(QApplication::translate("MainWindow", "Save", nullptr));
        actionShow->setText(QApplication::translate("MainWindow", "Show", nullptr));
        actionForm_Model->setText(QApplication::translate("MainWindow", "Form Model", nullptr));
        actionSaveToFile->setText(QApplication::translate("MainWindow", "Save", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuModel->setTitle(QApplication::translate("MainWindow", "Model", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
