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
