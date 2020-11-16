#include <cmath>
#include "circle.h"

Circle::Circle(int r)
    : Figure("CIRCLE")
    , P(2 * 3.14 * r)
    , S(3.14 * r * r),
      radius(r) {}


float Circle::Perimeter(){
  return P;
}
long double Circle::Area(){
  return S;
}
std::string Circle::Name(){
  return Type;
}

int Circle::getRadius() const{
    return radius;
}
