#include "servernetwork.h"

ServerNetwork::ServerNetwork(int port)
{
   /* server = new QTcpServer(this);
    if(!server->listen(QHostAddress::Any, port))
    {
        return;
    }
    connect(server, SIGNAL(newConnection()), this, SLOT(slotNewConnection()));
*/
}

void ServerNetwork::slotNewConnection()
{
  //  QTcpSocket* ClientSocket = server->nextPendingConnection();
    //connect(ClientSocket, SIGNAL(disconnected()),   ClientSocket,   SLOT(deleteLater())     );
   // connect(ClientSocket, SIGNAL(readyRead()),      this,           SLOT(slotReadClient())  );
}

