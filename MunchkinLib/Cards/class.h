#ifndef CLASS_H
#define CLASS_H

#include "munchkinlib_global.h"
#include "card.h"
#include "action.h"

class Shmatte;

enum Classes
{
        NoClass,
        Thief,
        Wizard,
        Warrior,
        Cleric
};

class MUNCHKINLIBSHARED_EXPORT Class : public Card
{
public:
    Class(uint id, QString name, bool type, Classes __class, QJsonObject ability1, QJsonObject ability2);
    Classes getClass() const;
    QJsonObject ability1() const;
    void doAbility1();
    QJsonObject ability2() const;
    void doAbility2();
    virtual QByteArray toByteArray();
    virtual bool canAddtoTable(Player *player, QList<Card*>& errCards);
    virtual bool fromJson(QJsonObject json);
    virtual QJsonObject toJson();

private:
    Classes _class;
    QJsonObject _ability1;
    QJsonObject _ability2;
};

#endif // CLASS_H
