import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle {
        property alias mouseArea: mouseArea
        property alias textEdit: textEdit
        property alias rect4: rect4

        width: 360
        height: 360
        MouseArea {
           id: mouseArea
           anchors.fill: parent
        }
        TextEdit {
            id: textEdit
            visible: false
        }
        Column {
            x: 50
            y: 30
            spacing: 5
            Rect1 {}
            Rect2 {}
            Rect3 {}
            Rect4 {id: rect4}
        }
    }
}
