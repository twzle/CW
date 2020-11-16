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
    bool ok;
    Triangle tr(14,5,12);
    ui->label_3->setText(QString("Perimeter: ") + QString::number(tr.Perimeter())+ "\nArea: " + QString::number(tr.Area(),'f',2));
}

void MainWindow::Calculate2(){
    bool ok;
    Rect rect(14,5);
    ui->label_3->setText(QString("Perimeter: ") + QString::number(rect.Perimeter())+ "\nArea: " + QString::number(rect.Area(),'f',2));
}

void MainWindow::Calculate3(){
    bool ok;
    Circle c(14);
    ui->label_3->setText(QString("Perimeter: ") + QString::number(c.Perimeter())+ "\nArea: " + QString::number(c.Area(),'f',2));
//    QString text = QInputDialog::getText(this, tr("Circle"),
//                                             tr("Please, write a telephone num to activate your b.c.:"), QLineEdit::NoEcho,
//                                             "+7", &ok);

}

