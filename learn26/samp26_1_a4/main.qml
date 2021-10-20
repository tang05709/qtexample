import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

ApplicationWindow {
    visible: true
    width: 330
    height: 200
    title: qsTr("部分控件的外观")

    ColumnLayout {
        anchors.centerIn: parent
        RowLayout {
            Label {
                text: "忙指示器"
            }
            BusyIndicator {

            }
        }
        RowLayout {
            Label {
                text: "进度条"
            }
            ProgressBar {
                indeterminate: true
            }
        }
        RowLayout {
            Label {
                text: "滑动条"
            }
            Slider {
                from: 1
                value: 25
                to: 100
                stepSize: 5
                snapMode: Slider.SnapOnRelease
            }
        }
        RowLayout {
            Label {
                text: "数值旋转框"
            }
            SpinBox {
                value: 50
            }
        }
    }
}
