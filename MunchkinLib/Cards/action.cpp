#include "action.h"

Action::Action()
{

}

bool Action::doAction(QByteArray action)
{
    QJsonParseError *err = NULL;
    QJsonDocument jsonAction = QJsonDocument::fromJson(action, err);
    if (err->error != QJsonParseError::NoError)
    {
        qDebug() << err->errorString();
        return false;
    }
    return true;
}
