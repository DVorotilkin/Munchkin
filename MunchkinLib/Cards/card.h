#ifndef CARD_H
#define CARD_H

#include "munchkinlib_global.h"
#include <QObject>

class MUNCHKINLIBSHARED_EXPORT Card : QObject
{
    Q_OBJECT

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
