#ifndef CHILDWORD_H
#define CHILDWORD_H

#include <QObject>
#include <QTextEdit>
#include <QPrinter>

class ChildWord : public QTextEdit
{
    Q_OBJECT
public:
    ChildWord();

    QString myCurDocPath; // 当前文档路径全名
    void newDoc(); // 新建文档
    QString getCurDocName(); // 从路径中提取文档名
    bool loadDoc(const QString& docName); // 加载文档内容
    bool saveDoc(); // 保存文件
    bool saveAsDoc(); // 另存为
    bool saveDocOpt(QString docName); // 具体执行保存操作
    void setFormatOnSelectedWord(const QTextCharFormat& fmt); // 设置字体和字号
    void setAlignOfDocumentText(int alignStyle); // 设置对齐样式
    void setParaStyle(int pstyle); // 设置段落标号和编号

protected:
    void closeEvent(QCloseEvent* event);


private slots:
    void docBeModified(); // 文档被修改时，在窗口标题栏显示*号

private:
    bool beSaved; // 文档是否已保存
    void setCurDoc(const QString& docName); //对当前文档的状态进行设置，并保存其路径名
    bool promptSave(); // 用户关闭文档时提示保存
};

#endif // CHILDWORD_H
