#include "Test.h"

#include <string>
#include <iostream>

using namespace std;
// using namespace iod;
void showName() {
    cout << iod::name << endl;
}

Car::Car(int id, string name) : id(id), name(name) {}

void add(const int &a, const int &b, int &result) {
    result = a + b;
}