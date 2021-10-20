import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Rectangle {
        property alias mouseArea: mouseArea
        property alias topRect: topRect
        width: 360
        height: 360
        MouseArea {
            id: mouseArea
            anchors.fill: parent
        }
        Rectangle {
            rotation: 45
            x: 40
            y: 60
            width: 100
            height: 100
            color: "red"
        }
        Rectangle {
            id: topRect
            opacity: 0.6
            scale: 0.8
            x: 135
            y: 60
            width: 100
            height: 100
            radius: 8
            gradient: Gradient {
                GradientStop { position: 0.0; color: "aqua" }
                GradientStop { position: 1.0; color: "teal" }
            }
            border {width: 3; color: "blue"}
        }
    }
}
