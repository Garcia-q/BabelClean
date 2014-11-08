#include <QApplication>
#include "ui.h"
#include "comtcp.h"

int main(int argc, char *argv[])
{
    ComTcp  *server;
    QApplication a(argc, argv);

    Ui client;
    server = new ComTcp();
    client.setServer(server);
    client.show();
    return a.exec();
}
