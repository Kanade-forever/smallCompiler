#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "cifa.h"
#include "four.h"
#include "stack.h"
#include "yufa.h"


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
