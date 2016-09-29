#include "shmatte.h"

Shmatte::Shmatte(uint id, QString name, bool type, quint8 bonus, Gender gender, Body limb, Races race, Classes __class, Classes incompatibleClass, QByteArray ability):
    Card(id, name, type), _bonus(bonus), _gender(gender), _limb(limb), _race(race), _class(__class), _incompatibleClass(incompatibleClass), _ability(ability){}

quint8 Shmatte::bonus() const
{
    return _bonus;
}

Races Shmatte::race() const
{
    return _race;
}

const QByteArray Shmatte::ability() const
{
    return _ability;
}

void Shmatte::doAbility()
{
    Action::doAction(_ability);
}

Gender Shmatte::gender() const
{
    return _gender;
}

Body Shmatte::limb() const
{
    return _limb;
}

Classes Shmatte::incompatibleClass() const
{
    return _incompatibleClass;
}

Classes Shmatte::getClass() const
{
    return _class;
}
