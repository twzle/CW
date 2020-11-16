#include "triangle.h"

Triangle::Triangle(int a, int b, int c)
    : Figure("TRIANGLE") {
  P = a + b + c;
  S = sqrtl((P/2)*(P/2 - a)*(P/2 - b)*(P/2 - c));
}

float Triangle::Perimeter(){
  return P;
}
long double Triangle::Area(){
  return S;
}
std::string Triangle::Name(){
  return Type;
}
