#pragma once
#ifndef RECTANLGE_H
#define RECTANLGE_H
#include "figure.h"

class Rect : public Figure {
public:
  Rect(int w, int h);

  float Perimeter() override;
  long double Area() override;
  std::string Name() override;
private:
  int P;
  double S;
};

#endif // RECTANLGE_H
