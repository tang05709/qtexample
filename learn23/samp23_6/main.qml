import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Row {
        x: 25
        y: 25
        spacing: 10
        layoutDirection: Qt.RightToLeft
        RedRectangle {}
        GreenRectangle {}
        BlueRectangle {}
    }
    Column {
        x: 25
        y: 120
        spacing: 2
        RedRectangle {}
        GreenRectangle {}
        BlueRectangle {}
    }
    Grid {
        x: 40
        y: 120
        columns: 3
        spacing: 5
        RedRectangle {}
        GreenRectangle {}
        BlueRectangle {}
        RedRectangle {}
        BlueRectangle {}
    }
    Flow {
        anchors.fill: parent
        anchors.margins: 15
        spacing: 5
        RedRectangle {}
        GreenRectangle {}
        BlueRectangle {}
    }
}
