#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QPainter>
#include "triangle.h"
#include "rectanlge.h"
#include "circle.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_triangle, SIGNAL(clicked()), this, SLOT(Calculate1()));
    connect(ui->pushButton_rectangle, SIGNAL(clicked()), this, SLOT(Calculate2()));
    connect(ui->pushButton_circle, SIGNAL(clicked()), this, SLOT(Calculate3()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Calculate1(){
    Triangle tr;
//    tr.setA(8);
//    tr.setB(8);
//    tr.setC(2);
    tr.Resize(8,8,2);
    ui->label_3->setText(QString("Perimeter: ") + QString::number(tr.Perimeter())+ "\nArea: " + QString::number(tr.Area(),'f',2));
}

void MainWindow::Calculate2(){
    Rect rect;
//    rect.setWidth(12);
//    rect.setHeight(10);
    rect.Resize(1,1);
    ui->label_3->setText(QString("Perimeter: ") + QString::number(rect.Perimeter())+ "\nArea: " + QString::number(rect.Area(),'f',2));
}

void MainWindow::Calculate3(){
    Circle c;
    c.Resize(10);
    ui->label_3->setText(QString("Perimeter: ") + QString::number(c.Perimeter())+ "\nArea: " + QString::number(c.Area(),'f',2));

}

