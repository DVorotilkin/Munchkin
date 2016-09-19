#ifndef MONSER_H
#define MONSER_H

#include "munchkinlib_global.h"
#include "card.h"
#include "action.h"

class MUNCHKINLIBSHARED_EXPORT Monser : public Card
{
public:
    Monser(uint id, QString name, bool type, quint8 lvl, quint8 damage, QByteArray ability, QByteArray badStash);
    quint8 _damage;
    quint8 lvl() const;
    void doAbility();
    void doBadStash();

private:
    quint8 _lvl;
    QByteArray _ability;
    QByteArray _badStash;
};

#endif // MONSER_H
