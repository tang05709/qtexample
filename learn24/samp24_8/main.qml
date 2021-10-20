import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Extras 1.4

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle {
        property alias mouseArea: mouseArea
        property alias textEdit: textEdit

        width: 360
        height: 360

        MouseArea {
           id: mouseArea
           anchors.fill: parent
           acceptedButtons: Qt.RightButton
           onClicked: {
               pieMenu.popup(mouseArea.mouseX, mouseArea.mouseY)
           }
        }
        PieMenu {
             id: pieMenu
             triggerMode: TriggerMode.TriggerOnRelease

             MenuItem {
                 text: qsTr("首页")
                 onTriggered: print(qsTr("首页"))
             }
             MenuItem {
                 text: qsTr("产品")
                 onTriggered: print(qsTr("产品"))
             }
             MenuItem {
                 text: qsTr("文章")
                 onTriggered: print(qsTr("文章"))
             }
        }
        TextEdit {
            id: textEdit
            text: qsTr("右键鼠标")
            verticalAlignment: Text.AlignVCenter
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.topMargin: 200
            Rectangle {
                anchors.fill: parent
                anchors.margins: -10
                color: "transparent"
                border.width: 1
            }
        }
    }



}
