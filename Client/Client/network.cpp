#include "network.h"

Network::Network(QObject *parent) : QObject(parent)
{
    QJsonObject card;
    j["name"] = "Elf";
  QJson::parser parser;
  bool ok;
  QVariant result = parser.parse(json, &ok);
}
