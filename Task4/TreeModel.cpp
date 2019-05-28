#include "TreeModel.h"
#include  <QSet>



TreeModel::TreeModel(const QMap<QString, QMultiMap<QString, QString>*>* data, QObject *parent)
	: QAbstractItemModel(parent)
{
	QList<QVariant> rootData;
	rootData << "URL";
	rootItem = new TreeItem(rootData);
	setupModelData(data, rootItem);
}

TreeItem* TreeModel::getRoot()
{
	return rootItem;
}

TreeModel::~TreeModel()
{
	delete rootItem;
}

QModelIndex TreeModel::index(int row, int column, const QModelIndex &parent) const
{
	if (!hasIndex(row, column, parent))
		return QModelIndex();

	TreeItem *parentItem;

	if (!parent.isValid())
		parentItem = rootItem;
	else
		parentItem = static_cast<TreeItem*>(parent.internalPointer());

	TreeItem *childItem = parentItem->child(row);
	if (childItem)
		return createIndex(row, column, childItem);

	return QModelIndex();
}

QModelIndex TreeModel::parent(const QModelIndex &index) const
{
	if (!index.isValid())
		return QModelIndex();

	TreeItem *childItem = static_cast<TreeItem*>(index.internalPointer());
	TreeItem *parentItem = childItem->getParent();

	if (parentItem == rootItem)
		return QModelIndex();

	return createIndex(parentItem->row(), 0, parentItem);
}

int TreeModel::rowCount(const QModelIndex &parent) const
{
	TreeItem *parentItem;
	if (parent.column() > 0)
		return 0;

	if (!parent.isValid())
		parentItem = rootItem;
	else
		parentItem = static_cast<TreeItem*>(parent.internalPointer());

	return parentItem->childCount();
}

int TreeModel::columnCount(const QModelIndex &parent) const
{
	if (parent.isValid())
		return static_cast<TreeItem*>(parent.internalPointer())->columnCount();

	return rootItem->columnCount();
}

QVariant TreeModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid())
		return QVariant();

	if (role != Qt::DisplayRole)
		return QVariant();

	auto item = static_cast<TreeItem*>(index.internalPointer());
	//auto temp = item->data(index.column());
	return item->data(index.column());
}

Qt::ItemFlags TreeModel::flags(const QModelIndex &index) const
{
	if (!index.isValid())
		return 0;

	return QAbstractItemModel::flags(index);
}

QVariant TreeModel::headerData(int section, Qt::Orientation orientation,
	int role) const
{
	if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
		return rootItem->data(section);

	return QVariant();
}

void TreeModel::setupModelData(const QMap<QString, QMultiMap<QString, QString>*>* lines, TreeItem *parent)
{
	int count = 0, globalcount = 0;
	QList<QVariant> vars;

	auto keys = lines->keys();

	for (auto& str : keys)
	{
		QList<QVariant> par_data;
		par_data << str;
		parent->appendChild(new TreeItem(par_data, parent));
		auto new_key = lines->find(str).value();
		auto temp = new_key->keys();
		QSet<QString> unique_keys_inside;
		for (const auto& key : temp)
			unique_keys_inside.insert(key);

		for (const auto& key : unique_keys_inside)
		{
			auto unique_values = new_key->values(key);
			vars.append(key);
			parent->child(globalcount)->appendChild(new TreeItem(vars, parent->child(globalcount)));
			vars.clear();
			for (auto& value : unique_values)
			{
				vars.append(value);
				parent->child(globalcount)->child(count)->appendChild(new TreeItem(vars, parent->child(globalcount)->child(count)));				
				vars.clear();
			}
			count++;
		}
		count = 0;
		globalcount++;
	}
}