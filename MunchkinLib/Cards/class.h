#ifndef CLASS_H
#define CLASS_H

#include "munchkinlib_global.h"
#include "card.h"
#include "action.h"

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
    Class(uint id, QString name, bool type, Classes __class, QByteArray ability1, QByteArray ability2);
    Classes getClass() const;

    QByteArray ability1() const;
    void doAbility1();
    QByteArray ability2() const;
    void doAbility2();

private:
    Classes _class;
    QByteArray _ability1;
    QByteArray _ability2;
};

#endif // CLASS_H
