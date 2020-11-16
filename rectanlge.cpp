#include "rectanlge.h"

Rect::Rect(int w, int h): Figure("RECT")
  , P(2 * w + 2 * h)
  , S(w * h) {
}

float Rect::Perimeter(){
    return P;
  }
  long double Rect::Area(){
    return S;
  }
  std::string Rect::Name(){
    return Type;
  }
