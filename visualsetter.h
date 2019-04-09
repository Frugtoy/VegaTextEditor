#ifndef VISUALSETTER_H
#define VISUALSETTER_H
#include <QTextEdit>
#include <QColor>

class VisualSetter
{
public:
    VisualSetter(QTextEdit* text);
    void setFontStyle(const QString fontStyle);
    void setFontColor(const QColor fontColor);
    void setBgColor(const QColor bgColor);
    void setFontSize(int size);
    void setTextBgColor(const QColor);
    ~VisualSetter();
    QColor bgColor;
    QColor fontColor;
    QColor textBgColor;
private:
    QTextEdit *setter;
    int fontSize;
   //QColor bgColor  and also fontColorhere is not provided by a function in mainwindow.cpp//

    QString fontStyle;
};

#endif // VISUALSETTER_H
