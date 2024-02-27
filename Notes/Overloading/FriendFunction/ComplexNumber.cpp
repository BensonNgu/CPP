#include "ComplexNumber.h"

#include <iostream>
#include <string>
using namespace std;

ComplexNumber::ComplexNumber() : real(0), img(0) {}

ComplexNumber::ComplexNumber(int real, int img) : real(real), img(img) {}

ComplexNumber operator+(const ComplexNumber& a, const ComplexNumber& b){
    ComplexNumber result;
    result.real = a.real + b.real;
    result.img = a.img + b.img;
    return result;
}

void ComplexNumber::print(){
    cout << "real: " << real << " img: " << img << endl;
}