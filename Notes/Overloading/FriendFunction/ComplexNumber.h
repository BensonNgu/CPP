#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

#include <iostream>
using namespace std;

class ComplexNumber{
//koverloading operator
friend ComplexNumber operator+(const ComplexNumber&, const ComplexNumber&);
// overloaig ostream
friend ostream& operator<<(ostream&, const ComplexNumber&);
friend istream& operator>>(istream&, ComplexNumber&);
private:
    int real;
    int img;
public:
    ComplexNumber();
    ComplexNumber(int, int);
    void print();
};

#endif