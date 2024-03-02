#include <string>
#include <iostream>
#include <string.h>
#include <random>
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
const double Test::aStaticDouble = 5.0;

class Test2{
public:
    string name;
    Test2(){cout << "Default constructor called" << endl;};
    Test2(string name) : name(name){cout << "Constructing Test2 " << name << endl;}; 
    ~Test2(){cout << "Desctructor called " << name << endl;};
};

class Example{
    friend void release(Example* ex);
    private :
        ~Example(){cout << "Destructor called" << endl;};
    public :
        Example(){
            cout << "Constructor called" << endl;
        }
};

void release(Example* ex){
    cout << "Release called" << endl;
    delete ex;
}


// exception handling
// throwing string as an argument
void testDate(int day, int month, int year){
    if(day < 1 ||  day > 31){
        throw (string("Invalid day"));
    }
    if(month < 1 || month > 12){
        throw (string("Invalid month"));
    }
    cout << "The day and month is valid: " << day << "-" << month << "-" << year << endl;
}

// throwing integer as argument
void verifyEmail(string email){
    int loc1, loc2;
    string at = "@";
    string dot = ".";
    loc1 = email.find(at);
    loc2 = email.rfind(dot);
    if(loc1 == string::npos){
        throw (1);
    }else{
        cout << at << " found at " << loc1 << endl;
    }
    if(loc2 == string::npos){
        throw (2);
    }else{
        cout << dot << " found at " << loc2 << endl;
    }
    if(loc1 >= loc2){
        throw (3);
    }

    cout << "Email is valid: " << email << endl;
}

namespace NS{
    int i;
}

namespace NS{
    int j;
}

class Engine{
public:
    void start(){
        cout << "Starting engine..." << endl;
    }

};

class Car{
public:
    void start(Engine *engine){
        engine->start();
    }

};

int main(){
    Car *car = new Car();
    Engine *engine = new Engine();

    car->start(engine);

    return 0;
}