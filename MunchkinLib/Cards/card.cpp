#include "card.h"

Card::Card(uint id, QString name, bool type)
{
    _id = id;
    _name = name;
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
    if (!json.contains("id") || !json.contains("description") ||!json.contains("type"))
    {
        emit error(8);
        return false;
    }
    _id = json["id"].toInt();
    _description = json["description"].toString();
    _type = json["type"].toBool();
    return true;
}

QJsonObject Card::toJson()
{
    QJsonObject result;
    result["id"] = QString::number(_id);
    result["description"] = _description;
    result["type"] = QString::number(_type);
    return result;
}
