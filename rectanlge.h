#pragma once
#ifndef RECTANLGE_H
#define RECTANLGE_H
#include "figure.h"

class Rect : public Figure {
public:
  Rect(int w, int h);
  Rect();

  float Perimeter() override;
  long double Area() override;
  std::string Name() override;

  int getHeight() const;
  int getWidth() const;

  void setHeight(const int _h);
  void setWidth(const int _w);
  void Resize(const int _w, const int _h);
private:
  int W,H;
  int P;
  double S;
};

#endif // RECTANLGE_H
