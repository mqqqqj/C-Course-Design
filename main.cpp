#include "intro.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    intro w;
    w.show();
    return a.exec();
}
