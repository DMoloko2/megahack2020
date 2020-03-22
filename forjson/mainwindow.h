#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QtNetwork/QNetworkAccessManager"
#include <QtNetwork/QNetworkReply>
#include <QByteArray>
#include <QTcpServer>
#include <QMessageBox>
#include <QTcpSocket>
#include <iostream>
#include <QString>
#include <QFile>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtWebSockets/QWebSocket>
#include <QtWebSockets/QWebSocketServer>
#include <QtSql>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager manager;
    QNetworkReply *reply;
    QUrl apiUrl;
    QByteArray requestString;
    void reqq(const char *);
    QTcpServer *m_ptcpServer;
    quint16 m_nNextBlockSize;
    void sendToClient(QTcpSocket* pSocket, const QString& str);
    void sendTelega(QByteArray);
    QTcpSocket soc;
    QByteArray *dataTel;
    std::vector<int> vec;
    QFile file;
    bool sqlConnect();
    QWebSocketServer *web;
    void processMessage(const QString &message);
    void socketDisconnected();
    void refreshDB();
    QTcpSocket* pClientSocket;
    int count=0;
    int typee;

public slots:
   void getReplyFinished();
   void onNewConnection();

   void slotReadClient ();
   void readyReadReply();
   void slotNewConnection();
   void slotReadyRead();
   void slotConnected();
   void slotError(QAbstractSocket::SocketError err);

private slots:
   void on_pushButton_clicked();
   void slot1(QStringList);

signals:
   void sig1(QStringList);

};

#endif // MAINWINDOW_H
