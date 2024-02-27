#include <string>
#include <iostream>
#include "ComplexNumber.h"
// #include "PrivateMember.h"

using namespace std;


// friend with multiple classes
class B;
class A{
    friend void frFunction(A&, B&);
private:
    int data;
public:
    A(int data) : data(data) {}
};

class B{
    friend void frFunction(A&, B&);
private:
    int data;
public:
    B(int data) : data(data){}
};

void frFunction(A& a, B& b) { 
    cout << a.data << " " << b.data << endl;
}

int main(){
    // operator overloading
    // ComplexNumber a(2,3), b(4,5), c;
    // c = a + b;
    // c.print();

    // access private member
    // Example* ex = new Example();
    // release(ex);

    // friend function with multiple classes
    // A a(3);
    // B b(5);

    // frFunction(a, b);

    // cout << a << endl << b ;

    ComplexNumber a;
    cin >> a;
    cout << a;
    return 0;
}