#ifndef MYLISTWIDGETDELEGATE_H
#define MYLISTWIDGETDELEGATE_H

#include <QPainter>
#include <QStyledItemDelegate>

class MyListWidgetDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    MyListWidgetDelegate(QObject* pParent);
    virtual ~MyListWidgetDelegate();

private:
    //决定如何绘图
    virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    //决定单元格的推荐大小
    virtual QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // MYLISTWIDGETDELEGATE_H
