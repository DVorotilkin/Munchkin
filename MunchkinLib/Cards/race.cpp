#include "race.h"
#include "../Entities/player.h"

Race::Race(uint id, QString name, QString description, Races race, QJsonObject ability):
    Card(id, name, description, false), _race(race), _ability(ability){}

Race::Race(QJsonObject json) :
    Card(json)
{
    if (!json.contains("race") ||
        !json.contains("ability"))
    {
        emit error(8);
        return;
    }
    _race = (Races)json["race"].toInt();
    _ability = json["ability"].toObject();
}
Races Race::race() const
{
    return _race;
}

void Race::doAbility()
{
    Action::doAction(_ability);
}

QJsonObject Race::ability() const
{
    return _ability;
}

QByteArray Race::toByteArray()
{
    QByteArray result = Card::toByteArray();
    result.append(_race);
    if (!_ability.isEmpty())
        result.append(QJsonDocument(_ability).toBinaryData());
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
        if (shm->race() != _race && shm->race() != _race)
            errCards.append((Card*)shm);
    }
    if (!errCards.empty())
    {
        emit error(5);
        return true;
    }
    return true;
}

QJsonObject Race::toJson()
{
    QJsonObject result = Card::toJson();
    result["race"] = QJsonValue((int)_race);
    result["ability"] = _ability;
    return result;
}

bool operator ==(const Race &l, const Race &r)
{
    if (!( (Card&)l == (Card&)r)) return false;
    if (l._race != r._race) return false;
    if (l._ability != r._ability) return false;
    return true;
}

