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
    quint8 _lvl;
    quint8 _damage;
    qint8 _runAwayChance;
    qint8 _luck;
    bool _raceCocktail;
    bool _superMunchkin;
    Gender _gender;
    bool canAddCardToTable(Card* card, QList<Card*>& errCards);
    void addCardToHand(Card *card);
    void addCardToTable(Card *card);
    QByteArray getHash();


private:
    QList<Card*> _hand;
    QList<Card*> _table;
    QList<Card*> _tap;
    Races _race[2];
    Classes _class[2];
    bool _body[5]; //по одному элементу на каждый элемент одежды
    bool isShmatteValid(Shmatte *shmatte);
    bool isClassValid(Class *__class);
    bool isRaceValid(Race *race);
    QByteArray cardToByteArray(Card *card);
    QByteArray toByteArray();

signals:
    void playerWin();
    void error(unsigned int err);
};

#endif // PLAYER_H
