#include <QApplication>
#include "widget.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Widget widget;
    widget.setWindowTitle("Vending Machine");
    widget.show();
    return app.exec();
}
