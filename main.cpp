#include "test.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    my_test w;
    w.show();

    return a.exec();
}
