#ifndef ONCEACTION_H
#define ONCEACTION_H

#include "munchkinlib_global.h"
#include "card.h"
#include "action.h"

class MUNCHKINLIBSHARED_EXPORT OnceAction : Card
{
public:
    OnceAction(uint id, QString name, bool type, QByteArray action);
    QByteArray action() const;
    void doAction();

private:
    QByteArray _action;
};

#endif // ONCEACTION_H
