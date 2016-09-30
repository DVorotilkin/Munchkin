#ifndef SERVERNETWORK_H
#define SERVERNETWORK_H


//#include "munchkinlib_global.h"
#include "../munchkinlib_global.h"
#include "network.h"

class MUNCHKINLIBSHARED_EXPORT ServerNetwork : public Network
{
    Q_OBJECT
public:
    ServerNetwork(int port = 1460);
private:
    //QTcpServer* server;
public slots:
    void slotNewConnection();
};

#endif // SERVERNETWORK_H
