#include "shmatte.h"
#include "../Entities/player.h"

Shmatte::Shmatte(uint id, QString name,QString description, quint8 bonus, Gender gender, Body limb, Races race, Classes __class, bool big, Classes incompatibleClass, QJsonObject ability):
    Card(id, name, description, false), _bonus(bonus), _gender(gender), _limb(limb), _race(race), _class(__class), _big(big), _incompatibleClass(incompatibleClass), _ability(ability){}

Shmatte::Shmatte(QJsonObject json) :
    Card(json)
{
    if (!json.contains("bonus") ||
        !json.contains("gender") ||
        !json.contains("limb") ||
        !json.contains("race") ||
        !json.contains("class") ||
        !json.contains("big") ||
        !json.contains("incompatibleClass") ||
        !json.contains("ability"))
    {
        emit error(8);
        return;
    }
    _bonus = json["bonus"].toInt();
    _gender = (Gender)json["gender"].toInt();
    _limb = (Body)json["limb"].toInt();
    _race = (Races)json["race"].toInt();
    _class = (Classes)json["class"].toInt();
    _big = (Races)json["big"].toBool();
    _incompatibleClass = (Classes)json["incompatibleClass"].toInt();
    _ability = json["ability"].toObject();
}


quint8 Shmatte::bonus() const
{
    return _bonus;
}

Races Shmatte::race() const
{
    return _race;
}

const QJsonObject Shmatte::ability() const
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

QByteArray Shmatte::toByteArray()
{
    QByteArray result = Card::toByteArray();
    result.append(_bonus);
    result.append(_gender);
    result.append(_race);
    result.append(_class);
    result.append(_big);
    result.append(_incompatibleClass);
    result.append(_limb);
    if (!_ability.empty())
        result.append(QJsonDocument(_ability).toBinaryData());
    return result;
}

bool Shmatte::canAddtoTable(Player *player, QList<Card*>& errCards)
{
    Q_UNUSED(errCards);
    if (_class != Classes::NoClass)
    {
        if ((player->superMunchkin) && (player->getClass()[0] != _class) && (player->getClass()[1] != _class))
        {
            emit error(1);
            return false;

        }
        if ((!player->superMunchkin) && (player->getClass()[0] != _class))
        {
            emit error(1);
            return false;
        }
    }
    if (_incompatibleClass != Classes::NoClass)//еcть несовместимые классы
    {
        if ((!player->superMunchkin) && (player->getClass()[0] == _incompatibleClass))
        {
            emit error(1);
            return false;
        }
    }
    if (_race != Races::NoRace)
    {
        if ((player->raceCocktail) && (player->race()[0] != _race) && (player->race()[1] != _race))
        {
            emit error(2);
            return false;
        }
        if ((!player->raceCocktail) && (player->race()[0] != _race))
        {
            emit error(1);
            return false;
        }
    }
    if (player->gender != _gender)
    {
        emit error(3);
        return false;
    }
    if ((_limb == Body::Hand) && (player->body()[Body::Hands] = true))
    {
        emit error(4);
        return false;
    }
    if ((_limb == Body::Hands) && (player->body()[Body::Hand] = true))
    {
        emit error(4);
        return false;
    }
    if (player->body()[_limb] == true)
    {
        emit error(4);
        return false;
    }
    if ((player->race()[0] != Races::Dwarf && player->race()[1] != Races::Dwarf) && _big && player->bigShmattes() > 0)
    {
        emit error(9);
        return false;
    }
    return true;
}
QJsonObject Shmatte::toJson()
{
    QJsonObject result = Card::toJson();
    result["bonus"] = QString::number(_bonus);
    result["gender"] = QString::number(_gender);
    result["limb"] = QString::number(_limb);
    result["race"] = QString::number(_race);
    result["class"] = QString::number(_class);
    result["big"] = QString::number(_big);
    result["incompatibleClass"] = QString::number(_incompatibleClass);
    result["ability"] = _ability;
    return result;
}

bool operator ==(const Shmatte &l, const Shmatte &r)
{
    if (!( (Card&)l == (Card&)r)) return false;
    if (l._bonus != r._bonus) return false;
    if (l._gender != r._gender) return false;
    if (l._limb != r._limb) return false;
    if (l._race != r._race) return false;
    if (l._class != r._class) return false;
    if (l._big != r._big) return false;
    if (l._incompatibleClass != r._incompatibleClass) return false;
    if (l._ability != r._ability) return false;
    return true;
}

