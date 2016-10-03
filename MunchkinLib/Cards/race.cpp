#include "race.h"
#include "Entities/player.h"

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

QByteArray Race::toByteArray()
{
    QByteArray result;
    result.append(_id);
    result.append(_description);
    result.append(_type);
    result.append(_race);
    result.append(_ability);
    return result;
}

bool Race::canAddtoTable(Player *player, QList<Card *> &errCards)
{
    if (player->raceCocktail && (player->race()[0] != Races::NoRace) && player->race()[1] != Races::NoRace)
    {
        emit error(2);
        return false;
    }
    if (!player->raceCocktail && player->race()[0] != Races::NoRace)
    {
        emit error(2);
        return false;
    }
    for (auto i = player->table().begin(); i != player->table().end(); ++i)
    {
        Shmatte *shm = dynamic_cast<Shmatte*>(*i);
        if (shm == NULL)
            continue;
        if (shm->race() != player->race()[0] && shm->race() != player->race()[1])
            errCards.append((Card*)shm);
    }
    if (!errCards.empty())
    {
        emit error(5);
        return true;
    }
    return true;
}

void Race::fromJson(QJsonObject json)
{

}

QJsonObject Race::toJson()
{

}
