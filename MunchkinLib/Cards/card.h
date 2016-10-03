#pragma once
#ifndef CARD_H
#define CARD_H

#include "munchkinlib_global.h"
//#include <Entities/player.h>
#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>

class Player;

class MUNCHKINLIBSHARED_EXPORT Card : public QObject
{
    Q_OBJECT

public:
    Card(uint id, QString name, bool type);
    QString name() const;
    uint id() const;
    bool type() const;
    QString description() const;
    virtual QByteArray toByteArray() = 0;
    virtual bool canAddtoTable(Player *player, QList<Card*>& errCards) = 0;
    virtual void fromJson(QJsonObject json) = 0;
    virtual QJsonObject toJson() = 0;

protected:
    QString _name;
    QString _description;
    uint _id;
    bool _type; //Door - false, treasure - true

signals:
    error(int);
};

#endif // CARD_H
