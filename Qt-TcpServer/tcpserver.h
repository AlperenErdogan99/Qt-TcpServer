#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QDebug>

class TcpServer : public QObject
{
    Q_OBJECT

public:

    QSharedPointer<QTcpServer> m_server;
    QString m_serverAddress;
    int m_serverPort;

public:
    explicit TcpServer(QObject *parent = nullptr);

public slots:
    void initialize();
    void setServerAddress(QString address);
    QString serverAddress();
    void setServerPort(int port);
    int serverPort();
    int startListenServer();

signals:
    void newConnectionDetected();
    void messageReceived(QByteArray message);

};

#endif // TCPSERVER_H
