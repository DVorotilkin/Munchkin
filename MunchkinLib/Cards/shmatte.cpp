#include "shmatte.h"
#include "Entities/player.h"

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
    result.append(_incompatibleClass);
    result.append(_limb);
    result.append(_ability);
    return result;
}

bool Shmatte::canAddtoTable(Player *player, QList<Card*>& errCards)
{
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
    if (player->_gender != _gender)
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
    return true;
}

void Shmatte::fromJson(QJsonObject json)
{

}

QJsonObject Shmatte::toJson()
{

}

Classes Shmatte::getClass() const
{
    return _class;
}
