#pragma once

#include <QMainWindow>
#include "ui_MainWindow.h"
#include "parseLogic.h"
#include "ResultWindow.h"
#include "TreeModel.h"
#include "QMdiArea"
#include "QListWidget"
#include "QListWidgetItem"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	~MainWindow();
	parseLogic* parser = new parseLogic();

private slots:
	void formModel();
	void openHtmls();
	//void setUi();

private:
	void saveToFile();
	//QListWidget* list;
	//QMdiArea* mdiArea;
	//TreeModel* model = nullptr;
	Ui::MainWindow *ui;
};
