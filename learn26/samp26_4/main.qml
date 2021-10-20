import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("选购图书")

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        Page1Form {
            ListView {
                id: listView
                anchors.fill: parent
                model: ListModel {
                    ListElement {
                        title: "java实用教程"
                        sender: "ISBN:a123 单价：￥49.00"
                    }
                    ListElement {
                        title: "Android实用教程"
                        sender: "ISBN:a456 单价：￥52.00"
                    }
                    ListElement {
                        title: "PHP实用教程"
                        sender: "ISBN:a789 单价：￥58.00"
                    }
                    ListElement {
                        title: "Python实用教程"
                        sender: "ISBN:a147 单价：￥65.00"
                    }
                    ListElement {
                        title: "Golang实用教程"
                        sender: "ISBN:a258 单价：￥35.00"
                    }
                    ListElement {
                        title: "C#实用教程"
                        sender: "ISBN:a369 单价：￥28.00"
                    }
                    ListElement {
                        title: "c++实用教程"
                        sender: "ISBN:a159 单价：￥65.00"
                    }
                }
                delegate: SwipeDelegate {
                    id: swipeDelegate
                    text: model.title + "-" + model.sender
                    width: parent.width
                    font.bold: true
                    font.pointSize: 12
                    onClicked: listView.currentIndex = index

                    ListView.onRemove: SequentialAnimation{
                        PropertyAction {
                            target: swipeDelegate
                            property: "ListView.delayRemove"
                            value: true
                        }
                        NumberAnimation {
                            target: swipeDelegate
                            property: "height"
                            to: 0
                            easing.type: Easing.InOutQuad
                        }
                        PropertyAction {
                            target: swipeDelegate
                            property: "ListView.delayRemove"
                            value: false
                        }
                    }

                    swipe.right: Row {
                        anchors.right: parent.right
                        height: parent.height
                        Label {
                            id: moveLabel
                            text: qsTr("购买")
                            color: "black"
                            font.pointSize: 12
                            verticalAlignment: Label.AlignVCenter
                            padding: 12
                            height: parent.height
                            SwipeDelegate.onClicked: {
                                switch (index) {
                                case 0: bookCover.source = "qrc:/images/images/pic640_1.jpg"; break;
                                case 1: bookCover.source = "qrc:/images/images/pic640_2.jpg"; break;
                                case 2: bookCover.source = "qrc:/images/images/pic640_3.jpg"; break;
                                case 3: bookCover.source = "qrc:/images/images/pic640_4.jpg"; break;
                                case 4: bookCover.source = "qrc:/images/images/pic640_5.jpg"; break;
                                case 5: bookCover.source = "qrc:/images/images/pic640_6.jpg"; break;
                                case 6: bookCover.source = "qrc:/images/images/pic640_7.jpg"; break;
                                default: break;
                                }
                            }
                            background: Rectangle {
                                color: moveLabel.SwipeDelegate.pressed ? Qt.darker("#ffbf47", 1.1) : "#ffbf47"
                            }
                        }
                        Label {
                            id: deleteLabel
                            text: qsTr("移除")
                            color: "black"
                            font.pointSize: 12
                            verticalAlignment: Label.AlignVCenter
                            padding: 12
                            height: parent.height
                            SwipeDelegate.onClicked: listView.model.remove(index)
                            background: Rectangle {
                                color: deleteLabel.SwipeDelegate.pressed ? Qt.darker("#tomato", 1.1) : "tomato"
                            }
                        }
                    }

                    RowLayout {
                        anchors.bottom: parent.bottom
                        anchors.horizontalCenter: parent.horizontalCenter
                        Image {
                            id: bookCover
                            source: "qrc:/images/images/pic640_1.jpg"
                        }
                        Button {
                            text: "结账"
                            font.bold: true
                            font.pointSize: 14
                            ToolTip.visible: down
                            ToolTip.text: qsTr("可选择支付方式")
                            onClicked: popup.open()
                        }
                        Popup {
                            id: popup
                            ColumnLayout {
                                anchors.fill: parent
                                Label {
                                    text: qsTr("请选择支付方式")
                                }
                                CheckBox { text: qsTr("支付宝") }
                                CheckBox { text: qsTr("微信") }
                                CheckBox { text: qsTr("银联") }
                            }
                            enter: Transition {
                                NumberAnimation {
                                    property: "opacity";
                                    from: 0.0
                                    to: 0.8
                                }

                            }
                            exit: Transition {
                                NumberAnimation {
                                    property: "opacity";
                                    from: 0.8
                                    to: 0.0
                                }
                            }
                        }
                    }
                }
            }
        }

        Page2Form {
            Label {
                text: qsTr("Secnod")
                anchors.centerIn: parent
            }
        }
    }

    footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex

        TabButton {
            text: qsTr("Page 1")
        }
        TabButton {
            text: qsTr("Page 2")
        }
    }
}
