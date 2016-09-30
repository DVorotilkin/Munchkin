#ifndef CLIENTNETWORK_H
#define CLIENTNETWORK_H

#include "../munchkinlib_global.h"
#include "network.h"

class MUNCHKINLIBSHARED_EXPORT ClientNetwork : public Network
{
    Q_OBJECT
public:
    ClientNetwork();
    void Void();/*
private slots:
//определим слоты для обработки сигналов сокета
    void onSokConnected();
    void onSokDisconnected();
//сигнал readyRead вызывается, когда сокет получает пакет (который может быть лишь частью отправленых данных) байтов
    void onSokReadyRead();
    void onSokDisplayError(QAbstractSocket::SocketError socketError);
private:
    QTcpSocket *_sok; //сокет
    quint16 _blockSize;//текущий размер блока данных
    QString _name;//имя клиента
    */
};
#endif // CLIENTNETWORK_H
