#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H
#include "figure.h"

class Circle : public Figure {
public:
  Circle (int r);

  float Perimeter() override;
  long double Area() override;
  std::string Name() override;

  int getRadius() const;
private:
  int radius;
  float P;
  double S;
};


#endif // CIRCLE_H
