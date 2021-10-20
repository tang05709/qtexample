import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Text {
        x: 60
        y: 100
        color: "green"
        font.pixelSize: 24
        text: "Hello Qt Quick"
    }
    Text {
        x: 60
        y: 140
        color: "green"
        font.pixelSize: 24
        text: "<b>Hello</b><i> Qt Quick</i>"
    }
    Text {
        x: 60
        y: 180
        color: "green"
        font.pixelSize: 24
        style: Text.Outline
        styleColor: "blue"
        text: "Hello Qt Quick"
    }
    Text {
        width: 200
        color: "green"
        font.pixelSize: 24
        horizontalAlignment: Text.AlignLeft
        verticalAlignment:  Text.AlignTop
        elide: Text.ElideRight
        text: "Hello Qt Quick"
    }
    Text {
        width: 200
        y: 30
        color: "green"
        font.pixelSize: 24
        horizontalAlignment: Text.AlignLeft
        wrapMode: Text.WrapAnywhere
        text: "Hello Qt Quick"
    }
}
