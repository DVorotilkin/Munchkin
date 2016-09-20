#ifndef ACTION_H
#define ACTION_H

#include <QObject>
#include <QDebug>
#include <QJsonDocument>
#include <QByteArray>
#include "munchkinlib_global.h"

class MUNCHKINLIBSHARED_EXPORT Action : QObject
{

public:
    Action();
    static bool doAction(QByteArray action);

};

#endif // ACTION_H