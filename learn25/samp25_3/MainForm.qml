import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtGraphicalEffects 1.0
import Qt.labs.calendar 1.0


Item {
    width: 890
    height: 460
    property alias img: img // 图片
    property alias desat: desat // 饱和度
    property alias size: size // 滑动条尺寸
    property alias colourful: colourful // 彩色开关
    property alias btn: btn // 灰度值按钮
    property alias progreBar: progreBar // 进度条

    Image {
        id: img
        x: 10
        y: 10
        width: 640
        height: 430
        source: "qrc:/images/test.jpg"
        fillMode: Image.Stretch
        clip: true
    }
    BusyIndicator {
        x: 317.2
        y: 202
        running: img.width < 640 * 0.4
    }
    Desaturate {
        id: desat
        anchors.fill: img
        source: img
    }
    RowLayout {
        anchors.left: img.left
        y: 442
        spacing: 5
        Label {
            text: "尺寸"
        }
        Slider {
            id: size
            from: 0.1
            to: 1.0
            stepSize: 0.1
            value: 1.0
        }
        Label {
            text: "颜色"
        }
        Switch {
            id: colourful
            checked: true
        }
        Button {
            id: btn
            text: "灰度值>>"
        }
        ProgressBar {
            id: progreBar
        }
    }
    ColumnLayout {
        anchors.top: img.top
        x: 650
        spacing: 10
        RowLayout {
            spacing: 5
            Label {
                text: "美人鱼"
                font.pixelSize: 14
                font.bold: true
            }
            SpinBox {
                id: age
                from: 4
                to: 24
                value: 16
                font.pixelSize: 14
                valueFromText: function(value, locale) { return value + "岁" }
            }
        }
        Label {
            text: "生日"
            font.pixelSize: 14
            font.bold: true
            color: "magenta"
        }
        GridLayout {
             columns: 2

             DayOfWeekRow {
                 locale: grid.locale

                 Layout.column: 1
                 Layout.fillWidth: true
             }

             WeekNumberColumn {
                 month: grid.month
                 year: grid.year
                 locale: grid.locale

                 Layout.fillHeight: true
             }

             MonthGrid {
                 id: grid
                 month: Calendar.December
                 year: 2015
                 locale: Qt.locale("en_US")

                 Layout.fillWidth: true
                 Layout.fillHeight: true
             }
         }
    }
}
