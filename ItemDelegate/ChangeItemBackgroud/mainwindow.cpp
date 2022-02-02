#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mylistwidgetdelegate.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //添加数据
    addItem("Video1", ":/images/video_1.png", 1024);
    addItem("Video2", ":/images/video_2.png", 2048);
    addItem("Video3", ":/images/video_3.png", 3072);
    addItem("Video4", ":/images/video_4.png", 4096);
    addItem("Video5", ":/images/video_1.png", 5120);

    //使用自定义绘图
    ui->listWidget->setItemDelegate(new MyListWidgetDelegate(ui->listWidget));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addItem(const QString& qstrDownloadFileName, const QString& qstrRecordPic, int iFileSize)
{
    QListWidgetItem* pItem = new QListWidgetItem();
    if (nullptr != pItem) {
        pItem->setData(Qt::DisplayRole, qstrDownloadFileName);
        pItem->setData(Qt::UserRole + 1, qstrRecordPic);
        pItem->setData(Qt::UserRole + 2, iFileSize);
        ui->listWidget->addItem(pItem);
    }
}
