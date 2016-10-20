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
    const quint8 _bonus;
    const Gender _gender;
    const Body _limb; //конечность (куда одевается)
    const Races _race;
    const Classes _class;
    const bool _big;
    const Classes _incompatibleClass; //несовместимый класс
    const QJsonObject _ability;

};

#endif // SHMATTE_H
