#ifndef COMTCP_H
#define COMTCP_H

#include <QString>
#include <QTcpSocket>
#include <QHostAddress>
#include <QAbstractSocket>

class ComTcp : public QObject
{
    Q_OBJECT
private:
    QTcpSocket *socket;
    QByteArray buffer;
    QString     ip;
    quint16     port;
    int        isConnected;
private slots:
    void readyRead();
    void setConnected();
    void setDisconnected();

public:
    explicit ComTcp(QObject *parent = 0);
    void sendData(const QByteArray);
    void setIp(const QString);
    void setPort(quint16);
    bool getConnection();
    void connectToServer();
    void disconnectFromServer();
    enum QAbstractSocket::SocketState getState() const;
    int amIConnected();
};

#endif // COMTCP_H
