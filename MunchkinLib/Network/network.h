#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
//#include <QTcpServer>
//#include <QTcpSocket>
#include "../munchkinlib_global.h"

class MUNCHKINLIBSHARED_EXPORT Network : public QObject
{
    Q_OBJECT
public:
    explicit Network(QObject *parent = 0);
private:
public slots:
};
#endif // NETWORK_H
