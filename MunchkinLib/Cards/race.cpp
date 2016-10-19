#include "race.h"
#include "../Entities/player.h"

Race::Race(uint id, QString name, QString description, Races race, QJsonObject ability):
    Card(id, name, description, false), _race(race), _ability(ability){}

Race::Race() :
    Card(0, "", "", false),
    _race(Races::NoRace),
    _ability(){}

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
    QByteArray result;
    result.append(_id);
    result.append(_description);
    result.append(_type);
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

bool Race::fromJson(QJsonObject json)
{
    if (!json.contains("race") ||
        !json.contains("ability"))
    {
        emit error(8);
        return false;
    }
    if (!Card::fromJson(json))
        return false;
    _race = (Races)json["race"].toInt();
    _ability = json["ability"].toObject();
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

