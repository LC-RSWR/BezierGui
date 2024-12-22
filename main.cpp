#include "beziergui.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BezierGui w;
    w.show();
    return a.exec();
}
