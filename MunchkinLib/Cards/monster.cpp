#include "monster.h"

Monster::Monster(uint id, QString name, QString description, quint8 lvl, quint8 damage, QJsonObject ability, QJsonObject badStash):
    Card(id, name, description, false), _damage(damage), _lvl(lvl), _ability(ability), _badStash(badStash){}

Monster::Monster(QJsonObject json) :
    Card(json), _damage(json["damage"].toInt()), _lvl(json["lvl"].toInt()), _ability(json["ability"].toObject()), _badStash(json["badStash"].toObject())
{
    if (!json.contains("lvl") ||
        !json.contains("damage") ||
        !json.contains("ability") ||
        !json.contains("badStash"))
        emit error(8);
}

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
    QByteArray result = Card::toByteArray();
    result.append(_lvl);
    result.append(_damage);
    if (!_ability.isEmpty())
        result.append(QJsonDocument(_ability).toBinaryData());
    if (!_badStash.isEmpty())
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

QJsonObject Monster::toJson()
{
    QJsonObject result = Card::toJson();
    result["lvl"] = QJsonValue((int)_lvl);
    result["damage"] = QJsonValue((int)_damage);
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
