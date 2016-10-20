#ifndef ONCEACTION_H
#define ONCEACTION_H

#include "../munchkinlib_global.h"
#include "card.h"
#include "action.h"

class MUNCHKINLIBSHARED_EXPORT OnceAction : Card
{
public:
    OnceAction(uint id, QString name, QString description, bool type, QJsonObject action);
    OnceAction(QJsonObject json);
    QJsonObject action() const;
    void doAction();
    virtual QByteArray toByteArray();
    virtual bool canAddtoTable(Player *player, QList<Card*>& errCards);
    virtual QJsonObject toJson();
    friend bool operator ==(const OnceAction &l, const OnceAction &r);

private:
    QJsonObject _action;
};

#endif // ONCEACTION_H
