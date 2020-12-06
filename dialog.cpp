#include "dialog.h"
#include "ui_dialog.h"
#include "triangle.h"
#include "rectanlge.h"
#include "circle.h"
#include <cmath>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::Draw(Figure *fig, QString colour) {
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    QPen outlinePen;
    outlinePen.setColor(colour);
    outlinePen.setWidth(5);

    if (fig->Name() == "CIRCLE") {
        Circle *p = dynamic_cast<Circle*>(fig);
        scene->addEllipse(0, 0, 2*p->getRadius(), 2*p->getRadius(), outlinePen);
    }
    else if (fig->Name() == "TRIANGLE") {
        Triangle *p = dynamic_cast<Triangle*>(fig);
        double a, b, c, cs, sn;
        a = p->getA();
        b = p->getB();
        c = p->getC();
        cs = (pow(a,2) + pow(c,2) - pow(b,2))/(2.0*a*c);
        sn = sqrt(1-pow(cs,2));
        QPolygon polygon;
        polygon << QPoint(0, 0) << QPoint(a, 0) << QPoint(c*cs/sn, c*sn/cs);
        scene->addPolygon(polygon, outlinePen);
    }
    else if (fig->Name() == "RECT") {
        Rect *p = dynamic_cast<Rect*>(fig);
        scene->addRect(0, 0, p->getWidth(), p->getHeight(), outlinePen);
    }
}
