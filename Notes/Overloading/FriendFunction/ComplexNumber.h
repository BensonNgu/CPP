#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

class ComplexNumber{
friend ComplexNumber operator+(const ComplexNumber&, const ComplexNumber&);
    int real;
    int img;
public:
    ComplexNumber();
    ComplexNumber(int, int);
    void print();
};

#endif