#pragma once
#ifndef CARD_H
#define CARD_H

#include "../munchkinlib_global.h"
#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>

class Player;

class MUNCHKINLIBSHARED_EXPORT Card : public QObject
{
    Q_OBJECT

public:
    Card(uint id, QString name, QString description, bool type);
    Card(QJsonObject json);
    QString name() const;
    uint id() const;
    bool type() const;
    QString description() const;
    virtual QByteArray toByteArray();
    virtual bool canAddtoTable(Player *player, QList<Card*>& errCards) = 0;
    virtual QJsonObject toJson();
    friend bool operator ==(const Card &l, const Card &r);

protected:
    QString _name;
    QString _description;
    uint _id;
    bool _type; //Door - false, treasure - true

signals:
    error(int);
};

#endif // CARD_H
