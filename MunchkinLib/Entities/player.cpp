#include "player.h"

Player::Player():_hand(), _table(), _tap()
{
    lvl = damage = 1;
    runAwayChance = luck = 0;
    for (int i = 0; i < 5; ++i)
        _body[i] = 0;
    _race[0] = Races::Man;
    _race[1] = Races::Man;
    _class[0] = Classes::NoClass;
    _class[1] = Classes::NoClass;
    raceCocktail = superMunchkin = false;
    _gender = Gender::Boy;
}

bool Player::canAddCardToTable(Card *card, QList<Card*>& errCards)
{
    if (!_hand.contains(card))
    {
        emit error(404);
        return false;
    }
    return card->canAddtoTable(this, errCards);
}

void Player::addCardToTable(Card *card)
{
    if (Shmatte *tmp = dynamic_cast<Shmatte*>(card))
        {
            _hand.removeOne(card);
            _table.append(card);
            damage += tmp->bonus();
        }
    if (Class *tmp = dynamic_cast<Class*>(card))
        {
            if (_class[0] == Classes::NoClass)
                _class[0] = tmp->getClass();
            else
                _class[1] = tmp->getClass();
            for (auto i = _table.begin(); i != _table.end(); ++i)
            {
                Shmatte *shm = dynamic_cast<Shmatte*>(card);
                if (shm == NULL)
                    continue;
                if (shm->getClass() != _class[0] && shm->getClass() != _class[1])
                {
                    _hand.append((Card*)shm);
                    _table.removeOne((Card*)shm);
                }
            }
        }
    if (Race *tmp = dynamic_cast<Race*>(card))
        {
            if (_race[0] == Races::NoRace)
                _race[0] = tmp->race();
            else
                _race[1] = tmp->race();
            for (auto i = _table.begin(); i != _table.end(); ++i)
            {
                Shmatte *shm = dynamic_cast<Shmatte*>(card);
                if (shm == NULL)
                    continue;
                if (shm->race() != _race[0] && shm->race() != _race[1])
                {
                    _hand.append((Card*)shm);
                    _table.removeOne((Card*)shm);
                }
            }
        }
}

void Player::addCardToHand(Card *card)
{
    _hand.append(card);

}

QByteArray Player::toByteArray()
{
    QByteArray result;
    result.append(lvl);
    result.append(damage);
    result.append(runAwayChance);
    result.append(luck);
    result.append(raceCocktail);
    result.append(superMunchkin);
    result.append(_gender);
    result.append(_race[0]);
    result.append(_race[1]);
    result.append(_class[0]);
    result.append(_class[1]);
    for (int i = 0; i < 5; ++i)
        result.append(_body[i]);
    for (auto i = _hand.begin(); i != _hand.end(); ++i)
    {
        result.append((*i)->toByteArray());
    }
    for (auto i = _table.begin(); i != _table.end(); ++i)
    {
        result.append((*i)->toByteArray());
    }for (auto i = _tap.begin(); i != _tap.end(); ++i)
    {
        result.append((*i)->toByteArray());
    }
    return result;
}

QByteArray Player::getHash()
{
    return QCryptographicHash::hash(toByteArray(), QCryptographicHash::Md5);
}

Races *Player::race()
{
    return _race;
}

Classes *Player::getClass()
{
    return _class;
}

bool *Player::body()
{
    return _body;
}

QList<Card *> Player::table()
{
    return _table;
}

qint8 Player::bigShmattes() const
{
    return _bigShmattes;
}

