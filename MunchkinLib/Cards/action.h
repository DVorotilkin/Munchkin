#ifndef ACTION_H
#define ACTION_H

#include <QObject>
#include "munchkinlib_global.h"

class MUNCHKINLIBSHARED_EXPORT Action : QObject
{

public:
    Action();
    virtual doAction1() = 0;

};

#endif // ACTION_H
