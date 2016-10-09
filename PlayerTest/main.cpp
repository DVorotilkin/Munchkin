#include <QCoreApplication>
#include "../MunchkinLib/Entities/player.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Player p;
    return a.exec();
}
