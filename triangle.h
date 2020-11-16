#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "figure.h"

class Triangle : public Figure {
public:
  Triangle(int a, int b, int c);

  float Perimeter() override;
  long double Area() override;
  std::string Name() override;
private:
  float P;
  long double S;
};


#endif // TRIANGLE_H
