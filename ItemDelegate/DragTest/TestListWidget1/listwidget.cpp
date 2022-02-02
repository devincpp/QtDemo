#include "listwidget.h"

ListWidget::ListWidget(QWidget *parent) :
    QListWidget(parent)
{
    //setMouseTracking(true);
    setDragEnabled(true);  //必需
    setAcceptDrops(true);  //必需
    //setDropIndicatorShown(false);
}

void ListWidget::dragEnterEvent(QDragEnterEvent *event)
{
    ListWidget *source = qobject_cast<ListWidget *>(event->source());
    if (source && source == this) {
        //IsDraging(标志位)判断是否正在拖拽
        IsDraging = true;
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
}

void ListWidget::dragLeaveEvent(QDragLeaveEvent *event)
{
    theHighlightedRow = -2;

    update(theHighlightedRect);

    //IsDraging(标志位)判断是否正在拖拽
    IsDraging = false;

    event->accept();
}

void ListWidget::dragMoveEvent(QDragMoveEvent *event)
{
    ListWidget *source = qobject_cast<ListWidget *>(event->source());
    if (source && source == this) {

        oldHighlightedRect = theHighlightedRect;
        theHighlightedRect = targetRect(event->pos());

        //offset() = 19(这个数值是我调用父类的dropEvent(event)一次一次试出来的，我觉得公式应该是19 = 40 / 2 - 1， 其中40是item行高)
        if(event->pos().y() >= offset()){

            theHighlightedRow = row(itemAt(event->pos() - QPoint(0, offset())));

            if(oldHighlightedRect != theHighlightedRect){
                update(oldHighlightedRect);  //刷新旧区域使DropIndicator消失
                update(theHighlightedRect);  //刷新新区域使DropIndicator显示
            }else
                update(theHighlightedRect);
        }else{
            theHighlightedRow = -1;
            update(QRect(0, 0, width(), 80));  //仅刷新第一行
        }

        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
}

void ListWidget::dropEvent(QDropEvent *event)
{
    ListWidget *source = qobject_cast<ListWidget *>(event->source());
    if (source && source == this){

        IsDraging = false;

        theHighlightedRow = -2;
        update(theHighlightedRect);  //拖拽完成，刷新以使DropIndicator消失

        //因为是拖拽即选中，所以可以调用父类dropEvent(event)
        QListWidget::dropEvent(event);

        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
}

//使用startDrag()则不需要判断拖拽距离
void ListWidget::startDrag(Qt::DropActions)
{
    QListWidgetItem *theDragItem = currentItem();
    theDragRow = row(theDragItem);

//[1]把拖拽的数据放在QMimeData容器中
    QString text = theDragItem->text();
    QIcon icon = theDragItem->icon();
    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    dataStream << text << icon;

    QMimeData *mimeData = new QMimeData;
    mimeData->setData(myMimeType(), itemData);
//[1]

//[2]设置拖拽时的缩略图，thumbnail类(找机会我会写一篇单独的文章介绍)是继承自QWidget的类椭圆形半透明窗口，使用grab()将QWidget变成QPixmap。
    Thumbnail *DragImage = new Thumbnail(this);
    DragImage->setupthumbnail(icon, text);
    //DragImage->setIconSize(18);  //default:20
    QPixmap pixmap = DragImage->grab();

    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);
    drag->setHotSpot(QPoint(pixmap.width() / 2, pixmap.height() / 2));
//[2]

    if(drag->exec(Qt::MoveAction) == Qt::MoveAction){
    }
}

const QRect ListWidget::targetRect(const QPoint &position) const
{
    //40是item的行高
    if(position.y() >= offset())
        return QRect(0, (position.y() - offset()) / 40 * 40, width(), 2 * 40);
    else
        return QRect(0, 0, width(), 40);
}
