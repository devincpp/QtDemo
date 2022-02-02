#include "mylistwidgetdelegate.h"

MyListWidgetDelegate::MyListWidgetDelegate(QObject *pParent)
    : QStyledItemDelegate(pParent)
{

}

MyListWidgetDelegate::~MyListWidgetDelegate()
{

}

void MyListWidgetDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    // QStyledItemDelegate::paint(painter, option, index);

    QRect rect = option.rect; // 目标矩形
    rect.adjust(2, 2, -2, -2); // 缩小一圈，留出空白间隔

    // 取得该项对应的数据
    QString qstrFileName = index.data(Qt::DisplayRole).toString();
    QString qstrRecordPic = index.data(Qt::UserRole + 1).toString();
    int iFileSize = index.data(Qt::UserRole + 2).toInt();

    // 状态显示: 若该项被选中
    if (option.state & QStyle::State_Selected) {
        painter->setBrush(QColor(0xCC, 0xAA, 0xAA));
        painter->drawRoundedRect(rect, 2, 2);
        painter->setBrush(Qt::NoBrush);
    }

    // 图片显示
    {
        QRect dst = rect;
        dst.setRight(rect.left() + 40);
        QRect area(0, 0, 24, 24);
        area.moveCenter(dst.center());

        QPixmap pixmapPic(qstrRecordPic);
        painter->drawPixmap(area, pixmapPic);
    }

    // 文件名显示
    {
        QRect dst = rect;
        dst.setLeft(rect.left() + 40);
        dst.setBottom(rect.top() + 20);
        painter->drawText(dst, Qt::AlignLeft | Qt::AlignVCenter, qstrFileName);
    }

    // 文件大小
    {
        QRect dst = rect;
        dst.setLeft(rect.left() + 40);
        dst.setTop(rect.top() + 20);
        painter->drawText(dst, Qt::AlignLeft | Qt::AlignVCenter, QString::number(iFileSize));
    }
}

QSize MyListWidgetDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    //return QStyledItemDelegate::sizeHint(option, index);

    QSize size = QStyledItemDelegate::sizeHint(option, index);
    size.setHeight(40);
    return size;
}
