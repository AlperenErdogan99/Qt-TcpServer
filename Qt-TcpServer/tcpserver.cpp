#include "tcpserver.h"

TcpServer::TcpServer(QObject *parent)
    : QObject{parent}
{

}

void TcpServer::initialize(){
    qDebug() << "Initialize tcpServer object";
    m_server.reset(new QTcpServer);
    connect(m_server.data(), &QTcpServer::newConnection, this, &TcpServer::newConnectionDetected);
}

void TcpServer::setServerAddress(QString address){
    qDebug() << "Set server address to " << address;
    m_serverAddress = address;
}

QString TcpServer::serverAddress(){
    return m_serverAddress;
}

void TcpServer::setServerPort(int port){
    qDebug() << "Set server port to " << port;
    m_serverPort = port;
}

int TcpServer::serverPort(){
    return m_serverPort;
}

int TcpServer::startListenServer(){
    qDebug() << "Listening Server...";
    QHostAddress tAdd;
    tAdd.setAddress(m_serverAddress);
    m_server->listen(tAdd, m_serverPort);
    return 0;
}
