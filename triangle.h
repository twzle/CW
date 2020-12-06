#pragma once
#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "figure.h"

class Triangle : public Figure {
public:
  Triangle(double a, double b, double c);
  Triangle();

  double Perimeter() override;
  double Area() override;
  std::string Name() override;

  double getA() const;
  double getB() const;
  double getC() const;


  void setA(const double _a);
  void setB(const double _b);
  void setC(const double _c);
  void Resize(const double _a, const double _b, const double _c);

private:
  double A,B,C;
  double P;
  double S;
};


#endif // TRIANGLE_H
