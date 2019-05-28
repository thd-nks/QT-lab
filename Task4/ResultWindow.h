#pragma once

#include <QWidget>
#include "TreeModel.h"

namespace Ui { class ResultWindow; };

class ResultWindow : public QWidget
{
	Q_OBJECT

public:
	ResultWindow(QWidget *parent = Q_NULLPTR);
	~ResultWindow();

public slots:
	void setModel(TreeModel* model);
	void saveToFile();

private:
	QStringList* formData();
	Ui::ResultWindow *ui;
	TreeModel* this_model;
};
