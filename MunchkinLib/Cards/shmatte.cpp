#include "shmatte.h"

Shmatte::Shmatte(uint id, QString name, bool type, quint8 bonus, Races race, Classes __class, QByteArray ability):
    Card(id, name, type), _bonus(bonus), _race(race), _class(__class), _ability(ability){}

quint8 Shmatte::bonus() const
{
    return _bonus;
}

Races Shmatte::race() const
{
    return _race;
}

QByteArray Shmatte::ability() const
{
    return _ability;
}

void Shmatte::doAbility()
{
    Action::doAction(_ability);
}

Classes Shmatte::getClass() const
{
    return _class;
}
