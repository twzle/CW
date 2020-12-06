#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QPainter>
#include "triangle.h"
#include "rectanlge.h"
#include "circle.h"
#include <fstream>
#include <QFileDialog>
#include <QListWidget>
#include "dialog.h"

std::vector<Figure *> v;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool readFromFile(const std::string &name) {
    std::fstream file(name);
    if (file.is_open()) {
        while (!file.eof()) {
            std::string s1;
            file >> s1;
            if (s1 == "Circle") {
                std::string s2;
                file >> s2;
                double radius = std::stod(s2);
                Figure* p = new Circle(radius); //
                v.push_back(p);
            }
            if (s1 == "Triangle") {
                std::string s2, s3, s4;
                file >> s2;
                file >> s3;
                file >> s4;
                double a = std::stod(s2);
                double b = std::stod(s3);
                double c = std::stod(s4);
                Figure* p = new Triangle(a,b,c); //
                v.push_back(p);
            }
            if (s1 == "Rectangle") {
                std::string s2, s3;
                file >> s2;
                file >> s3;
                double a = std::stod(s2);
                double b = std::stod(s3);
                Figure* p = new Rect(a,b); //
                v.push_back(p);
            }
        }
        file.close();
    }
    else {
        std::cout << "Cant open file" << std::endl;
        return false;
    }
    return true;
}

bool makeFile(const std::string &name) {
    std::ofstream file(name);
    if (file.is_open()) {
        for (size_t i = 0; i < v.size(); i++) {
            if (v[i]->Name() == "CIRCLE") {
                Circle *p = dynamic_cast<Circle*>(v[i]);
                file << "Circle " << p->getRadius() << " " << std::endl;
            }
            else if (v[i]->Name() == "TRIANGLE") {
                Triangle *p = dynamic_cast<Triangle*>(v[i]);
                file << "Triangle " << p->getA() << " " << p->getB() << " " << p->getC()<< std::endl;
            }
            else if (v[i]->Name() == "RECT") {
                Rect *p = dynamic_cast<Rect*>(v[i]);
                file << "Rectangle " << p->getWidth() << " " << p->getHeight() << std::endl;
            }
        }
        file.close();
    }
    else {
        std::cout << "Cant open file" << std::endl;
        return false;
    }
    return true;
}

double countSumP() {
    double sum = 0.0;
    for (size_t i = 0; i < v.size(); i++) {
        sum += v[i]->Perimeter();
    }
    return sum;
}

double countSumA() {
    double sum = 0.0;
    for (size_t i = 0; i < v.size(); i++) {
        sum += v[i]->Area();
    }
    return sum;
}

double countAverageP() {
    return countSumP() / v.size();
}

double countAverageA() {
    return countSumA() / v.size();
}

void MainWindow::updateList() {
    ui->listWidget->clear();
    for (size_t i = 0; i < v.size(); i++) {
        QString s;
        if (v[i]->Name() == "CIRCLE") {
            Circle *p = dynamic_cast<Circle*>(v[i]);
            s = "Circle\t" + QString::number(p->getRadius());
        }
        else if (v[i]->Name() == "TRIANGLE") {
            Triangle *p = dynamic_cast<Triangle*>(v[i]);
            s = "Trinagle\t" + QString::number(p->getA()) + "\t" + QString::number(p->getB()) + "\t" + QString::number(p->getC());
        }
        else if (v[i]->Name() == "RECT") {
            Rect *p = dynamic_cast<Rect*>(v[i]);
            s = "Rectangle\t" + QString::number(p->getWidth()) + "\t" + QString::number(p->getHeight());
        }
        ui->listWidget->insertItem(i, s);
    }
    ui->label_Result->setText("Сумма периметров = " + QString::number(countSumP()) + "\n" +
                              "Сумма площадей= " + QString::number(countSumA()) + "\n" +
                              "Средний периметр = " + QString::number(countAverageP()) + "\n" +
                              "Средняя площадь = " + QString::number(countAverageA()) + "\n");
}

void MainWindow::on_pushButton_ReadFromFile_clicked()
{
    for (size_t i = 0; i < v.size(); i++) {
        delete v[i];
    }
    v.clear();
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open file"), "/home", tr("Text Files (*.txt)"));
    readFromFile(fileName.toStdString());
    updateList();
    ui->pushButton_MakeFile->setEnabled(true);
    ui->pushButton_Clear->setEnabled(true);
    ui->pushButton_RemoveItem->setEnabled(true);
    ui->pushButton_Draw->setEnabled(true);
}

void MainWindow::on_pushButton_MakeFile_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save file"), "/home", tr("Text Files (*.txt)"));
    makeFile(fileName.toStdString());
}



void MainWindow::on_pushButton_Clear_clicked()
{
    for (size_t i = 0; i < v.size(); i++) {
        delete v[i];
    }
    v.clear();
    ui->pushButton_MakeFile->setEnabled(false);
    ui->pushButton_Clear->setEnabled(false);
    ui->pushButton_RemoveItem->setEnabled(false);
    ui->pushButton_Draw->setEnabled(false);
    ui->listWidget->clear();
    ui->label_Result->setText(" ");
}

void MainWindow::on_pushButton_AddItem_clicked()
{
    if (ui->radioButton_Circle->isChecked()) {
        Figure *p = new Circle(ui->lineEdit_1->text().toDouble());
        v.push_back(p);
    } else if (ui->radioButton_Triangle->isChecked()) {
        Figure *p = new Triangle(ui->lineEdit_1->text().toDouble(), ui->lineEdit_2->text().toDouble(), ui->lineEdit_3->text().toDouble());
        v.push_back(p);
    } else if (ui->radioButton_Rectangle->isChecked()) {
        Figure *p = new Rect(ui->lineEdit_1->text().toDouble(), ui->lineEdit_2->text().toDouble());
        v.push_back(p);
    }
    updateList();
    ui->pushButton_MakeFile->setEnabled(true);
    ui->pushButton_Clear->setEnabled(true);
    ui->pushButton_RemoveItem->setEnabled(true);
    ui->pushButton_Draw->setEnabled(true);
}

void MainWindow::on_pushButton_RemoveItem_clicked()
{
    size_t i = ui->listWidget->currentRow();
    if (i < v.size()) {
        delete v[i];
        v.erase(v.begin() + i);
    }
    if (v.size() == 0) {
        ui->pushButton_MakeFile->setEnabled(false);
        ui->pushButton_Clear->setEnabled(false);
        ui->pushButton_RemoveItem->setEnabled(false);
        ui->pushButton_Draw->setEnabled(false);
        ui->listWidget->clear();
        ui->label_Result->setText(" ");
    } else {
        updateList();
    }
}

void MainWindow::on_radioButton_Circle_clicked()
{
    ui->labelInput_1->setText("Радиус   ");
    ui->labelInput_2->setText("         ");
    ui->labelInput_3->setText("         ");
    ui->lineEdit_2->setVisible(false);
    ui->lineEdit_3->setVisible(false);
}

void MainWindow::on_radioButton_Triangle_clicked()
{
    ui->labelInput_1->setText("Сторона A");
    ui->labelInput_2->setText("Сторона B");
    ui->labelInput_3->setText("Сторона C");
    ui->lineEdit_2->setVisible(true);
    ui->lineEdit_3->setVisible(true);
}

void MainWindow::on_radioButton_Rectangle_clicked()
{
    ui->labelInput_1->setText("Ширина   ");
    ui->labelInput_2->setText("Высота   ");
    ui->labelInput_3->setText("         ");
    ui->lineEdit_2->setVisible(true);
    ui->lineEdit_3->setVisible(false);
}

void MainWindow::on_pushButton_Draw_clicked()
{
    size_t index = ui->listWidget->currentRow();
    QString colour = ui->lineEdit_Index_2->text();
    if (index < v.size()) {
        ui->label_Error->setText(" ");
        Dialog g;
        g.setModal(true);
        g.Draw(v[index], colour);
        g.exec();
    } else {
        ui->label_Error->setText("неверный индекс");
    }
}
