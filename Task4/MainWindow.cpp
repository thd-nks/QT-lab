#include "MainWindow.h"
#include "parseLogic.h"
#include <QFileDialog>
#include "TreeModel.h"
#include "ResultWindow.h"
#include "QGridLayout"
#include <QMdiSubWindow>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	//mdiArea = new QMdiArea(this);

	ui->mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	ui->mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	setCentralWidget(ui->mdiArea);

	connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::openHtmls);
	connect(ui->actionShow, &QAction::triggered, this, &MainWindow::formModel);
	connect(ui->actionSaveToFile, &QAction::triggered, this, &MainWindow::saveToFile);
	//connect(ui->mdiArea, SIGNAL(ui->mdiArea->subWindowActivated(ui->mdiArea->activeSubWindow())), this, SLOT(&MainWindow::setUi));
}


void MainWindow::saveToFile()
{	
	if(auto win = dynamic_cast<ResultWindow*>(ui->mdiArea->currentSubWindow()->widget()))
		win->saveToFile();
}


void MainWindow::openHtmls()
{
	const auto fileName = QFileDialog::getOpenFileName(this, "Open", "D:/VS Projects/Task4", "*.txt");
	if (!fileName.isEmpty())
	{
		QFile file(fileName);

		if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
			return;

		while (!file.atEnd())
		{
			auto fileNames = ((QString)file.readLine()).split(QRegExp("[,]+"));
			for (const auto& name : fileNames)
			{
				auto htmlFile = new QFile(name);

				if (htmlFile->open(QIODevice::ReadOnly | QIODevice::Text))
					parser->addFile(htmlFile);
			}
		}
		file.close();
	}
	auto files = parser->getFiles();


	auto widget = new QWidget;
	auto list = new QListWidget(widget);
	list->parentWidget()->setGeometry(20, 20, 300, 400);
	ui->mdiArea->addSubWindow(widget);
	widget->parentWidget()->setGeometry(20, 20, 350, 200);
	widget->parentWidget()->show();

	for (auto& file : *files)
	{
		list->addItem(file->fileName());
	}
	files->clear();
}


void MainWindow::formModel()
{
	TreeModel* model = nullptr;
	if (!dynamic_cast<ResultWindow*>(ui->mdiArea->currentSubWindow()->widget()))
	{
		auto parsed_file = parser->parseFiles((QListWidget*)ui->mdiArea->currentSubWindow()->widget()->children().first());
		model = new TreeModel(parsed_file);
		if (model)
		{
			auto result_window = new ResultWindow(ui->mdiArea);
			result_window->setModel(model);
			ui->mdiArea->addSubWindow(result_window);
			result_window->show();
			result_window->parentWidget()->setGeometry(10, 10, 368, 550);
		}
	}
}


MainWindow::~MainWindow()
{
	delete ui;
}
