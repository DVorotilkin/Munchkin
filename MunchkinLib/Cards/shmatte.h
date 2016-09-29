#ifndef SHMATTE_H
#define SHMATTE_H

#include "munchkinlib_global.h"
#include "race.h"
#include "class.h"

enum Body
{
    Nowhere = -1,
    Helmet,
    Footwear,
    Armor,
    Hand,
    Hands
};

enum Gender
{
    Girl,
    Boy,
    AnyGender
};

class MUNCHKINLIBSHARED_EXPORT Shmatte : public Card
{
public:
    Shmatte(uint id, QString name, bool type, quint8 bonus, Gender gender, Body limb, Races race, Classes __class, Classes incompatibleClass, QByteArray ability);
    quint8 bonus() const;
    Races race() const;
    Classes getClass() const;
    const QByteArray ability() const;
    void doAbility();
    Gender gender() const;
    Body limb() const;

    Classes incompatibleClass() const;

private:
    Gender _gender;
    quint8 _bonus;
    Races _race;
    Classes _class;
    Classes _incompatibleClass; //несовместимый класс
    QByteArray _ability;
    Body _limb; //конечность (куда одевается)
};

#endif // SHMATTE_H
