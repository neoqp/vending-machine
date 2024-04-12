#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLCDNumber>
#include <QPushButton>
#include <QMessageBox>

class MyWidget : public QWidget {
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr);

private slots:
    void addMoney(int amount);
    void buyDrink(int index);
    void updateButtons();
    void updateDisplay();
    void showChange();

private:
    QLCDNumber *lcdNumber;
    QPushButton *drinkButtons[3];
    QPushButton *resetButton;
    int money = 0;
    QVector<int> amounts = {10, 50, 100, 500};
    QVector<int> drinkPrices = {100, 150, 200};
};

#endif // WIDGET_H
