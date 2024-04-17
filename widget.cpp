#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    money(0)
{
    ui->setupUi(this);

    ui->lcdNumber->setStyleSheet("QLCDNumber { background-color: white; }");
    connect(ui->add10, &QPushButton::clicked, this, &Widget::add10);
    connect(ui->add50, &QPushButton::clicked, this, &Widget::add50);
    connect(ui->add100, &QPushButton::clicked, this, &Widget::add100);
    connect(ui->add500, &QPushButton::clicked, this, &Widget::add500);

    connect(ui->buyCoffee, &QPushButton::clicked, this, &Widget::buyCoffee);
    connect(ui->buyTea, &QPushButton::clicked, this, &Widget::buyTea);
    connect(ui->buyMilk, &QPushButton::clicked, this, &Widget::buyMilk);

    connect(ui->reset, &QPushButton::clicked, this, &Widget::reset);

    updateDrinkButtons();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::updateDisplay() {
    ui->lcdNumber->display(money);
}

void Widget::addMoney(int amount) {
    money += amount;
    updateDisplay();
    updateDrinkButtons();
}

void Widget::buyDrink(int cost) {
    if (money >= cost) {
        money -= cost;
        updateDisplay();
        updateDrinkButtons();
    } else {
        QMessageBox::warning(this, "Warning", "Not enough money!");
    }
}

void Widget::reset() {
    QString message = "500won: " + QString::number(money / 500) +
                      "\n100won: " + QString::number((money % 500) / 100) +
                      "\n50won: " + QString::number(((money % 500) % 100) / 50) +
                      "\n10won: " + QString::number((((money % 500) % 100) % 50) / 10);

    QMessageBox::information(this, "Change", message);

    money = 0;
    updateDisplay();
    updateDrinkButtons();
}

void Widget::add10() {
    addMoney(10);
}

void Widget::add50() {
    addMoney(50);
}

void Widget::add100() {
    addMoney(100);
}

void Widget::add500() {
    addMoney(500);
}

void Widget::buyCoffee() {
    buyDrink(100);
}

void Widget::buyTea() {
    buyDrink(150);
}

void Widget::buyMilk() {
    buyDrink(200);
}

void Widget::updateDrinkButtons() {
    ui->buyCoffee->setEnabled(money >= 100);
    ui->buyTea->setEnabled(money >= 150);
    ui->buyMilk->setEnabled(money >= 200);
}
