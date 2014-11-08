#include "comtcp.h"

ComTcp::ComTcp(QObject *parent) :
    QObject(parent)
{
    socket = new QTcpSocket(this);
    ip = "127.0.0.1";
    port = 8888;
}


void ComTcp::connectToServer() {
    QHostAddress ipAddress;

    ipAddress.setAddress(ip);
    socket->connectToHost(ipAddress, port);

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(socket, SIGNAL(connected()), this, SLOT(successConnect()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(successDisconnect()));

}

void ComTcp::disconnectFromServer() {
    socket->disconnectFromHost();
}

void ComTcp::sendData(const QByteArray data) {
    if( socket->waitForConnected() ) {
        socket->write(data, data.size());
    }
}

void ComTcp::setIp(const QString ip) {
    this->ip = ip;
}

void ComTcp::setPort(quint16 port) {
    this->port = port;
}

enum QAbstractSocket::SocketState ComTcp::getState() const {
    return socket->state();
}

void ComTcp::readyRead() {
/*
    buffer.clear();
    buffer = socket->readAll();
    if (buffer.size() > 0)
        std::cout << "Message : " << buffer.data() << std::endl;
*/
}

void ComTcp::successConnect() {
    emit clientConnected();
}

void ComTcp::successDisconnect() {
    emit clientDisconnected();
}
