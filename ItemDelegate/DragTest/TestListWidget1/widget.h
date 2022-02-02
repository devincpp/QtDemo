#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLayout>
#include "itemdelegate.h"

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);

private:
    void initUi();
};


#endif // WIDGET_H
