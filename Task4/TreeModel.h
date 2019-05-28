#pragma once
#include "TreeItem.h"
#include <qabstractitemmodel.h>

class TreeModel : public QAbstractItemModel
{
	Q_OBJECT

public:
	explicit TreeModel(const QMap<QString, QMultiMap<QString, QString>*>* data, QObject *parent = nullptr);
	~TreeModel();

	QVariant data(const QModelIndex &index, int role) const override;
	Qt::ItemFlags flags(const QModelIndex &index) const override;
	QVariant headerData(int section, Qt::Orientation orientation,
		int role = Qt::DisplayRole) const override;
	QModelIndex index(int row, int column,
		const QModelIndex &parent = QModelIndex()) const override;
	QModelIndex parent(const QModelIndex &index) const override;
	int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	int columnCount(const QModelIndex &parent = QModelIndex()) const override;

	TreeItem* getRoot();

private:
	void setupModelData(const QMap<QString, QMultiMap<QString, QString>*>* lines, TreeItem *parent);

	TreeItem* rootItem;
};

