#include <iostream>
#include <string>

using namespace std;

class MyClass{
public:
    int data;
    MyClass(const MyClass& other){
        cout << "Copy constructor called" << endl;
        data = other.data;
    }   
    MyClass(int value) : data(value){
        cout << "Normal constructor called" << endl;
    }
};

int main(){
    MyClass obj1(10);
    MyClass obj2 = obj1;
    cout << "obj1.data: " << obj1.data << endl;
    cout << "obj2.data: " << obj2.data << endl;
    return 0;
}