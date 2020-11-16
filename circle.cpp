#include <cmath>
#include "circle.h"

Circle::Circle(int r)
    : Figure("CIRCLE"){
    if (r>=0){
        setRadius(r);
        P = (2 * 3.14 * R);
        S = (3.14 * R * R);
    }
    else{
        S=P=R=0;
    }
}

Circle::Circle()
    : Figure("CIRCLE")
    , P(0)
    , S(0),
      R(0) {}

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
    return R;
}

void Circle::setRadius(const int _r){
    if (_r>=0){
        R =_r;
        P = (2 * 3.14 * R);
        S = (3.14 * R * R);
    }
}

void Circle::Resize(const int _r){
    setRadius(_r);
}
