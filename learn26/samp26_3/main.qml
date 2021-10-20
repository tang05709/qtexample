import QtQuick 2.12
import QtQuick.Controls 2.5

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("选择美女")

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        Page1Form {
            ListView {
                id: listTitle
                width: 200
                height: 240
                model: bookModel
                delegate: ItemDelegate {
                    text: modelData
                    width: parent.width
                    highlighted: ListView.isCurrentItem

                    onClicked:  {
                        listTitle.currentIndex = index
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
                }
                ScrollIndicator.vertical: ScrollIndicator {}
            }
            Image {
                id: bookCover
                width: 164
                height: 230
                source: "qrc:/images/images/pic640_1.jpg"
                anchors.left: listTitle.right
                anchors.leftMargin: 120
            }

            ListModel {
                id: bookModel
                ListElement {
                    title: "Java实用教程"
                }
                ListElement {
                    title: "JavaEE基础实用教程"
                }
                ListElement {
                    title: "MySql实用教程"
                }
                ListElement {
                    title: "Oracle实用教程"
                }
                ListElement {
                    title: "PHP实用教程"
                }
                ListElement {
                    title: "PLC实用教程"
                }
                ListElement {
                    title: "SQL Server实用教程"
                }
            }
        }

        Page2Form {
            Label {
                text: "Second page"
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
