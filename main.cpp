#include <QApplication>
#include "widget.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MyWidget widget;
    widget.setWindowTitle("Vending Machine");
    widget.show();
    return app.exec();
}
