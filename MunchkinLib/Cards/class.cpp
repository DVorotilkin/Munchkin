#include "class.h"
#include "shmatte.h"
#include "../Entities/player.h"

Class::Class(uint id, QString name, bool type, Classes __class, QJsonObject ability1, QJsonObject ability2):
    Card(id, name, type), _class(__class), _ability1(ability1), _ability2(ability2){}

Class::Class():
    Card(0, "", false),
    _class(Classes::NoClass),
    _ability1(),
    _ability2(){}

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
    result.append(QJsonDocument(_ability1).toBinaryData());
    result.append(QJsonDocument(_ability2).toBinaryData());
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
        if (shm->getClass() != _class)
            errCards.append((Card*)shm);
    }
    if (!errCards.empty())
    {
        emit error(5);
        return true;
    }
    return true;
}

bool Class::fromJson(QJsonObject json)
{
    if (!json.contains("class") ||
        !json.contains("ability1") ||
        !json.contains("ability2"))
    {
        emit error(8);
        return false;
    }
    if (!Card::fromJson(json))
        return false;
    _class = (Classes)json["class"].toInt();
    _ability1 = json["ability1"].toObject();
    _ability2 = json["ability2"].toObject();
    return true;
}

QJsonObject Class::toJson()
{
    QJsonObject result = Card::toJson();
    result["class"] = (int)_class;
    result["ability1"] = _ability1;
    result["ability2"] = _ability2;
    return result;
}

QJsonObject Class::ability2() const
{
    return _ability2;
}

QJsonObject Class::ability1() const
{
    return _ability1;
}
