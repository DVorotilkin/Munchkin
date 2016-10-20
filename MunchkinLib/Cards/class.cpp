#include "class.h"
#include "shmatte.h"
#include "../Entities/player.h"

Class::Class(uint id, QString name, QString description, Classes __class, QJsonObject ability1, QJsonObject ability2):
    Card(id, name, description, false), _class(__class), _ability1(ability1), _ability2(ability2){}

Class::Class(QJsonObject json):
    Card(json), _class((Classes)json["class"].toInt()), _ability1(json["ability1"].toObject()), _ability2(json["ability2"].toObject())
{
    if (!json.contains("class") ||
        !json.contains("ability1") ||
        !json.contains("ability2"))
        emit error(8);
}

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
    QByteArray result = Card::toByteArray();
    result.append(_class);
    if (!_ability1.isEmpty())
        result.append(QJsonDocument(_ability1).toBinaryData());
    if (!_ability2.isEmpty())
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

QJsonObject Class::toJson()
{
    QJsonObject result = Card::toJson();
    result["class"] = QJsonValue((int)_class);
    result["ability1"] = _ability1;
    result["ability2"] = _ability2;
    return result;
}

bool operator ==(const Class &l, const Class &r)
{
    if (!( (Card&)l == (Card&)r)) return false;
    if (l._class != r._class) return false;
    if (l._ability1 != r._ability1) return false;
    if (l._ability2 != r._ability2) return false;
    return true;
}

QJsonObject Class::ability2() const
{
    return _ability2;
}

QJsonObject Class::ability1() const
{
    return _ability1;
}
