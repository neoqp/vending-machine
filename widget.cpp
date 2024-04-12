#include "widget.h"

MyWidget::MyWidget(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    lcdNumber = new QLCDNumber(this);
    lcdNumber->setDigitCount(6);
    layout->addWidget(lcdNumber);

    QGridLayout *gridLayout = new QGridLayout;
    layout->addLayout(gridLayout);

    QStringList buttons = {"10won", "50won", "100won", "500won"};
    for (int i = 0; i < buttons.size(); ++i) {
        QPushButton *button = new QPushButton(buttons[i], this);
        connect(button, &QPushButton::clicked, [this, i]() {
            addMoney(i);
        });
        gridLayout->addWidget(button, 0, i);
    }

    QStringList drinks = {"Coffee(100)", "Tea(150)", "Milk(200)"};
    for (int i = 0; i < drinks.size(); ++i) {
        QPushButton *button = new QPushButton(drinks[i], this);
        connect(button, &QPushButton::clicked, [this, i]() {
            buyDrink(i);
        });
        drinkButtons[i] = button;
        gridLayout->addWidget(button, 1, i);
    }

    resetButton = new QPushButton("Reset", this);
    connect(resetButton, &QPushButton::clicked, this, &MyWidget::showChange);
    layout->addWidget(resetButton);

    setLayout(layout);
    updateButtons();
}

void MyWidget::addMoney(int amount) {
    money += amounts[amount];
    updateButtons();
    updateDisplay();
}

void MyWidget::buyDrink(int index) {
    int price = drinkPrices[index];
    if (money >= price) {
        money -= price;
        updateButtons();
        updateDisplay();
    }
}

void MyWidget::updateButtons() {
    for (int i = 0; i < 3; ++i) {
        drinkButtons[i]->setEnabled(money >= drinkPrices[i]);
    }
}

void MyWidget::updateDisplay() {
    lcdNumber->setStyleSheet("background-color: white;");
    lcdNumber->display(money);
}

void MyWidget::showChange() {
    QMessageBox msgBox;
    msgBox.setWindowTitle("money");
    QString message = QString("500won: %1\n100won: %2\n50won: %3\n10won: %4")
                          .arg(money / 500).arg((money % 500) / 100).arg((money % 100) / 50).arg((money % 50) / 10);
    msgBox.setText(message);
    msgBox.exec();
    money=0;
    updateDisplay();
    updateButtons();
}
