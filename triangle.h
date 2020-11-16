#pragma once
#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "figure.h"

class Triangle : public Figure {
public:
  Triangle(int a, int b, int c);
  Triangle();

  float Perimeter() override;
  long double Area() override;
  std::string Name() override;

  int getA() const;
  int getB() const;
  int getC() const;


  void setA(const int _a);
  void setB(const int _b);
  void setC(const int _c);
  void Resize(const int _a, const int _b, const int _c);

private:
  int A,B,C;
  float P;
  long double S;
};


#endif // TRIANGLE_H
