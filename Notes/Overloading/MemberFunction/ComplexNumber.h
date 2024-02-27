#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

class ComplexNumber{
    int real;
    int img;
public:
    ComplexNumber();
    ComplexNumber(int, int);
    ComplexNumber operator+(const ComplexNumber&) const;
    // copy assignemnt operator
    const ComplexNumber& operator=(const ComplexNumber&);
    // Relational operator
    bool operator==(const ComplexNumber&) const;
    void print();
};

#endif