#include "onceaction.h"

OnceAction::OnceAction(uint id, QString name, bool type, QByteArray action):
    Card(id, name, type), _action(action){}

QByteArray OnceAction::action() const
{
    return _action;
}

void OnceAction::doAction()
{
    Action::doAction(_action);
}

QByteArray OnceAction::toByteArray()
{
    QByteArray result;
    result.append(_id);
    result.append(_description);
    result.append(_type);
    result.append(_action);
    return result;
}

bool OnceAction::canAddtoTable(Player *player, QList<Card *> &errCards)
{
    emit error(7);
    return false;
}

void OnceAction::fromJson(QJsonObject json)
{

}

QJsonObject OnceAction::toJson()
{

}
