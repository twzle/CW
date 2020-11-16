#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H
#include "figure.h"

class Circle : public Figure {
public:
  Circle(int r);
  Circle();

  float Perimeter() override;
  long double Area() override;
  std::string Name() override;

  int getRadius() const;

  void setRadius(const int _r);
  void Resize(const int _r);
private:
  int R;
  float P;
  double S;
};


#endif // CIRCLE_H
