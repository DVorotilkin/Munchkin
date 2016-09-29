#include "class.h"

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

QByteArray Class::ability2() const
{
    return _ability2;
}

QByteArray Class::ability1() const
{
    return _ability1;
}
