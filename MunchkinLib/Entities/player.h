#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "Cards/shmatte.h"
#include "Cards/onceaction.h"
#include "Cards/monster.h"
#include <QList>
#include <QCryptographicHash>

class Player : public QObject
{
    Q_OBJECT
public:
    Player();
    quint8 lvl;
    quint8 damage;
    qint8 runAwayChance;
    qint8 luck;
    bool raceCocktail;
    bool superMunchkin;
    Gender _gender;
    bool canAddCardToTable(Card* card, QList<Card*>& errCards);
    void addCardToHand(Card *card);
    void addCardToTable(Card *card);
    QByteArray getHash();
    Races *race();
    Classes *getClass();
    bool* body();
    QList<Card *> table();


private:
    QList<Card*> _hand;
    QList<Card*> _table;
    QList<Card*> _tap;
    Races _race[2];
    Classes _class[2];
    bool _body[5]; //по одному элементу на каждый элемент одежды
    QByteArray cardToByteArray(Card *card);
    QByteArray toByteArray();

signals:
    void playerWin();
    void error(unsigned int err);
};

#endif // PLAYER_H
