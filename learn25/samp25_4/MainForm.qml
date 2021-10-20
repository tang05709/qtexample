import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Styles 1.4


Item {
    id: win
    width: 600
    height: 240
    property int columnWidth: win.width / 5

    GridLayout {
        rowSpacing: 12
        columnSpacing: 30
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.margins: 30

        Button {
            text: "标准按钮"
            implicitWidth: columnWidth
        }
        Button {
            text: "样式属性"
            contentItem: BorderImage {
                source: "qrc:/images/images/button-pressed.png"
                border.left: 4; border.top: 4
                border.right: 4; border.bottom: 4
            }
            implicitWidth: columnWidth
        }
        Button {
            text: "代理样式"
            background: Rectangle {
                implicitHeight: 22
                implicitWidth: columnWidth
                color: "darkGray"
                antialiasing: true
                border.color: "gray"
                radius: height /2
                Rectangle {
                    anchors.fill: parent
                    anchors.margins: 1
                    color: "transparent"
                    antialiasing: true
                    visible: false
                    border.color: "#aaffff"
                    radius: height / 2
                }
            }
            implicitWidth: columnWidth
        }
        TextField {
            Layout.row: 1
            implicitWidth: columnWidth
        }
        TextField {
            background: BorderImage {
                source: "qrc:/images/images/textfield.png"
                border.left: 4; border.top: 4
                border.right: 4; border.bottom: 4
            }
            implicitWidth: columnWidth
        }
        TextField {
            background: Rectangle {
                implicitWidth: columnWidth
                color: "#f0f0f0"
                antialiasing: true
                border.color: "gray"
                radius: height /2
                Rectangle {
                    anchors.fill: parent
                    anchors.margins: 1
                    color: "transparent"
                    antialiasing: true
                    visible: false
                    border.color: "#aaffff"
                    radius: height / 2
                }
            }
            implicitWidth: columnWidth
        }
        Slider {
            id: slider1
            Layout.row: 2
            value: 0.5
            implicitWidth: columnWidth
        }
        Slider {
            id: slider2
            value: 0.5
            implicitWidth: columnWidth

            handle: Item {
                width: 13
                height: 13
                Image {
                    anchors.centerIn: parent
                    source: "qrc:/images/images/slider-handle.png"
                }
            }
        }
        Slider {
            id: slider3
            value: 0.5
            implicitWidth: columnWidth
            handle: Rectangle {
                width: 18
                height: 18
                color: "#f0f0f0"
                antialiasing: true
                border.color: "gray"
                radius: height /2
                Rectangle {
                    anchors.fill: parent
                    anchors.margins: 1
                    color: "transparent"
                    antialiasing: true
                    visible: false
                    border.color: "#eee"
                    radius: height / 2
                }
            }
            /*groove: Rectangle {
                height: 8
                implicitWidth: columnWidth
                implicitHeight: 22
                color: "#f0f0f0"
                border.color: "#777"
                antialiasing: true
                radius: height /2
                Rectangle {
                    anchors.fill: parent
                    anchors.margins: 1
                    color: "transparent"
                    antialiasing: true
                    visible: false
                    border.color: "#66ffff"
                    radius: height / 2
                }
            }*/
        }
        ProgressBar {
            Layout.row: 3
            value: slider1.value
            implicitWidth: columnWidth
        }
        ProgressBar {
            value: slider2.value
            implicitWidth: columnWidth
            background: BorderImage {
                source: "qrc:/images/images/progress-background.png"
                border.left: 2; border.top: 2
                border.right: 2; border.bottom: 2
            }
            /*progress: Item {
                clip: true
                BorderImage {
                    source: "qrc:/images/images/progress-fill.png"
                    anchors.fill: parent
                    anchors.rightMargin: -4
                    border.left: 10
                    border.right: 10
                    Rectangle {
                        width: 1
                        anchors.top: parent.top
                        anchors.bottom: parent.bottom
                        anchors.bottomMargin: 1
                        anchors.right: parent.right
                        color: "#a70"
                        opacity: 0.8
                        visible: false
                        anchors.rightMargin: -parent.anchors.rightMargin
                    }
                }
            }*/
        }
        ProgressBar {
            value: slider2.value
            implicitWidth: columnWidth
            background: Rectangle {
                implicitWidth: columnWidth
                implicitHeight: 24
                color: "#f0f0f0"
                border.color: "gray"
            }
            /*progress: Rectangle {
                color: "#ccc"
                border.color: "gray"
                Rectangle {
                    anchors.fill: parent
                    anchors.margins: 1
                    color: "transparent"
                    border.color: "#44ffff"
                }
            }*/
        }
    }

}
