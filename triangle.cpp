#include "triangle.h"
#include <cmath>

Triangle::Triangle(double a, double b, double c)
    : Figure("TRIANGLE"){
    if (a<b+c && b<a+c && c<a+b && a>=0 && b>=0 && c>=0){
        A = a;
        B = b;
        C = c;
        P = a + b + c;
        S = sqrt((P/2)*(P/2 - a)*(P/2 - b)*(P/2 - c));
    }
    else{
        A=B=C=P=S=0;
    }
}

Triangle::Triangle()
    : Figure("TRIANGLE"), A(0), B(0), C(0) {
  P = A + B + C;
  S = sqrt((P/2)*(P/2 - A)*(P/2 - B)*(P/2 - C));
}


double Triangle::Perimeter(){
  return P;
}

double Triangle::Area(){
  return S;
}

std::string Triangle::Name(){
  return Type;
}

double Triangle::getA() const{
    return A;
}

double Triangle::getB() const{
    return B;
}

double Triangle::getC() const{
    return C;
}

void Triangle::setA(const double _a){
    if (_a>=0 && _a<C+B && B<_a+C && C<_a+B){
       A=_a;
       P=A+B+C;
       S = sqrt((P/2)*(P/2 - A)*(P/2 - B)*(P/2 - C));
    }
}

void Triangle::setB(const double _b){
    if (_b>=0 && _b<C+A && A<_b+C && C<_b+A){
       B=_b;
       P=A+B+C;
       S = sqrt((P/2)*(P/2 - A)*(P/2 - B)*(P/2 - C));
    }
}

void Triangle::setC(const double _c){
    if (_c>=0 && _c<B+A && B<_c+A && A<_c+B){
       C=_c;
       P=A+B+C;
       S = sqrt((P/2)*(P/2 - A)*(P/2 - B)*(P/2 - C));
    }
}

void Triangle::Resize(const double _a, const double _b, const double _c){
    if (_a>=0 && _b>=0 && _c>=0 && _c<_b+_a && _b<_c+_a && _a<_c+_b){
       A=_a;
       B=_b;
       C=_c;
       P=A+B+C;
       S = sqrt((P/2)*(P/2 - A)*(P/2 - B)*(P/2 - C));
    }
}


