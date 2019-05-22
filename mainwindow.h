#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <filemanager.h>
#include <visualsetter.h>
#include <compiler.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    //void on_pushButton_pressed();
    void create_file_slot();
    void save_file_slot();
    void open_file_slot();
    void change_font_style_slot();
    void change_font_color_slot();
    void change_font_size_slot();
    void change_bg_color_slot();
    void change_text_bg_slot();
    void compile_slot();
private:
    Ui::MainWindow* ui;
    FileManager* file_manager;
    VisualSetter* setter;
    Compiler* compiler;
};


#endif // MAINWINDOW_H
