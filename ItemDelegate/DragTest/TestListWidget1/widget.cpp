#include "widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    initUi();
}

void Widget::initUi()
{
    setFixedSize(250, 600);

    ListWidget *listwidget = new ListWidget(this);
    listwidget->setIconSize(QSize(25, 25));
    listwidget->setFocusPolicy(Qt::NoFocus);  //这样可禁用tab键和上下方向键并且除去复选框
    listwidget->setFixedHeight(320);
    listwidget->setFont(QFont("宋体", 10, QFont::DemiBold));
    listwidget->setStyleSheet(
                //"*{outline:0px;}"  //除去复选框
                "QListWidget{background:rgb(245, 245, 247); border:0px; margin:0px 0px 0px 0px;}"
                "QListWidget::Item{height:40px; border:0px; padding-left:14px; color:rgba(200, 40, 40, 255);}"
                "QListWidget::Item:hover{color:rgba(40, 40, 200, 255); padding-left:14px;}"
                "QListWidget::Item:selected{color:rgba(40, 40, 200, 255); padding-left:15px;}"
                );

    ItemDelegate *delegate = new ItemDelegate();
    listwidget->setItemDelegate(delegate);

    QListWidgetItem *item1 = new QListWidgetItem(listwidget);
    item1->setIcon(QIcon(":/listBar_Icon/1_hover.png"));
    item1->setText("发现音乐");

    QListWidgetItem *item2 = new QListWidgetItem(listwidget);
    item2->setIcon(QIcon(":/listBar_Icon/2_hover.png"));
    item2->setText("私人FM");

    QListWidgetItem *item3 = new QListWidgetItem(listwidget);
    item3->setIcon(QIcon(":/listBar_Icon/3_hover.png"));
    item3->setText("朋友");

    QListWidgetItem *item4 = new QListWidgetItem(listwidget);
    item4->setIcon(QIcon(":/listBar_Icon/4_hover.png"));
    item4->setText("MV");

    QListWidgetItem *item5 = new QListWidgetItem(listwidget);
    item5->setIcon(QIcon(":/listBar_Icon/5_hover.png"));
    item5->setText("本地音乐");

    QListWidgetItem *item6 = new QListWidgetItem(listwidget);
    item6->setIcon(QIcon(":/listBar_Icon/6_hover.png"));
    item6->setText("下载管理");

    QListWidgetItem *item7 = new QListWidgetItem(listwidget);
    item7->setIcon(QIcon(":/listBar_Icon/7_hover.png"));
    item7->setText("我的音乐云盘");

    QListWidgetItem *item8 = new QListWidgetItem(listwidget);
    item8->setIcon(QIcon(":/listBar_Icon/8_hover.png"));
    item8->setText("我的收藏");

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setSpacing(0);
    layout->addWidget(listwidget);
    layout->setContentsMargins(0, 0, 0, 0);
    setLayout(layout);
}
