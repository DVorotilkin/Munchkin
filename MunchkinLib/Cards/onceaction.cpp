#include "onceaction.h"

OnceAction::OnceAction(uint id, QString name, QString description, bool type, QJsonObject action):
    Card(id, name, description, type), _action(action){}

OnceAction::OnceAction() :
    Card(0, "", "", false),
    _action(){}

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
    QByteArray result;
    result.append(_id);
    result.append(_description);
    result.append(_type);
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

bool OnceAction::fromJson(QJsonObject json)
{
    if (!json.contains("action"))
    {
        emit error(8);
        return false;
    }
    if (!Card::fromJson(json))
        return false;
    _action = json["action"].toObject();
    return true;
}

QJsonObject OnceAction::toJson()
{
    QJsonObject result = Card::toJson();
    result["action"] = _action;
    return result;
}

bool operator ==(const OnceAction &l, const OnceAction &r)
{

}
