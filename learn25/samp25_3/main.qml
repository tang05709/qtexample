import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    MainForm {
        anchors.fill: parent
        size.onValueChanged: {
            var scale = size.value;
            img.width = 640 * scale
            img.height = 430 * scale
        }
        colourful.onCheckedChanged: {
            desat.desaturation = colourful.checked ? 0.0 : 1.0
        }
        btn.onClicked: {
            if (desat.desaturation < 0.9) {
                desat.desaturation += 0.1

            } else {
                desat.desaturation = 0.0
            }
            progreBar.value = desat.desaturation
        }
    }
}
