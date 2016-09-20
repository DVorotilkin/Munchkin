#ifndef SHMATTE_H
#define SHMATTE_H

#include "munchkinlib_global.h"
#include "race.h"
#include "class.h"

class MUNCHKINLIBSHARED_EXPORT Shmatte : public Card
{
public:
    Shmatte(uint id, QString name, bool type, quint8 bonus, Races race, Classes __class, QByteArray ability);
    quint8 bonus() const;

    Races race() const;

    Classes getClass() const;

    QByteArray ability() const;
    void doAbility();
private:
    quint8 _bonus;
    Races _rece;
    Classes _class;
    QByteArray _ability;
};

#endif // SHMATTE_H
