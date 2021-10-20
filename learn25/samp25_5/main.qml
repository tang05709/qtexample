import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Dialogs 1.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    MainForm {
        id: main
        anchors.fill: parent
        btnSelect.onClicked: dateDialog.open()
        btnOpen.onClicked: fileDialog.open()
        btnFont.onClicked: fontDialog.open()
        btnColor.onClicked: colorDialog.open()

    }

    Dialog {
        id: dateDialog
        title: "选择日期"
        width: 275
        height: 300
        standardButtons: StandardButton.Save | StandardButton.Cancel
        onAccepted: main.date.text = '2021-5-5'

    }

    FileDialog {
        id: fileDialog
        title: "打开"
        nameFilters: ["Text files(*.txt)", "Image files(*.jpg *.png)", "All files(*)"]
        onAccepted: main.file.text = fileDialog.fileUrl
    }

    FontDialog {
        id: fontDialog
        title: "字体"
        width: 250
        height: 200
        font: Qt.font({ family: "宋体", pointSize: 18, weight: Font.Bold })
        modality: Qt.WindowModal
        onAccepted: main.content.font = fontDialog.font
    }

    ColorDialog {
        id: colorDialog
        title: "颜色"
        width: 250
        height: 200
        modality: Qt.WindowModal
        onAccepted: main.content.color = colorDialog.color
    }
}
