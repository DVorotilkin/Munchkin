#ifndef MONSTER_H
#define MONSTER_H

#include "../munchkinlib_global.h"
#include "card.h"
#include "action.h"

class MUNCHKINLIBSHARED_EXPORT Monster : public Card
{
public:
    Monster(uint id, QString name, QString description, quint8 damage, quint8 lvl, QJsonObject ability, QJsonObject badStash);
    Monster(QJsonObject json);
    quint8 _damage;
    quint8 lvl() const;
    void doAbility();
    void doBadStash();

    QJsonObject ability() const;
    QJsonObject badStash() const;

    virtual QByteArray toByteArray();
    virtual bool canAddtoTable(Player *player, QList<Card*>& errCards);
    virtual QJsonObject toJson();
    friend bool operator ==(const Monster &l, const Monster &r);

private:
    const quint8 _lvl;
    const QJsonObject _ability;
    const QJsonObject _badStash;
};

#endif // MONSTER_H
