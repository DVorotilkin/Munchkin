#ifndef CARD_H
#define CARD_H

#include "munchkinlib_global.h"
#include <QObject>

class MUNCHKINLIBSHARED_EXPORT Card : public QObject
{
    Q_OBJECT

public:
    Card(uint id, QString name, bool type);
    QString name() const;
    uint id() const;
    bool type() const;
    QString description() const;

private:
    QString _name;
    QString _description;
    uint _id;
    bool _type; //Door - false, treasure - true

};

#endif // CARD_H
