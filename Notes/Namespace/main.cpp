#include <iostream>
// #include "counter.h"
// #include "delay.h"
// #include "Test.h"
#include "inlineNamespace.h"

using namespace std;


// class date{
// private:
//     static int year;
// public:
//     static void setYear(int nYear){
//         year = nYear;
//     }
//     static int getYear() { return year; }
// };

class Date{
private:
    int year = 2003;
public:
    int getYear() { return year; }
};




int main() {
    namespace latest = mylib::v2;
    latest::function1();
    mylib::v1::function1();
    return 0;
}

