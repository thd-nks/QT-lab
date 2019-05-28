#include "MainWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	w.show();
	return a.exec();
}
/*
 *	В первом окне отображаются открытые html
 *	Кнопка парсинга
 *	Открывается результат парсинга
 *	Сохранить результат в текстовый файл
 *
 */