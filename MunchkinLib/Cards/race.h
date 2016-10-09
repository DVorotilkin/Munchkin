#ifndef RACE_H
#define RACE_H

#include "../munchkinlib_global.h"
#include "card.h"
#include "action.h"

enum Races
{
        NoRace, //любая расса (для шмота)
        Man,
        Elf,
        Dwarf,
        Halfling
};

class MUNCHKINLIBSHARED_EXPORT Race : public Card
{
public:
    Race(uint id, QString name, bool type, Races race, QJsonObject ability);
    Race();
    Races race() const;
    void doAbility();
    QJsonObject ability() const;
    virtual QByteArray toByteArray();
    virtual bool canAddtoTable(Player *player, QList<Card*> &errCards);
    virtual bool fromJson(QJsonObject json);
    virtual QJsonObject toJson();

private:
    Races _race;
    QJsonObject _ability;
};

#endif // RACE_H
