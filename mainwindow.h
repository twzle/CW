#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    Ui::MainWindow *ui;

private slots:
    void updateList();
    void on_pushButton_ReadFromFile_clicked();
    void on_pushButton_MakeFile_clicked();
    void on_pushButton_Clear_clicked();
    void on_pushButton_AddItem_clicked();
    void on_pushButton_RemoveItem_clicked();
    void on_radioButton_Circle_clicked();
    void on_radioButton_Triangle_clicked();
    void on_radioButton_Rectangle_clicked();
    void on_pushButton_Draw_clicked();
};
#endif // MAINWINDOW_H
