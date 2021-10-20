import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Extras 1.4

Item {
    width: 320
    height: 270

    property alias button1: button1
    property alias button2: button2
    property alias thermometer: thermometer

    ColumnLayout {
        anchors.centerIn: parent
        Gauge {
            id: thermometer
            minimumValue: 0
            value: 30
            maximumValue: 100
            anchors.centerIn: parent
        }
        Label {
            height: 15
        }
        Label {
            height: 15
        }
        RowLayout {
            Button {
                id: button1
                text: "升温"
            }
            Button {
                id: button2
                text: "降温"
            }
        }
    }
}
