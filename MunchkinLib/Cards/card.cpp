#include "card.h"

Card::Card(uint id, QString name, QString description, bool type)
{
    _id = id;
    _name = name;
    _description = description;
    _type = type;
}

QString Card::name() const
{
    return _name;
}

uint Card::id() const
{
    return _id;
}

bool Card::type() const
{
    return _type;
}

QString Card::description() const
{
    return _description;
}

bool Card::fromJson(QJsonObject json)
{
    if (!json.contains("id") || !json.contains("name") || !json.contains("description") ||!json.contains("type"))
    {
        emit error(8);
        return false;
    }
    _id = json["id"].toInt();
    _name = json["name"].toString();
    _description = json["description"].toString();
    _type = json["type"].toBool();
    return true;
}

QJsonObject Card::toJson()
{
    QJsonObject result;
    result["id"] = QJsonValue((int)_id);
    result["name"] = _name;
    result["description"] = _description;
    result["type"] = QJsonValue(_type);
    return result;
}

bool operator ==(const Card &l, const Card &r)
{
    if (l._id != r._id) return false;
    if (l._name != r._name) return false;
    if (l._description != r._description) return false;
    if (l._type != r._type) return false;
    return true;
}
