import QtQuick 2.12
import QtQuick.Window 2.12
import QtQml 2.12
import QtQuick.Controls 2.12
import Sensor 1.0


Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    property int sensorValue: 0
    property int sensorValue2 : 0
    property bool connectionState: false

    property double lati
    property double longi
    property double heading
    property double pitch
    property double roll
    property double speed
    property double alt
    property double vbat
    property string time
    property double signalx

    property string dataAll

    Sensor{
        id: sens
    }

    Button {
        id: btnConnect
        width: 100
        height: 50
        onPressed: {
            btnConnect.width = 100*0.85
            btnConnect.height = 50*0.85
              btnConnect.text = "Connect"
        }

        onReleased: {
            btnConnect.width = 100
            btnConnect.height = 50
            connectionState = Serial.getConnectingState();
//             btnConnect.text = "Disconect"
            if (connectionState == true) {
                Serial.disconnectDevice()
                btnConnect.text = "Connect"
            } else {
                if(Serial.connectDevice()) {
                    btnConnect.text = "Disconnect"
                }
            }
        }
    }

    Text {
        id: text
        text: qsTr("Test Hello ")
        font.pixelSize: 30
        color: "red"
        anchors.centerIn: parent

    }

    Text {
        id: longi
        x: 100
        y: 100
//        anchors.top: text.bottom
//        anchors.horizontalCenter: text.horizontalCenter
//        anchors.topMargin: 10
//        font.pixelSize: 50
        text: longi
    }
    Text {
        id: lati
        x: 100
        y: 200
//        anchors.top: text.bottom
//        anchors.horizontalCenter: text.horizontalCenter
//        anchors.topMargin: 10
        font.pixelSize: 50
        text: lati
    }
    Timer{
        id: timer
        interval: 1000
        repeat: true
        running: true
        onTriggered: {
            dataAll = Serial.getData()
            const myData = dataAll.split(",")
            console.log(myData[0])
            lati = Number(myData[0])
//            longi = Number(myData[1])
//            heading = Number(myData[2])
//            pitch = Number(myData[3])
//            roll = Number(myData[4])
//            speed = Number(myData[5])
//            alt = Number(myData[6])
//            vbat = Number(myData[7])
//            time = myData[8]
//            signalx = Number(myData[9])

//            sensorValue = sens.getsensorValue()
//            sensorValue2 = Sensor2.getsensorValue()
//            console.log("CONSOLE :" + Serial.getData())

        }
    }

}
