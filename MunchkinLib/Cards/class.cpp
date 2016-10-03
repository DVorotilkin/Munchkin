#include "class.h"
#include "shmatte.h"
#include "Entities/player.h"

Class::Class(uint id, QString name, bool type, Classes __class, QByteArray ability1, QByteArray ability2):
    Card(id, name, type), _class(__class), _ability1(ability1), _ability2(ability2){}

Classes Class::getClass() const
{
    return _class;
}

void Class::doAbility1()
{
    Action::doAction(_ability1);
}

void Class::doAbility2()
{
    Action::doAction(_ability2);
}

QByteArray Class::toByteArray()
{
    QByteArray result;
    result.append(_id);
    result.append(_description);
    result.append(_type);
    result.append(_class);
    result.append(_ability1);
    result.append(_ability2);
    return result;
}

bool Class::canAddtoTable(Player *player, QList<Card*>& errCards)
{
    if (player->superMunchkin && (player->getClass()[0] != Classes::NoClass) && player->getClass()[1] != Classes::NoClass)
    {
        emit error(1);
        return false;
    }
    if (!player->superMunchkin && player->getClass()[0] != Classes::NoClass)
    {
        emit error(1);
        return false;
    }
    for (auto i = player->table().begin(); i != player->table().end(); ++i)
    {
        Shmatte *shm = dynamic_cast<Shmatte*>(*i);
        if (shm == NULL)
            continue;
        if (shm->getClass() != player->getClass()[0] && shm->getClass() != player->getClass()[1])
            errCards.append((Card*)shm);
    }
    if (!errCards.empty())
    {
        emit error(5);
        return true;
    }
    return true;
}

void Class::fromJson(QJsonObject json)
{

}

QJsonObject Class::toJson()
{

}

QByteArray Class::ability2() const
{
    return _ability2;
}

QByteArray Class::ability1() const
{
    return _ability1;
}
