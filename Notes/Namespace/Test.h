#ifndef _test_h
#define _test_h

#include <iostream>
#include <string>

namespace iod{
    static std::string name = "test";
}

void showName();

class Car{
private:
    int id;
    std::string name;
public:
    Car(int, std::string);
};

void add(const int &, const int &, int &);

#endif