#include "PrivateMember.h"
#include <iostream>
using namespace std;

Example::~Example(){cout << "Destructor called" << endl;}

// friend function access the private function of the class
void release(Example* example){
    cout << "Release called" << endl;
    delete example;
}