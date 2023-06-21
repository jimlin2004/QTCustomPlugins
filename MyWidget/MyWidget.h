#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QPushButton>

class MyWidget : public QPushButton
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = 0);
};

#endif // MYWIDGET_H
