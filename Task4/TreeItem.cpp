#include "TreeItem.h"



TreeItem::TreeItem(QList<QVariant> data, TreeItem *parent)
{
	parentItem = parent;
	itemData = data;
}

TreeItem::~TreeItem()
{
	qDeleteAll(childItems);
}

void TreeItem::appendChild(TreeItem* child)
{
	childItems.append(child);
}

TreeItem* TreeItem::getParent()
{
	return parentItem;
}

QVariant TreeItem::data(const int column) const
{
	return itemData.value(column);
}

TreeItem* TreeItem::child(int row)
{
	return childItems.value(row);
}

int TreeItem::childCount() const
{
	return childItems.count();
}

int TreeItem::columnCount() const
{
	return itemData.count();
}

int TreeItem::row() const
{
	if (parentItem)
		return parentItem->childItems.indexOf(const_cast<TreeItem*>(this));

	return 0;
}







