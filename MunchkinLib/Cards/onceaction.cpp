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
