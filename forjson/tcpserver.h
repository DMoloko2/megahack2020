#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMessageBox>

class tcpServer
{
    Q_OBJECT

public:
    tcpServer();
    ~tcpServer();

private:
    QTcpServer *m_ptcpServer;
    quint16 m_nNextBlockSize;

public slots:
    void slotReadClient ();
};

#endif // TCPSERVER_H
