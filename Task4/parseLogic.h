#pragma once
#include <qvector.h>
#include <QFileDialog>
#include <QListWidgetItem>
using namespace std;


class parseLogic
{
public:
	parseLogic();
	~parseLogic();
	void addFile(QFile* file);
	QMap<QString, QMultiMap<QString, QString>*>* parseFiles(QListWidget* list);
	QVector<QFile*>* getFiles();

private:
	QVector<QFile*>* files = new QVector<QFile*>;
};

