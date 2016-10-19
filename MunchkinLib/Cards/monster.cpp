#include "monster.h"

Monster::Monster(uint id, QString name, QString description, quint8 lvl, quint8 damage, QJsonObject ability, QJsonObject badStash):
    Card(id, name, description, false), _damage(damage), _lvl(lvl), _ability(ability), _badStash(badStash){}

Monster::Monster() :
    Card(0, "", "", false),
    _damage(0),
    _lvl(0),
    _ability(),
    _badStash(){}

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
    QJsonObject result = Card::toJson();
    result["lvl"] = QString::number(_lvl);
    result["damage"] = QString::number(_damage);
    result["ability"] = _ability;
    result["badStash"] = _badStash;
    return result;
}

bool operator ==(const Monster &l, const Monster &r)
{
    if (!( (Card&)l == (Card&)r)) return false;
    if (l._lvl != r._lvl) return false;
    if (l._damage != r._damage) return false;
    if (l._ability != r._ability) return false;
    if (l._badStash != r._badStash) return false;
    return true;
}
