import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    TextBox {
        id: tbx1
        x: 25
        y: 25
        focus: true
        label: "学号"
        text: focus ? "" : "请输入内容..."
        KeyNavigation.tab: tbx2
    }
    TextBox {
        id: tbx2
        x: 25
        y: 60
        focus: true
        label: tr("姓名")
        text: focus ? "" : "请输入内容..."
        KeyNavigation.tab: tbx1
    }
}
