/********************************************************************************
** Form generated from reading UI file 'ResultWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESULTWINDOW_H
#define UI_RESULTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ResultWindow
{
public:
    QTreeView *treeView;

    void setupUi(QWidget *ResultWindow)
    {
        if (ResultWindow->objectName().isEmpty())
            ResultWindow->setObjectName(QString::fromUtf8("ResultWindow"));
        ResultWindow->resize(310, 500);
        treeView = new QTreeView(ResultWindow);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setGeometry(QRect(10, 10, 241, 481));

        retranslateUi(ResultWindow);

        QMetaObject::connectSlotsByName(ResultWindow);
    } // setupUi

    void retranslateUi(QWidget *ResultWindow)
    {
        ResultWindow->setWindowTitle(QApplication::translate("ResultWindow", "ResultWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ResultWindow: public Ui_ResultWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULTWINDOW_H
