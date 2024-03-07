#ifndef _INLINENAMESPACE_H_
#define _INLINENAMESPACE_H_

#include <string>
#include <iostream>
using namespace std;

namespace mylib{
    inline namespace v1{
        void function1(){
            cout << "v1 function1" << endl;
        }
    }

    inline namespace v2{
        void function1(){
            cout << "v2 function1" << endl;
        }
    }
}

#endif