#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <QDebug>


class MyClient;

class MyServer : public QTcpServer
{
    Q_OBJECT

public:
    explicit MyServer(QWidget *widget = nullptr, QObject *parent = nullptr);
    bool doStartServer(QHostAddress addr, qint16 port);






private slots:
    void slotNewConnection();

};

#endif // MYSERVER_H
