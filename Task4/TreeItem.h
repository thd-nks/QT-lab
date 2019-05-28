#pragma once
#include <qlist.h>
#include <QVariant>

class TreeItem
{
public:
	explicit TreeItem(QList<QVariant> data, TreeItem *parentItem = nullptr);
	~TreeItem();

	void appendChild(TreeItem *child);

	TreeItem *child(int row);
	int childCount() const;
	int columnCount() const;
	QVariant data(int column) const;
	int row() const;
	TreeItem* getParent();

private:
	QList<TreeItem*> childItems;
	QList<QVariant> itemData;
	TreeItem* parentItem;
};
