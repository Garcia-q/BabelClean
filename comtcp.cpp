#include "comtcp.h"
#include <iostream>

ComTcp::ComTcp(QObject *parent) :
    QObject(parent)
{
    socket = new QTcpSocket(this);
    ip = "127.0.0.1";
    port = 8888;
}


void ComTcp::connectToServer() {
    QHostAddress    ipAddress;

    ipAddress.setAddress(ip);
    std::cout << "Trying to connect to the server !" << std::endl;
    socket->connectToHost(ipAddress, port);
    std::cout << "Socket responded : " << getState() << std::endl;

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(socket, SIGNAL(connected()), this, SLOT(successConnect()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(successDisconnect()));

}

void ComTcp::disconnectFromServer() {
    std::cout << "Disconnected from the server" << std::endl;
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
    QByteArray yolo;

    yolo = socket->readAll();
    if (yolo.size() > 0) {
        std::cout << yolo.data() << std::endl;
    }
}

void ComTcp::successConnect() {
    std::cout << "Sucessfully connected!" << std::endl;
    emit clientConnected();
}

void ComTcp::successDisconnect() {
    std::cout << "Sucessfully disconnected!" << std::endl;
    emit clientDisconnected();
}
