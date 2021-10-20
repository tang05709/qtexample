import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    MainForm {
        anchors.fill: parent
        submit.onClicked: {
            var hobbyText = "";
            for (var i = 0; i < 7; i++) {
                hobbyText += hobby.children[i].checked ? (hobby.children[i].text + "、") : "";

            }
            if (hobby.children[7].checked) {
                hobbyText += "...";
            }
            console.log(hobbyText)
            details.text = "我的名字叫" + name.text + ",是个" + age.text + "岁" + sex.text + "生，所学专业是"
                           + spec.currentText + ",业余喜欢" + hobbyText;
        }
    }
}
