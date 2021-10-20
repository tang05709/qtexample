import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Image {
        x: 20
        y: 20
        width: 720
        height: 480
        source: "qrc:/images/test.jpg"
        fillMode: Image.PreserveAspectCrop
        clip: true

    }
}
