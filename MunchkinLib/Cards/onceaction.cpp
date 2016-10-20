#include "onceaction.h"

OnceAction::OnceAction(uint id, QString name, QString description, bool type, QJsonObject action):
    Card(id, name, description, type), _action(action){}

OnceAction::OnceAction(QJsonObject json) :
    Card(json), _action(json["action"].toObject())
{
    if (!json.contains("action"))
        emit error(8);
}

QJsonObject OnceAction::action() const
{
    return _action;
}

void OnceAction::doAction()
{
    Action::doAction(_action);
}

QByteArray OnceAction::toByteArray()
{
    QByteArray result = Card::toByteArray();
    if (!_action.isEmpty())
        result.append(QJsonDocument(_action).toBinaryData());
    return result;
}

bool OnceAction::canAddtoTable(Player *player, QList<Card *> &errCards)
{
    Q_UNUSED(errCards);
    Q_UNUSED(player);
    emit error(7);
    return false;
}

QJsonObject OnceAction::toJson()
{
    QJsonObject result = Card::toJson();
    result["action"] = _action;
    return result;
}

bool operator ==(const OnceAction &l, const OnceAction &r)
{
    if (!( (Card&)l == (Card&)r)) return false;
    if (l._action != r._action) return false;
    return true;
}
