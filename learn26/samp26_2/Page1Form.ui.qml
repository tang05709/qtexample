import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Item {
    property alias topic: topic
    property alias author: author

    SwipeView {
        id: view
        currentIndex: pageIndicator.currentIndex
        anchors.fill: parent

        Page {
            title: qsTr("图片1")
            Image {
                source: "qrc:/images/images/pic640_1.jpg"
            }
        }
        Page {
            title: qsTr("图片2")
            Image {
                source: "qrc:/images/images/pic640_2.jpg"
            }
        }
        Page {
            title: qsTr("图片3")
            Image {
                source: "qrc:/images/images/pic640_3.jpg"
            }
        }
    }

    PageIndicator {
        id: pageIndicator
        interactive: true
        count: view.count
        currentIndex: view.currentIndex
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Label {
        id: topic
        text: view.currentItem.title
        font.bold: true
        font.pixelSize: 25
        anchors.right: parent.right
        anchors.rightMargin: 250
        TextArea {
            id: author
            font.pixelSize: 18
            anchors.top: parent.bottom
        }
    }

}
