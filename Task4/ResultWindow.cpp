#include "ResultWindow.h"
#include "ui_ResultWindow.h"
#include <QFileDialog>
#include <QTextStream>

ResultWindow::ResultWindow(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::ResultWindow();
	ui->setupUi(this);
}

ResultWindow::~ResultWindow()
{
	delete ui;
	delete this_model;
}

void ResultWindow::setModel(TreeModel* model)
{
	this_model = model;
	ui->treeView->setModel(model);
	this->show();
}

void ResultWindow::saveToFile()
{
	auto strings = formData();
	QString fileName = QFileDialog::getSaveFileName(this,
		tr("Save to file"), "", tr("(*.txt)"));

	if (!fileName.isEmpty())
	{
		QFile file(fileName);
		if (!file.open(QIODevice::WriteOnly))
			return;

		QTextStream out(&file);
		for (auto& str : *strings)
			out << str << "\n";
	}

}

QStringList* ResultWindow::formData()
{
	QStringList* strings = new QStringList;
	const QModelIndex index;
	QVector<QVariant> temp;
	int i = 0;
	for (i = 0; i < this_model->rowCount(); i++)
	{
		strings->push_back(this_model->data(this_model->index(i, 0), 0).toString());
		auto row1 = this_model->rowCount(this_model->index(i, 0));
		for (auto r = 0; r < row1; r++)
		{
			strings->push_back("\t" + this_model->data(this_model->index(i, 0).child(r, 0), 0).toString());
			auto row2 = this_model->rowCount(this_model->index(i, 0).child(r, 0));
			for (auto r2 = 0; r2 < row2; r2++)
				strings->push_back("\t\t" + this_model->data(this_model->index(i, 0).child(r, 0).child(r2, 0), 0).toString());
		}
	}
	return strings;
}


