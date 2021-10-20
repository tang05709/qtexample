#include "childword.h"
#include <QFileInfo>
#include <QFile>
#include <QFileDialog>
#include <QTextCodec>
#include <QTextDocumentWriter>
#include <QMessageBox>
#include <QCloseEvent>

ChildWord::ChildWord()
{
    setAttribute(Qt::WA_DeleteOnClose); // 子窗口关闭时销毁该类的对象实例
    beSaved = false;
}

void ChildWord::newDoc()
{
    // 设置窗口编号
    static int wndSeqNum = 1;
    // 将当前打开的文档命名为“Word 文档 编号”的形式，编号使用一次后自增
    myCurDocPath = tr("Word 文档 %1").arg(wndSeqNum++);
    // 设置窗口标题，文档被改动后在其名称后面显示“*”号标识
    setWindowTitle(myCurDocPath + "[*]" + tr("- MyWord"));
    // 文档被改动时发送contentsChanged()信号，执行指定docBeModified()槽函数
    connect(document(), SIGNAL(contentsChanged()), this, SLOT(docBeModified()));
}


void ChildWord::docBeModified()
{
    // 判断文档内容是否被修改
    setWindowModified(document()->isModified());
}

QString ChildWord::getCurDocName()
{
    return QFileInfo(myCurDocPath).fileName();
}

bool ChildWord::loadDoc(const QString& docName)
{
    if (!docName.isEmpty()) {
        if (!QFile::exists(docName)) return false;
        QFile doc(docName);
        if (!doc.open(QFile::ReadOnly)) return false;
        QByteArray text = doc.readAll();
        QTextCodec *textCodec = Qt::codecForHtml(text);
        QString str = textCodec->toUnicode(text);
        if (Qt::mightBeRichText(str)) {
            this->setHtml(str);
        } else {
            str = QString::fromLocal8Bit(text);
            this->setPlainText(str);
        }
        setCurDoc(docName);
        connect(document(), SIGNAL(contentsChanged()), this, SLOT(docBeModified()));
        return true;
    }
    return false;
}

bool ChildWord::saveDoc()
{
    if(!beSaved){
        return saveAsDoc();
    } else {
        return saveDocOpt(myCurDocPath);
    }
}

bool ChildWord::saveAsDoc()
{
   QString docName = QFileDialog::getSaveFileName(this, tr("另存为"), myCurDocPath, tr("HTML 文档(*.htm *.html);;所有文件(*.*)"));
   if (docName.isEmpty()) {
       return false;
   } else {
       return saveDocOpt(docName);
   }
}

bool ChildWord::saveDocOpt(QString docName)
{
    if (!(docName.endsWith(".htm", Qt::CaseSensitive) || docName.endsWith(".html", Qt::CaseSensitive))) {
        docName += ".html";
    }
    QTextDocumentWriter writer(docName);
    bool success = writer.write(this->document());
    if (success) setCurDoc(docName);
    return success;
}

void ChildWord::setFormatOnSelectedWord(const QTextCharFormat& fmt)
{
    QTextCursor tcursor = this->textCursor();
    if (!tcursor.hasSelection()) tcursor.select(QTextCursor::WordUnderCursor);
    tcursor.mergeCharFormat(fmt); //将参数fmt所选的格式应用到光标所选的字符上
}

void ChildWord::setAlignOfDocumentText(int alignStyle)
{
    switch (alignStyle) {
    default:
    case 1:
        this->setAlignment(Qt::AlignLeft | Qt::AlignAbsolute);
        break;
    case 2:
        this->setAlignment(Qt::AlignCenter);
        break;
    case 3:
        this->setAlignment(Qt::AlignRight | Qt::AlignAbsolute);
        break;
    case 4:
        this->setAlignment(Qt::AlignJustify);
        break;
    }
}

void ChildWord::setParaStyle(int pstyle)
{
    QTextCursor tcursor = this->textCursor();
    if (pstyle != 0) {
        QTextListFormat::Style sname = QTextListFormat::ListDisc;
        switch (pstyle) {
        default:
        case 1:
            sname = QTextListFormat::ListDisc; // 实心圆标号
            break;
        case 2:
            sname = QTextListFormat::ListCircle; // 空心圆标号
            break;
        case 3:
            sname = QTextListFormat::ListSquare; // 方形圆标号
            break;
        case 4:
            sname = QTextListFormat::ListDecimal; // 十进制编号
            break;
        case 5:
            sname = QTextListFormat::ListLowerAlpha; // 小写字母编号
            break;
        case 6:
            sname = QTextListFormat::ListUpperAlpha; // 大写字母编号
            break;
        case 7:
            sname = QTextListFormat::ListLowerRoman; // 小写罗马数字编号
            break;
        case 8:
            sname = QTextListFormat::ListUpperRoman; // 大写罗马数字编号
            break;
        }
        tcursor.beginEditBlock();
        QTextBlockFormat tBlockFmt = tcursor.blockFormat();
        QTextListFormat tListFmt;
        /*if (tcursor.currentList()) {

        } else {
            tListFmt.setIndent(tBlockFmt.indent() + 1);
            tBlockFmt.setIndent(0);
            tcursor.setBlockFormat(tBlockFmt);
        }*/

        tListFmt.setIndent(tBlockFmt.indent() + 1);
        tBlockFmt.setIndent(0);
        tcursor.setBlockFormat(tBlockFmt);

        tListFmt.setStyle(sname);
        tcursor.createList(tListFmt);
        tcursor.endEditBlock();
    } else {
        QTextBlockFormat tBlockFmt;
        tBlockFmt.setObjectIndex(-1);
        tcursor.mergeBlockFormat(tBlockFmt);
    }
}

void ChildWord::closeEvent(QCloseEvent* event)
{
    if (promptSave()) {
        event->accept();
    } else {
        event->ignore();
    }
}


bool ChildWord::promptSave()
{
    if (!document()->isModified()) return true;
    QMessageBox::StandardButton result;
    result = QMessageBox::warning(
                this,
                tr("MyWord"),
                tr("文档'%1'已被修改，保存吗？").arg(getCurDocName()),
                QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    if (result == QMessageBox::Save) {
        return saveDoc();
    } else if (result == QMessageBox::Cancel) {
        return false;
    }
    return true;
}

void ChildWord::setCurDoc(const QString& docName)
{
    myCurDocPath = QFileInfo(docName).canonicalFilePath();
    beSaved = true;
    document()->setModified(false); // 文档未被改动
    setWindowModified(false); // 窗口不显示被改动标识
    setWindowTitle(getCurDocName() + "[*]");// 设置文档名未子窗口标题

}
