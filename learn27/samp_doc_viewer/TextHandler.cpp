#include "TextHandler.h"
#include <QtGui/QTextDocument>
#include <QtCore/QFileInfo>

TextHandler::TextHandler()
            : m_target(0)
            , m_doc(0)
            , m_cursorPosition(-1)
            , m_selectionStart(0)
            , m_selectionEnd(0)
{

}


void TextHandler::setTarget(QQuickItem *target)
{
    m_doc = 0;
    m_target = target;
    if (!m_target) {
        return;
    }
    QVariant doc = m_target->property("textDocument");
    if (doc.canConvert<QQuickTextDocument*>()) {
        QQuickTextDocument *qqdoc = doc.value<QQuickTextDocument*>();
        if (qqdoc) {
            m_doc = qqdoc->textDocument();
        }
    }
    emit targetChanged();
}

void TextHandler::setFileUrl(const QUrl &arg)
{
    if (m_fileUrl != arg) {
        m_fileUrl = arg;
        QString fileName = QQmlFile::urlToLocalFileOrQrc(arg);
        if (QFile::exists(fileName)) {
            QFile file(fileName);
            if (file.open(QFile::ReadOnly)) {
                QByteArray data = file.readAll();
                QTextCodec *codec = QTextCodec::codecForName("GB2312");
                setText(codec->toUnicode(data));
                if (m_doc) {
                    m_doc->setModified(false);
                }
                if (fileName.isEmpty()) {
                    m_htmlTitle = QStringLiteral("untitled.txt");
                } else {
                    m_htmlTitle = QFileInfo(fileName).fileName();
                }
                emit textChanged();
                emit htmlTitleChanged();
            }
        }
        emit fileUrlChanged();
    }
}

QString TextHandler::htmlTitle() const
{
    return m_htmlTitle;
}

void TextHandler::setHtmlTitle(QString arg)
{
    if (m_htmlTitle != arg) {
        m_htmlTitle = arg;
        emit htmlTitleChanged();
    }
}

void TextHandler::setText(const QString &arg)
{
    if (m_text != arg) {
        m_text = arg;
        emit textChanged();
    }
}

QUrl TextHandler::fileUrl() const
{
    return m_fileUrl;
}

QString TextHandler::text() const
{
    return m_text;
}
