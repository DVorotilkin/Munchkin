#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>

class Network : public QObject
{
    Q_OBJECT
public:
    explicit Network(QObject *parent = 0);
    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;

signals:

public slots:
};

#endif // NETWORK_H
