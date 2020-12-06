#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H
#include "figure.h"

class Circle : public Figure {
public:
  Circle(double r);
  Circle();

  double Perimeter() override;
  double Area() override;
  std::string Name() override;

  double getRadius() const;

  void setRadius(const double _r);
  void Resize(const double _r);
private:
  double R;
  double P;
  double S;
};


#endif // CIRCLE_H
