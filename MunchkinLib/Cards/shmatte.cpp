#include "shmatte.h"
#include "Entities/player.h"

Shmatte::Shmatte(uint id, QString name, bool type, quint8 bonus, Gender gender, Body limb, Races race, Classes __class, bool big, Classes incompatibleClass, QJsonObject ability):
    Card(id, name, type), _bonus(bonus), _gender(gender), _limb(limb), _race(race), _class(__class), _big(big), _incompatibleClass(incompatibleClass), _ability(ability){}

Shmatte::Shmatte() :
    Card(0, "", false),
    _bonus(0),
    _gender(Gender::AnyGender),
    _limb(Body::Nowhere),
    _race(Races::NoRace),
    _class(Classes::NoClass),
    _big(false),
    _incompatibleClass(Classes::NoClass),
    _ability(){}

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

QByteArray Shmatte::toByteArray()
{
    QByteArray result;
    result.append(_id);
    result.append(_description);
    result.append(_type);
    result.append(_bonus);
    result.append(_gender);
    result.append(_race);
    result.append(_class);
    result.append(_big);
    result.append(_incompatibleClass);
    result.append(_limb);
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

bool Shmatte::fromJson(QJsonObject json)
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
        return false;
    }
    if (!Card::fromJson(json))
        return false;
    _bonus = json["bonus"].toInt();
    _gender = (Gender)json["gender"].toInt();
    _limb = (Body)json["limb"].toInt();
    _race = (Races)json["race"].toInt();
    _class = (Classes)json["class"].toInt();
    _big = (Races)json["big"].toBool();
    _incompatibleClass = (Classes)json["incompatibleClass"].toInt();
    _ability = json["ability"].toObject();
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

Classes Shmatte::getClass() const
{
    return _class;
}
