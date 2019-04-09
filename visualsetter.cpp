 #include "visualsetter.h"
 #include <QPalette>
#define DEFAULT_SIZE 12
#define DEFAULT_TEXT_COLOR black
#define DEFAULT_BG_COLOR white


VisualSetter::VisualSetter(QTextEdit*text)
{
    setter = text;
    fontSize = DEFAULT_SIZE;
    bgColor = Qt::DEFAULT_BG_COLOR;
    fontColor = Qt::DEFAULT_TEXT_COLOR;
}
/*void VisualSetter::setFontStyle(const QString event)
{
  fontSize = event;
  setter->setFontFamily(fontSize);
}*/
void VisualSetter::setFontColor(const QColor event)
{
  fontColor=event;
  setter->setTextColor(event);


}
void VisualSetter::setBgColor(const QColor event)
{
 QPalette col = setter->palette();

 col.setColor(QPalette::Base,event);
 setter->setPalette(col);
}
void VisualSetter::setFontSize(int event)
{
  this->fontSize =event;
  setter->setFontPointSize(fontSize);
}
void VisualSetter::setTextBgColor(const QColor event)
{
  this->textBgColor = event;
  setter->setTextBackgroundColor(event);
}
VisualSetter::~VisualSetter()
{

}



