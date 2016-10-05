#include "monster.h"

Monster::Monster(uint id, QString name, bool type, quint8 lvl, quint8 damage, QJsonObject ability, QJsonObject badStash):
    Card(id, name, type), _damage(damage), _lvl(lvl), _ability(ability), _badStash(badStash){}

quint8 Monster::lvl() const
{
    return _lvl;
}

void Monster::doAbility()
{
    Action::doAction(_ability);
}

void Monster::doBadStash()
{
     Action::doAction(_badStash);
}

QJsonObject Monster::ability() const
{
    return _ability;
}

QJsonObject Monster::badStash() const
{
    return _badStash;
}

QByteArray Monster::toByteArray()
{
    QByteArray result;
    result.append(_id);
    result.append(_description);
    result.append(_type);
    result.append(_lvl);
    result.append(_damage);
    result.append(QJsonDocument(_ability).toBinaryData());
    result.append(QJsonDocument(_badStash).toBinaryData());
    return result;
}

bool Monster::canAddtoTable(Player *player, QList<Card *> &errCards)
{
    Q_UNUSED(errCards);
    Q_UNUSED(player);
    emit error(6);
    return false;
}

bool Monster::fromJson(QJsonObject json)
{
    if (!json.contains("lvl") ||
        !json.contains("damage") ||
        !json.contains("ability") ||
        !json.contains("badStash"))
    {
        emit error(8);
        return false;
    }
    if (!Card::fromJson(json))
        return false;
    _lvl = json["lvl"].toInt();
    _damage = json["damage"].toInt();
    _ability = json["ability"].toObject();
    _badStash = json["badStash"].toObject();
    return true;
}

QJsonObject Monster::toJson()
{

}
