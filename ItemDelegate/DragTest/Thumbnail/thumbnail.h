#ifndef THUMBNAIL_H
#define THUMBNAIL_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLayout>
#include <QPainter>

#define RADIUS 17             //窗口边角的弧度
#define ELLIPSE_RADIUS 12     //内部小圆半径
#define RECT 10               //图标长/宽的一半
#define TEXT_LENGTH 100       //文字长度

class Thumbnail : public QWidget
{
    Q_OBJECT
public:
    Thumbnail(QWidget *parent = nullptr);
    void setupthumbnail(QIcon icon, QString str);
    void setIconSize(int size);

private:
    QPushButton *ImageButton = nullptr;
    QLabel *TextLabel = nullptr;

private:
    void initUi();
    void paintEvent(QPaintEvent *);
};

#endif // THUMBNAIL_H
