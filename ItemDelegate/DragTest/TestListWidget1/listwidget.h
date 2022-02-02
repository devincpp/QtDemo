#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QListWidget>
#include <QDrag>
#include <QDragEnterEvent>
#include <QMimeData>
#include "thumbnail.h"

class ListWidget : public QListWidget
{
    Q_OBJECT

public:
    explicit ListWidget(QWidget *parent = nullptr);

    bool isDraging() const {return IsDraging;}
    int offset() const {return 19;}
    int highlightedRow() const {return theHighlightedRow;}
    int dragRow() const {return theDragRow;}
    static QString myMimeType() { return QStringLiteral("TestListWidget/text-icon"); }

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragLeaveEvent(QDragLeaveEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void startDrag(Qt::DropActions supportedActions) override;

private:
    bool IsDraging = false;
    QRect oldHighlightedRect;
    QRect theHighlightedRect;
    int theHighlightedRow = -1;
    int theDragRow = -1;

    const QRect targetRect(const QPoint &position) const;
};


#endif // LISTWIDGET_H
