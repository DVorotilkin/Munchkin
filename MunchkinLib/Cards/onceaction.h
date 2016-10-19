#ifndef ONCEACTION_H
#define ONCEACTION_H

#include "../munchkinlib_global.h"
#include "card.h"
#include "action.h"

class MUNCHKINLIBSHARED_EXPORT OnceAction : Card
{
public:
    OnceAction(uint id, QString name, QString description, bool type, QJsonObject action);
    OnceAction();
    QJsonObject action() const;
    void doAction();
    virtual QByteArray toByteArray();
    virtual bool canAddtoTable(Player *player, QList<Card*>& errCards);
    virtual bool fromJson(QJsonObject json);
    virtual QJsonObject toJson();
    friend bool operator ==(const OnceAction &l, const OnceAction &r);

private:
    QJsonObject _action;
};

#endif // ONCEACTION_H
