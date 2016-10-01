#include "player.h"

Player::Player():_hand(), _table(), _tap()
{
    _lvl = _damage = 1;
    _runAwayChance = _luck = 0;
    for (int i = 0; i < 5; ++i)
        _body[i] = 0;
    _race[0] = Races::Man;
    _race[1] = Races::Man;
    _class[0] = Classes::NoClass;
    _class[1] = Classes::NoClass;
    _raceCocktail = _superMunchkin = false;
    _gender = Gender::Boy;
}

bool Player::canAddCardToTable(Card *card, QList<Card*>& errCards)
{
    if (!_hand.contains(card)) //exeption бы
    {
        emit error(404);
        return false;
    }
    if (Shmatte *tmp = dynamic_cast<Shmatte*>(card))
        return isShmatteValid(tmp);

    if (Class *tmp = dynamic_cast<Class*>(card))
    {
        if (!isClassValid(tmp))
            return false;
        for (auto i = _table.begin(); i != _table.end(); ++i)
        {
            Shmatte *shm = dynamic_cast<Shmatte*>(card);
            if (shm == NULL)
                continue;
            if (shm->getClass() != _class[0] && shm->getClass() != _class[1])
                errCards.append((Card*)shm);
        }
        if (!errCards.empty())
        {
            emit error(5);
            return true;
        }
    }

    if (Race *tmp = dynamic_cast<Race*>(card))
    {
        if (!isRaceValid(tmp))
            return false;
        for (auto i = _table.begin(); i != _table.end(); ++i)
        {
            Shmatte *shm = dynamic_cast<Shmatte*>(card);
            if (shm == NULL)
                continue;
            if (shm->race() != _race[0] && shm->race() != _race[1])
                errCards.append((Card*)shm);
        }
        if (!errCards.empty())
        {
            emit error(5);
            return true;
        }
    }

    if (Monster *tmp = dynamic_cast<Monster*>(card))
    {
        emit error(6);
        return false;
    }
    if (OnceAction *tmp = dynamic_cast<OnceAction*>(card))
    {
        emit error(7);
        return false;
    }
    return true;
}

void Player::addCardToTable(Card *card)
{
    if (Shmatte *tmp = dynamic_cast<Shmatte*>(card))
        {
            _hand.removeOne(card);
            _table.append(card);
            _damage += tmp->bonus();
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

bool Player::isShmatteValid(Shmatte *shmatte)
{
    if (shmatte->getClass() != Classes::NoClass)
    {
        if ((_superMunchkin) && (_class[0] != shmatte->getClass()) && (_class[1] != shmatte->getClass()))
        {
            emit error(1);
            return false;

        }
        if ((!_superMunchkin) && (_class[0] != shmatte->getClass()))
        {
            emit error(1);
            return false;
        }
    }
    if (shmatte->incompatibleClass() != Classes::NoClass)//еcть несовместимые классы
    {
        if ((!_superMunchkin) && (_class[0] == shmatte->incompatibleClass()))
        {
            emit error(1);
            return false;
        }
    }
    if (shmatte->race() != Races::NoRace)
    {
        if ((_raceCocktail) && (_race[0] != shmatte->race()) && (_race[1] != shmatte->race()))
        {
            emit error(2);
            return false;
        }
        if ((!_raceCocktail) && (_race[0] != shmatte->race()))
        {
            emit error(1);
            return false;
        }
    }
    if (_gender != shmatte->gender())
    {
        emit error(3);
        return false;
    }
    if ((shmatte->limb() == Body::Hand) && (_body[Body::Hands] = true))
    {
        emit error(4);
        return false;
    }
    if ((shmatte->limb() == Body::Hands) && (_body[Body::Hand] = true))
    {
        emit error(4);
        return false;
    }
    if (_body[shmatte->limb()] == true)
    {
        emit error(4);
        return false;
    }
    return true;

}

bool Player::isClassValid(Class *__class)
{
    if (_superMunchkin && (_class[0] != Classes::NoClass) && _class[1] != Classes::NoClass)
    {
        emit error(1);
        return false;
    }
    if (!_superMunchkin && _class[0] != Classes::NoClass)
    {
        emit error(1);
        return false;
    }
    return true;
}

bool Player::isRaceValid(Race *race)
{
    if (_raceCocktail && (_race[0] != Races::NoRace) && _race[1] != Races::NoRace)
    {
        emit error(2);
        return false;
    }
    if (!_raceCocktail && _race[0] != Races::NoRace)
    {
        emit error(2);
        return false;
    }
    return true;
}

QByteArray Player::getHash()
{
    return QCryptographicHash::hash(toByteArray(), QCryptographicHash::Md5);
}

QByteArray Player::cardToByteArray(Card *card)
{
    QByteArray result;
    result.append(card->id());
    result.append(card->description());
    result.append(card->type());
    if (Shmatte *tmp = dynamic_cast<Shmatte*>(card))
    {
        result.append(tmp->bonus());
        result.append(tmp->gender());
        result.append(tmp->race());
        result.append(tmp->getClass());
        result.append(tmp->incompatibleClass());
        result.append(tmp->limb());
        result.append(tmp->ability());
    }
    if (Monster *tmp  = dynamic_cast<Monster*>(card))
    {
        result.append(tmp->lvl());
        result.append(tmp->_damage);
        result.append(tmp->ability());
        result.append(tmp->badStash());
    }
    if (Class *tmp  = dynamic_cast<Class*>(card))
    {
        result.append(tmp->getClass());
        result.append(tmp->ability1());
        result.append(tmp->ability2());
    }
    if (Race *tmp  = dynamic_cast<Race*>(card))
    {
        result.append(tmp->race());
        result.append(tmp->ability());
    }
    if (Race *tmp  = dynamic_cast<Race*>(card))
    {

    }
}

QByteArray Player::toByteArray()
{
    QByteArray input;
    input.append(_lvl);
    input.append(_damage);
    input.append(_runAwayChance);
    input.append(_luck);
    input.append(_raceCocktail);
    input.append(_superMunchkin);
    input.append(_gender);
    input.append(_race[0]);
    input.append(_race[1]);
    input.append(_class[0]);
    input.append(_class[1]);
    for (int i = 0; i < 5; ++i)
        input.append(_body[i]);
    for (auto i = _hand.begin(); i != _hand.end(); ++i)
    {
        input.append(cardToByteArray(*i));
    }
}
