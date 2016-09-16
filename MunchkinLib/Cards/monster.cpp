#include "monster.h"

Monser::Monser(uint id, QString name, bool type, quint8 lvl, quint8 damage, QByteArray ability, QByteArray badStash):
    Card(id, name, type), _lvl(lvl), _damage(damage), _ability(ability), _badStash(badStash){}

quint8 Monser::lvl() const
{
    return _lvl;
}

void Monser::doAbility()
{
    Action::doAction(_ability);
}

void Monser::doBadStash()
{
     Action::doAction(_badStash);
}
