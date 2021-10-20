import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Grid {
        x: 25
        y: 25
        spacing: 4
        Repeater {
            model: 6
            Rectangle {
                width: 48
                height: 48
                color: "aqua"
                Text {
                    anchors.centerIn: parent
                    color: "black"
                    font.pointSize: 20
                    text: index
                }
            }
        }
    }
}
