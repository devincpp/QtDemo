#ifndef ITEMDELEGATE_H
#define ITEMDELEGATE_H

#include <QWidget>
#include <QStyledItemDelegate>
#include "listwidget.h"

#define POLYGON 4   //等腰三角形直角边长
#define WIDTH 1     //分隔符粗细的一半

class ItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    ItemDelegate(QObject *parent = nullptr);

protected:
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // ITEMDELEGATE_H
