#include "ComplexNumber.h"

#include <iostream>
#include <string>
using namespace std;

ComplexNumber::ComplexNumber() : real(0), img(0) {}

ComplexNumber::ComplexNumber(int real, int img) : real(real), img(img) {}

ComplexNumber ComplexNumber::operator+(const ComplexNumber& a)const{
    ComplexNumber result;
    result.real = real + a.real;
    result.img = img + a.img;
    return result;
}

void ComplexNumber::print(){
    cout << "real: " << real << " img: " << img << endl;
}