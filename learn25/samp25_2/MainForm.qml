import QtQuick 2.0
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Item {
    width: 640
    height: 480
    property alias name: name // 姓名文本框
    property alias age: age // 年龄文本框
    property alias sex: sexGroup // 性别互斥选项框
    property alias spec: specBox // 专业组合框
    property alias hobby: hobbyGrid // 爱好GridLayout
    property alias submit: submit // 提交按钮
    property alias details: stuInfo // 基本信息文本区

   RowLayout {
       x: 50
       y: 35
       spacing: 10
       ColumnLayout {
           spacing: 8
           RowLayout {
               spacing: 0
               Label {
                 text: qsTr("姓名")
               }
               TextField {
                   id: name
                   placeholderText: qsTr("请输入...")
                   focus: true
               }
           }
           RowLayout {
               spacing: 0
               Label {
                 text: qsTr("年龄")
               }
               TextField {
                   id: age
                   placeholderText: qsTr("请年龄...")
                   validator: IntValidator { bottom: 16; top: 26 }
               }
           }
           GroupBox {
               id: sexGroup
               title: qsTr("性别")
               Layout.fillWidth: true


               RowLayout {
                   ButtonGroup { id: sexItem }
                   RadioButton {
                       text: qsTr("男")
                       checked: true
                       ButtonGroup.group: sexItem
                       Layout.minimumWidth: 65
                   }
                   RadioButton {
                       text: qsTr("女")
                       ButtonGroup.group: sexItem
                       Layout.minimumWidth: 65
                   }
               }
           }
           RowLayout {
               spacing: 0
               Label {
                   text: qsTr("专业")
               }
               ComboBox {
                   id: specBox
                   Layout.fillWidth: true
                   currentIndex: 0
                   model: ListModel {
                       ListElement { text: qsTr("计算机") }
                       ListElement { text: qsTr("通信工程") }
                       ListElement { text: qsTr("信息网络") }
                   }
                   width: 200
               }
           }
           GroupBox {
               id: groupHobby
               title: qsTr("爱好")
               Layout.fillWidth: true
               GridLayout {
                   id: hobbyGrid
                   columns: 3
                   CheckBox {
                       text: qsTr("旅游")
                   }
                   CheckBox {
                       text: qsTr("游泳")
                       checked: true
                   }
                   CheckBox {
                       text: qsTr("篮球")
                       checked: true
                   }
                   CheckBox {
                       text: qsTr("唱歌")
                       checked: true
                   }
                   CheckBox {
                       text: qsTr("舞蹈")
                       checked: true
                   }
                   CheckBox {
                       text: qsTr("网购")
                       checked: true
                   }
                   CheckBox {
                       text: qsTr("看电视")
                       checked: true
                   }
                   CheckBox {
                       text: qsTr("其他")
                       checked: true
                   }
               }
           }

           Button {
               id: submit
               text: qsTr("提交")
           }
       }

       ColumnLayout {
           Layout.alignment: Qt.AlignTop
           Label {
               text: qsTr("基本信息")
               font.pixelSize: 15
               font.bold: true
               wrapMode: Text.WordWrap
           }
           TextArea {
               id: stuInfo
               Layout.fillHeight: true
               width: 240
               text: qsTr("个人资料")
               font.pixelSize:  14
           }
       }
   }

}
