#include "monster.h"

Monster::Monster(uint id, QString name, bool type, quint8 lvl, quint8 damage, QByteArray ability, QByteArray badStash):
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

QByteArray Monster::ability() const
{
    return _ability;
}

QByteArray Monster::badStash() const
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
    result.append(_ability);
    result.append(_badStash);
    return result;
}

bool Monster::canAddtoTable(Player *player, QList<Card *> &errCards)
{
    emit error(6);
    return false;
}

void Monster::fromJson(QJsonObject json)
{

}

QJsonObject Monster::toJson()
{

}
