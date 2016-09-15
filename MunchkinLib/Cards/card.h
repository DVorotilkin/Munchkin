#ifndef CARD_H
#define CARD_H

#include "munchkinlib_global.h"

class MUNCHKINLIBSHARED_EXPORT Card
{

public:
    Card();
    Card(uint id, QString name, bool type);
    QString name() const;
    uint id() const;
    bool type() const;

private:
    QString _name;
    uint _id;
    bool _type; //Door - false, treasure - true

};

#endif // CARD_H
