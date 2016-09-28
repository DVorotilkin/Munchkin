#ifndef RACE_H
#define RACE_H

#include "munchkinlib_global.h"
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
    Race(uint id, QString name, bool type, Races race, QByteArray ability);
    Races race() const;
    void doAbility();
    QByteArray ability() const;

private:
    Races _race;
    QByteArray _ability;
};

#endif // RACE_H
