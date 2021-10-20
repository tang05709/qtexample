import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Item {
    width: 320
    height: 280

    property alias date: date // 日期
    property alias btnSelect: btnSelect // 选择按钮
    property alias file: file // 文件
    property alias btnOpen: btnOpen // 打开
    property alias content: content // 文本框
    property alias btnFont: btnFont // 字体
    property alias btnColor: btnColor // 颜色

    ColumnLayout {
        anchors.centerIn: parent
        RowLayout {
            Label {
                text: "日期"
            }
            TextField {
                id: date
            }
            Button {
                id: btnSelect
                text: "选择"
            }
        }
        RowLayout {
            Label {
                text: "文件"
            }
            TextField {
                id: file
            }
            Button {
                id: btnOpen
                text: "打开"
            }
        }
        TextArea {
            id: content
            Layout.fillWidth: true
            text: "Hello world"
            font.pixelSize: 14

        }
        RowLayout {
            Layout.alignment: Qt.AlignRight
            Button {
                id: btnFont
                text: "字体"
            }
            Button {
                id: btnColor
                text: "颜色"
            }
        }
    }
}
