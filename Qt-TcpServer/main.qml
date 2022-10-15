import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

import TcpServer 1.0

Window {
    width: 320
    height: 240
    visible: true
    title: qsTr("Simple Tcp Server")

    TcpServer{
        id: tcpServer
        onNewConnectionDetected: {
            console.log("New connection detected");
        }
        Component.onCompleted: {
            tcpServer.initialize();
            tcpServer.setServerAddress("127.0.0.1");
            tcpServer.setServerPort(80);
        }
    }

    Text {
        id: tcpServerText
        text: qsTr("Click button for listening")
        width: 150
        height: 70
        anchors.centerIn: parent
        anchors.verticalCenterOffset: -50
    }

    Button{
        id: startListenButton
        width: 100
        height: 100
        anchors.centerIn: parent
        onClicked: {
            tcpServer.startListenServer()
        }

        background: Rectangle {
            color: parent.down ? "#94e2d8" : (parent.hovered ? "#94e2a4" : "#b8e2ce")
        }
    }
}
