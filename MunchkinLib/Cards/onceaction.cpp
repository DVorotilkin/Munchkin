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
    Q_UNUSED(errCards);
    Q_UNUSED(player);
    emit error(7);
    return false;
}

void OnceAction::fromJson(QJsonObject json)
{
    if (!json.contains("action"))
    {
        emit error(8);
        return;
    }
    Card::fromJson(json);
    _action = json["action"].toString().toUtf8(); //мб бага бага
}

QJsonObject OnceAction::toJson()
{
    QJsonObject result = Card::toJson();
    result["action"] = QString::fromUtf8(_action);
    return result;
}
