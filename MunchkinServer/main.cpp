#include <QCoreApplication>
#include "servernetwork.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ServerNetwork s;

    return a.exec();
}
