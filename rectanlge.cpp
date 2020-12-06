#include "rectanlge.h"

Rect::Rect(double w, double h): Figure("RECT")
  , W(w), H(h), P(2 * w + 2 * h)
  , S(w * h) {
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
  , W(0), H(0), P(0),S(0) {
}

double Rect::Perimeter(){
    return P;
  }

double Rect::Area(){
    return S;
  }

std::string Rect::Name(){
    return Type;
  }

double Rect::getHeight() const{
    return H;
}

double Rect::getWidth() const{
    return W;
}

void Rect::setHeight(const double _h){
    if (_h>=0){
        H=_h;
        P=2 * W + 2 * H;
        S=W*H;
    }
}

void Rect::setWidth(const double _w){
    if (_w>=0){
        W=_w;
        P=2 * W + 2 * H;
        S=W*H;
    }
}

void Rect::Resize(const double _w, const double _h){
    if (_w>=0 && _h>=0){
       W=_w;
       H=_h;
       P =(2 * W + 2 * H);
       S=(W * H);
    }
}
