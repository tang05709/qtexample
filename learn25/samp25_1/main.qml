import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    MenuBar {
        Menu {
            title: qsTr("菜单")
            MenuItem {
                text: qsTr("菜单1")
            }
            MenuItem {
                text: qsTr("菜单2")
            }
        }
    }

    ToolBar {
        ToolButton {
            text: qsTr("菜单1")
        }
        ToolButton {
            text: qsTr("菜单2")
        }
    }


}
