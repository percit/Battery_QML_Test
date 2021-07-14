import QtQuick 2.7
import QtQuick.Window 2.2
import CustomControls 1.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.1
import QtQuick.Controls.Material 2.12
import com.blikoon.batteryvalue 1.0//nasz url
Window {
    visible: true
    width: 700
    height: 700
    title: qsTr("Hello World")

    Rectangle {
        anchors.fill: parent
        color: "#1d1d35"
    }
    Battery{
        id: mBattery

    }
    Popup {
        id: popup
        anchors.centerIn: parent
        width: 400
        height: 100
        radius: 5
        modal: true
        focus: true
        Text {
            anchors.centerIn: parent
            id: textPopup
            text: qsTr("Device fully charged")
            font.family: "Halvetica"
            font.italic: false
            font.pointSize: 24
            color: "#1dc58f"
        }
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutsideParent
    }
    Column {
        id: layoutColumn
        anchors.centerIn: parent
        Row {
            anchors.horizontalCenter: parent.horizontalCenter
            Button{
            id: buttonCharge
            width: 300
            onClicked:{
                (mBattery.value == 100) ? popup.open() : ""
                mBattery.start()

            }
                Text {
                    anchors.centerIn: parent
                    id: textCharge
                    text: qsTr("Charge device")
                    font.family: "Halvetica"
                    font.italic: false
                    font.pointSize: 24
                    color: "#1dc58f"
                }

            }
        }
        Row {
            id: layout
            //spacing: 30
            RadialBar {
                anchors.horizontalCenter: buttonCharge.horizontalCenter
                width: 300
                height: 300
                penStyle: Qt.RoundCap
                dialType: RadialBar.FullDial
                progressColor: "#1dc58f"
                foregroundColor: "#191a2f"
                dialWidth: 30
                startAngle: 180
                spanAngle: 70
                minValue: 0
                maxValue: 100
                value: mBattery.value
                textFont {
                    family: "Halvetica"
                    italic: false
                    pointSize: 16
                }
                Image{
                    anchors.centerIn: parent
                    width: 200; height: 200
                    source: "/pics/battery1.svg"
                }

                suffixText: "%"
                textColor: "#FFFFFF"
            }
        }
    }
}
