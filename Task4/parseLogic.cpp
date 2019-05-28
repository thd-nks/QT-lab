#include "parseLogic.h"
#include <QMap>
#include <QListWidgetItem>
#include <QFile>


parseLogic::parseLogic()
{
}


parseLogic::~parseLogic()
{
	delete files;
}


void parseLogic::addFile(QFile* file)
{
	auto name = file->fileName();
	for(auto& addedFile : *files)
		if(addedFile->fileName() == name)
			return;
	files->push_back(file);
}

QVector<QFile*>* parseLogic::getFiles()
{
	return files;
}


QMap<QString, QMultiMap<QString, QString>*>* parseLogic::parseFiles(QListWidget* list)
{
	QRegExp rx("(http|ftp|gopher|news|telnet|file):\\/\\/w{3}\\.\\w+\\.?\\w*\\.?ru");
	auto pos = 0;
	auto count = 0;
	auto result = new QMap<QString, QMultiMap<QString, QString>*>;

	files->clear();
	for (int i = 0; i < list->count(); i++)
		addFile(new QFile(list->item(i)->text()));

	for (auto file : *files)
	{
		//if (!file->isOpen() && !file->open(QIODevice::ReadOnly))
			//return nullptr;
		file->open(QIODevice::ReadOnly);
		QStringList strings = ((QString)file->readAll()).split('\n');
		for (auto i = 0; i != strings.length(); i++)
		{
			while ((pos = rx.indexIn(strings[i], pos)) != -1) {

				pos += rx.matchedLength();
				QString url = strings[i].mid(pos - rx.matchedLength(), rx.matchedLength());
				if(!result->contains(url))
					result->insert(url, new QMultiMap<QString, QString>);
				
				QString position = QString("Row: %1; Symbol: %2").arg(QString::number(i + 1), QString::number(rx.pos(count++)));
				result->find(url).value()->insert(file->fileName(), position);
			}
			count = 0;
			pos = 0;
		}
		file->close();
	}
	return result;
}

