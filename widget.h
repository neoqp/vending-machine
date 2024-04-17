#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "ui_widget.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void add10();
    void add50();
    void add100();
    void add500();
    void buyCoffee();
    void buyTea();
    void buyMilk();
    void reset();
    void updateDrinkButtons();

private:
    Ui::Widget *ui;
    int money;

    void updateDisplay();
    void addMoney(int amount);
    void buyDrink(int cost);
};

#endif // WIDGET_H
