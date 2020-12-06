#pragma once
#ifndef RECTANLGE_H
#define RECTANLGE_H
#include "figure.h"

class Rect : public Figure {
public:
  Rect(double w, double h);
  Rect();

  double Perimeter() override;
  double Area() override;
  std::string Name() override;

  double getHeight() const;
  double getWidth() const;

  void setHeight(const double _h);
  void setWidth(const double _w);
  void Resize(const double _w, const double _h);
private:
  double W,H;
  double P;
  double S;
};

#endif // RECTANLGE_H
