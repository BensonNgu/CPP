#include <string>
#include <iostream>
#include <string.h>
// #include "class_declaration.h"

using namespace std;
size_t count_calls()
{
    static size_t count = 0;
    return ++count;
}

constexpr int square(int x) {
    return x * x;
}

int add(int x, int y){
    return x + y;
}

int subtract(int x, int y){
    return x - y;
}

int performOperation(int (* operationPtr) (int, int), int a, int b){
    return operationPtr(a, b);
}   

struct Test{
    static const int aStaticInt = 5;
    static const double aStaticDouble;
    // static const string aStaticString = "Hello world";
};

class Test2{
public:
    string name;
    Test2(){cout << "Default constructor called" << endl;};
    Test2(string name) : name(name){cout << "Constructing Test2 " << name << endl;}; 
    ~Test2(){cout << "Desctructor called " << name << endl;};
};



const double Test::aStaticDouble = 5.0;
int main(){
    return 0;
}