#include "monster.h"

Monster::Monster(uint id, QString name, bool type, quint8 lvl, quint8 damage, QByteArray ability, QByteArray badStash):
    Card(id, name, type), _lvl(lvl), _damage(damage), _ability(ability), _badStash(badStash){}

quint8 Monster::lvl() const
{
    return _lvl;
}

void Monster::doAbility()
{
    Action::doAction(_ability);
}

void Monster::doBadStash()
{
     Action::doAction(_badStash);
}
