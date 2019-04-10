#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "visualsetter.h"
#include <qfiledialog.h>
#include <qstring.h>
#include <QColorDialog>
#include <QInputDialog>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    file_manager = new FileManager();
    setter = new VisualSetter(ui->textEdit);

    connect(ui->actionOpen, &QAction::triggered,this, &MainWindow::open_file_slot);
    connect(ui->actionSave, &QAction::triggered,this,&MainWindow::save_file_slot);
    connect(ui->actionCreate, &QAction::triggered,this,&MainWindow::create_file_slot);
    connect(ui->Change_Font_Size,&QAction::triggered,this,&MainWindow::change_font_size_slot);//-
    connect(ui->Change_Font_Style,&QAction::triggered,this,&MainWindow::change_font_style_slot);//-
    connect(ui->Change_Font_Color,&QAction::triggered,this,&MainWindow::change_font_color_slot);
    connect(ui->Change_Background_Color,&QAction::triggered,this,&MainWindow::change_bg_color_slot);
    connect(ui->Change_Text_Backqround_Color,&QAction::triggered,this,&MainWindow::change_text_bg_slot);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete file_manager;
    delete setter;
}


void MainWindow::create_file_slot()
{
    QString path = QFileDialog::getSaveFileName(this,tr ("create file"),"/home",tr(""));
    file_manager->createFile(path);
}
void MainWindow::save_file_slot()
{
    QString path = QFileDialog::getSaveFileName(this,tr("save file"),"/home",tr(""));
    if(path!="")
    {
        QString text = ui->textEdit->toPlainText();
        file_manager->saveFile(path,text);
    }
}
void MainWindow::open_file_slot()
{
    QString path = QFileDialog::getOpenFileName(this,tr("open file"),"/home",tr(""));
    if(path!="")
    {
       QString text = file_manager->openFile(path);
       ui->textEdit->setPlainText(text);
    }
}
void MainWindow::change_font_color_slot()
{
    setter->setFontColor(QColorDialog::getColor(setter->fontColor,this));
}

void MainWindow::change_font_style_slot()
{
   QStringList styles;
   styles<<tr("TimesNewRoman")<<tr("Ubuntu")/*<<tr("coming soon")*/;
   const QString font_style = QInputDialog::getItem(this,tr("Set Font style"),tr("font list"),styles,0,false);
   setter->setFontStyle(font_style);
}
void MainWindow::change_font_size_slot()
{
    setter->setFontSize(QInputDialog::getInt(this,tr("Size of font"),0,100,1));
}
void MainWindow::change_bg_color_slot()
{
    setter->setBgColor(QColorDialog::getColor(setter->bgColor,this));
}

void MainWindow::change_text_bg_slot()
{

    setter->setTextBgColor(QColorDialog::getColor(setter->textBgColor,this));

}
