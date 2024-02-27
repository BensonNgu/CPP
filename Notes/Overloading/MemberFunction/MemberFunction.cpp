#include <string>
#include <iostream>
#include "ComplexNumber.h"

using namespace std;

int main(){
    ComplexNumber a(2,3), b(4,5), c;
    c = a + b;
    c.print();

    return 0;
}