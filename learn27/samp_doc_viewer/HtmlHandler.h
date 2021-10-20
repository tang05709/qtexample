#ifndef HTMLHANDLER_H
#define HTMLHANDLER_H
#include <QQuickTextDocument>
#include <QtCore/QTextCodec>
#include <qqmlfile.h>

class QTextDocument;

class HtmlHandler : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQuickItem *target READ target WRITE setTarget NOTIFY targetChanged)
    Q_PROPERTY(QUrl fileUrl READ fileUrl WRITE setFileUrl NOTIFY fileUrlChanged)
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
    Q_PROPERTY(QString htmlTitle READ htmlTitle WRITE setHtmlTitle NOTIFY htmlTitleChanged)

public:
    HtmlHandler();
    QQuickItem *target() { return m_target; }
    void setTarget(QQuickItem *target);
    QUrl fileUrl() const;
    QString text() const;
    QString htmlTitle() const;
public Q_SLOTS:
    void setFileUrl(const QUrl &arg);
    void setText(const QString &arg);
    void setHtmlTitle(QString arg);

Q_SIGNALS:
    void targetChanged();
    void fileUrlChanged();
    void textChanged();
    void htmlTitleChanged();


private:
    QQuickItem *m_target; // 指向目标元素的指针
    QTextDocument *m_doc; // 指向文档的指针
    int m_cursorPosition; // 光标位置
    int m_selectionStart; // 选中文本段的起始点
    int m_selectionEnd; // 选中文本段的终点
    QFont m_font;
    QUrl m_fileUrl;
    QString m_text;
    QString m_htmlTitle;
};

#endif // HTMLHANDLER_H
