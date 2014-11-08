#include "ui.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QBuffer>
#include <QSpinBox>

Ui::Ui(QWidget* parent)
: QWidget(parent)
{
    QVBoxLayout* main	= new QVBoxLayout(this);
    QGridLayout* top	= new QGridLayout;

    QLabel* label	= new QLabel("Server:", this);
    serverIp		= new QLineEdit(this);
    port			= new QSpinBox(this);
    connect			= new QPushButton("Connect", this);
    port->setRange(1, 32767);
    port->setValue(6667);
    serverIp->setText("127.0.0.1");
    top->addWidget(label, 0, 0);
    top->addWidget(serverIp, 0, 1);
    top->addWidget(port, 0, 2);
    top->addWidget(connect, 1, 2);
    server = new ComTcp();

    main->addLayout(top);

    setLayout(main);

    parent->connect(connect, SIGNAL(clicked()), this, SLOT(toggleConnection()));
    parent->connect(server, SIGNAL(clientConnected()), this, SLOT(setConnected()));
    parent->connect(server, SIGNAL(clientDisconnected()), this, SLOT(setDisconnected()));

    setDisconnected();
}

Ui::~Ui()
{

}

void Ui::setServer(ComTcp *server) {
    this->server = server;
}

void Ui::setConnected()
{
    port->setEnabled(false);
    serverIp->setEnabled(false);
    connect->setText("Disconnect");
}

void Ui::setDisconnected()
{
    port->setEnabled(true);
    serverIp->setEnabled(true);
    connect->setText("Connect");
}

void Ui::toggleConnection()
{
    if (server->getState() == QAbstractSocket::UnconnectedState)
    {
        server->setIp(serverIp->text());
        server->setPort(port->value());
        server->connectToServer();
    }
    else
    {
        server->disconnectFromServer();
    }
}
