import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.12
import QtQuick.Dialogs 1.2
import org.qtproject.easybooks 1.0


ApplicationWindow {
    id: main
    title: "多功能文档查看器"
    visible: true
    width: 640
    height: 480
    minimumWidth: 400
    minimumHeight: 300

    property color textBackgroundColor: "black"
    property color textColor: "white"

    // 剪切
    Action {
        id: cutAction
        text: "剪切"
        shortcut: "Ctrl+X"
        icon.source: "qrc:/images/images/editcut.png"
        icon.name: "edit-cut"
        enabled: false
        onTriggered: textArea.cut()
    }

    // 复制
    Action {
        id: copyAction
        text: "复制"
        shortcut: "Ctrl+C"
        icon.source: "qrc:/images/images/editcopy.png"
        icon.name: "edit-copy"
        enabled: false
        onTriggered: textArea.copy()
    }

    // 粘贴
    Action {
        id: pasteAction
        text: "粘贴"
        shortcut: "Ctrl+V"
        icon.source: "qrc:/images/images/editpaste.png"
        icon.name: "edit-paste"
        enabled: false
        onTriggered: textArea.paste()
    }

    // 打开网页
    Action {
        id: htmlOpenAction
        text: "打开网页"
        icon.source: "qrc:/images/images/filehtml.png"
        icon.name: "html-open"
        onTriggered: htmlDlg.open()
    }

    // 打开文本
    Action {
        id: txtOpenAction
        text: "打开文本"
        icon.source: "qrc:/images/images/filetext.png"
        icon.name: "text-open"
        onTriggered: txtDlg.open()
    }

    // 打开图片
    Action {
        id: imgOpenAction
        text: "打开图片"
        icon.source: "qrc:/images/images/fileimage.png"
        icon.name: "image-open"
        onTriggered: imgDlg.open()
    }

    // 放大
    Action {
        id: imgZoominAction
        icon.source: "qrc:/images/images/zoomin.png"
        icon.name: "image-zoomin"
        text: "放大图片"
        enabled: false
        onTriggered: {
            imageArea.scale += 0.1
            if (imageArea.scale > 3) {
                imageArea.scale = 1
            }
        }

    }

    // 缩小
    Action {
        id: imgZoomoutAction
        icon.source: "qrc:/images/images/zoomout.png"
        icon.name: "image-zoomout"
        text: "缩小图片"
        enabled: false
        onTriggered: {
            imageArea.scale -= 0.1
            if (imageArea.scale < 0.1) {
                imageArea.scale = 1
            }
        }
    }

    // 左旋转
    Action {
        id: imgRotaleftAction
        icon.source: "qrc:/images/images/rotaleft.png"
        icon.name: "image-rotaleft"
        text: "左旋转"
        enabled: false
        onTriggered: {
            imageArea.rotation -= 45
        }
    }

    // 右旋转
    Action {
        id: imgRotarightAction
        icon.source: "qrc:/images/images/rotaright.png"
        icon.name: "image-rotaright"
        text: "右旋转"
        enabled: false
        onTriggered: {
            imageArea.rotation += 45
        }
    }

    // 菜单栏
    menuBar: MenuBar {
        // 文档主菜单
        Menu {
            title: "文档"
            // 打开文本
            MenuItem {
                text: "文本..."
                action: txtOpenAction
            }
            // 打开网页
            MenuItem {
                text: "网页..."
                action: htmlOpenAction
            }
            // 打开图片
            MenuItem {
                text: "图片..."
                action: imgOpenAction
            }
            MenuSeparator {}
            MenuItem {
                text: "退出"
                onTriggered: Qt.quit()
            }
        }

        // 编辑菜单
        Menu {
            title: "编辑"
            MenuItem { action: cutAction }
            MenuItem { action: copyAction }
            MenuItem { action: pasteAction }
        }
        // 图片
        Menu {
            title: "图片"
            MenuItem {
                text: "放大"
                action: imgZoominAction
            }
            MenuItem {
                text: "缩小"
                action: imgZoomoutAction
            }
            MenuSeparator {}
            MenuItem {
                text: "向左旋转"
                action: imgRotaleftAction
            }
            MenuItem {
                text: "向右旋转"
                action: imgRotarightAction
            }
        }
        // 帮助
        Menu {
            title: "帮助"
            MenuItem {
                text: "关于..."
                onTriggered: aboutBox.open()
            }
        }
    }
    // 工具栏
    header: ToolBar {
        id: mainToolBar
        width: parent.width
        RowLayout {
            anchors.fill: parent
            spacing: 0
            ToolButton { action: htmlOpenAction }
            ToolSeparator {}
            ToolButton { action: txtOpenAction }
            ToolButton { action: cutAction }
            ToolButton { action: copyAction }
            ToolButton { action: pasteAction }
            ToolSeparator {}
            ToolButton { action: imgOpenAction }
            ToolButton { action: imgRotaleftAction }
            ToolButton { action: imgRotarightAction }
            ToolButton { action: imgZoominAction }
            ToolButton { action: imgZoomoutAction }

            Item { Layout.fillWidth: true } // Item元素填满工具栏剩余宽度
        }
    }
    // 定义界面主显示区域的元素
    Item {
        id: centralArea
        anchors.fill: parent
        visible: true
        property var current: htmlArea

        BusyIndicator {
            id: busy
            anchors.centerIn: parent
            running: false
            z: 3
        }

        TextArea {
            id: htmlArea
            anchors.fill: parent
            readOnly: true
            baseUrl: "qrc:/"
            text: htmldoc.text
            textFormat: Qt.RichText
        }
        TextArea {
            id: textArea
            anchors.fill: parent
            visible: false
            wrapMode: TextEdit.WordWrap
            font.pointSize: 12
            text: textdoc.text

            Component.onCompleted: forceActiveFocus() // 自动获取焦点
        }
        Image {
            id: imageArea
            anchors.fill: parent
            visible: true
            fillMode: Image.PreserveAspectFit
            onStatusChanged: {
                if (status === Image.Loading) {
                    busy.running = true
                } else if (status === Image.Ready) {
                    busy.running = false
                } else if (status === Image.Error) {
                    busy.running = false
                    mainStatusBar.text = "图片无法显示"
                }
            }
        }
    }

    // 状态栏
    footer: ToolBar {
        width: parent.width
        implicitHeight: 30
        Rectangle {
            id: mainStatusBar
            color: "lightgray"
            implicitHeight: 30
            width: parent.width
            property alias text: status.text

            Text {
                id: status
                anchors.fill: parent
                anchors.margins: 4
                font.pointSize: 12
            }
        }
    }

    // 打开网页对话框
    FileDialog {
        id: htmlDlg
        title: "打开网页"
        nameFilters: ["网页(*.htm *.html)"]
        onAccepted:  {
            htmldoc.fileUrl = fileUrl
            var filepath = new String(fileUrl);
            mainStatusBar.text = filepath.slice(8)
            centralArea.current = htmlArea // 设置htmlArea为主显示区域
            textArea.visible = false
            imageArea.visible = false
            htmlArea.visible = true
            main.title = htmldoc.htmlTitle + "-多功能文档查看器"
            // 设置系统各功能的可用性
            copyAction.enabled = false
            cutAction.enabled = false
            pasteAction.enabled = false
            imgRotaleftAction.enabled = false
            imgRotarightAction.enabled = false
            imgZoominAction.enabled = false
            imgZoomoutAction.enabled = false

        }
    }
    // 打开文本对话框
    FileDialog {
        id: txtDlg
        title: "打开文本"
        nameFilters: ["文本文件(*.txt)"]
        onAccepted: {
            textdoc.fileUrl = fileUrl
            var filepath = new String(fileUrl);
            mainStatusBar.text = filepath.slice(8)
            centralArea.current = textArea // 设置textArea为主显示区域
            htmlArea.visible = false
            imageArea.visible = false
            textArea.visible = true
            main.title = textdoc.htmlTitle + "-多功能文档查看器"
            // 设置系统各功能的可用性
            copyAction.enabled = true
            cutAction.enabled = true
            pasteAction.enabled = true
            imgRotaleftAction.enabled = false
            imgRotarightAction.enabled = false
            imgZoominAction.enabled = false
            imgZoomoutAction.enabled = false
        }
    }
    // 打开图片对话框
    FileDialog {
        id: imgDlg
        title: "打开图片"
        nameFilters: ["图片文件(*.jpg *.png *.gif *.bmp *.ico)"]
        onAccepted: {
            var filepath = new String(fileUrl)
            mainStatusBar.text = filepath.slice(8)
            var dot = filepath.lastIndexOf(".")
            var sep = filepath.lastIndexOf("/")
            if (dot > sep) {
                var filename = filepath.substring(sep + 1)
                main.processFile(fileUrl, filename)
            } else {
                mainStatusBar.text = "出错，不支持此格式图片"
            }
        }
    }
    // 关于对话框
    MessageDialog {
         id: aboutBox
         title: "关于"
         text: "MultiDocVier 1.1 \n这是一个多功能文档查看器，可打开文本、网页、图片d等多种类型的文档\n
         使用Qt Quick Controls开发而成，\nCopyright@ 2021 - 2017 easybooks.版权所有"
         icon: StandardIcon.Information
    }

    HtmlHandler {
        id: htmldoc
        Component.onCompleted: htmldoc.fileUrl = "qrc:/easybooks.htm"
    }

    TextHandler {
        id: textdoc
    }

    function processFile(fileUrl, name) {
        if (centralArea.current != imageArea) {
            if (centralArea.current != null) {
                centralArea.current.visible = false;
            }
            imageArea.visible = true;
            centralArea.current = imageArea;
        }
        imageArea.source = fileUrl;
        main.title = name + "-多功能文档查看器";
        copyAction.enabled = false
        cutAction.enabled = false
        pasteAction.enabled = false
        imgRotaleftAction.enabled = true
        imgRotarightAction.enabled = true
        imgZoominAction.enabled = true
        imgZoomoutAction.enabled = true
    }
}
