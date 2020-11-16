#include "rectanlge.h"

Rect::Rect(int w, int h): Figure("RECT")
  , P(2 * w + 2 * h)
  , S(w * h), W(w), H(h) {
    if (w>=0 && h>=0){
        W=w;
        H=h;
        P =(2 * w + 2 * h);
        S=(w * h);
    }
    else{
        W=H=P=S=0;
    }
}

Rect::Rect(): Figure("RECT")
  , P(0)
  , S(0), W(0), H(0) {
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

int Rect::getHeight() const{
    return H;
}

int Rect::getWidth() const{
    return W;
}

void Rect::setHeight(const int _h){
    if (_h>=0){
        H=_h;
        P=2 * W + 2 * H;
        S=W*H;
    }
}

void Rect::setWidth(const int _w){
    if (_w>=0){
        W=_w;
        P=2 * W + 2 * H;
        S=W*H;
    }
}

void Rect::Resize(const int _w, const int _h){
    if (_w>=0 && _h>=0){
       W=_w;
       H=_h;
       P =(2 * W + 2 * H);
       S=(W * H);
    }
}
