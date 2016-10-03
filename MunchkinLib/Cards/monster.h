#ifndef MONSTER_H
#define MONSTER_H

#include "munchkinlib_global.h"
#include "card.h"
#include "action.h"

class MUNCHKINLIBSHARED_EXPORT Monster : public Card
{
public:
    Monster(uint id, QString name, bool type, quint8 damage, quint8 lvl, QByteArray ability, QByteArray badStash);
    quint8 _damage;
    quint8 lvl() const;
    void doAbility();
    void doBadStash();

    QByteArray ability() const;

    QByteArray badStash() const;

    virtual QByteArray toByteArray();
    virtual bool canAddtoTable(Player *player, QList<Card*>& errCards);
    virtual void fromJson(QJsonObject json);
    virtual QJsonObject toJson();

private:
    quint8 _lvl;
    QByteArray _ability;
    QByteArray _badStash;
};

#endif // MONSTER_H
