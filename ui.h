#ifndef UI_H
#define UI_H

#include <QWidget>
#include "comtcp.h"

class QLineEdit;
class QSpinBox;
class QPushButton;

class Ui : public QWidget
{
    Q_OBJECT

public:
    Ui(QWidget* parent = 0);
    ~Ui();
    void setServer(ComTcp*);

private slots:
    void setConnected();
    void setDisconnected();
    void toggleConnection();

private:
    QLineEdit*		serverIp;
    QSpinBox*		port;
    QLineEdit*		pseudo;
    QPushButton*    connect;
    ComTcp*         server;
};

#endif // UI_H
