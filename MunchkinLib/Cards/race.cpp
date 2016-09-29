#include "race.h"

Race::Race(uint id, QString name, bool type, Races race, QByteArray ability):
    Card(id, name, type), _race(race), _ability(ability){}

Races Race::race() const
{
    return _race;
}

void Race::doAbility()
{
    Action::doAction(_ability);
}

QByteArray Race::ability() const
{
    return _ability;
}
