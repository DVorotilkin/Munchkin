#pragma once
#ifndef SHMATTE_H
#define SHMATTE_H

#include "../munchkinlib_global.h"
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
    Shmatte(uint id, QString name, QString description, quint8 bonus, Gender gender, Body limb, Races race, Classes __class, bool big, Classes incompatibleClass, QJsonObject ability);
    Shmatte(QJsonObject json);
    quint8 bonus() const;
    Races race() const;
    Classes getClass() const;
    const QJsonObject ability() const;
    void doAbility();
    Gender gender() const;
    Body limb() const;
    Classes incompatibleClass() const;
    virtual QByteArray toByteArray();
    virtual bool canAddtoTable(Player *player, QList<Card*>& errCards);
    virtual QJsonObject toJson();
    friend bool operator ==(const Shmatte &l, const Shmatte &r);

private:
    quint8 _bonus;
    Gender _gender;
    Body _limb; //конечность (куда одевается)
    Races _race;
    Classes _class;
    bool _big;
    Classes _incompatibleClass; //несовместимый класс
    QJsonObject _ability;

};

#endif // SHMATTE_H
