#include <iostream>
#include <string>
#include <utility>
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

class Pointier 
{
public:
    int *x;
    Pointier(){x = new int(1);}
    Pointier(int num){
        x = new int(num);
    }
    Pointier& operator=(const Pointier& point){
        x = new int(*point.x);
        return *this;
    }
    void display()	{ cout << *x << endl; }
};

class Test {
private:
    int* data; // Pointer to dynamically allocated data

public:
    // Constructor
    Test(int value) : data(new int(value)) {
        cout << "Constructor called for " << value << endl;
    }

    // Move constructor
    Test(Test&& other) noexcept : data(other.data) {
        cout << "Move constructor called for " << *data << endl;
        other.data = nullptr; // Reset the source object's pointer
    }

    // Destructor
    ~Test() {
        delete data; // Deallocate dynamically allocated memory
        cout << "Destructor called \n";
    }

    // Print method
    void print() const {
        if(data != nullptr){
            cout << "Data: " << *data << std::endl;
        }else{
            cout << "Data does not exists\n";
        }
    }
};

class Test2 {
private:
    int* data; // Pointer to dynamically allocated data

public:
    // Constructor
    Test2(int value) : data(new int(value)) {
        cout << "Constructor called for " << value << endl;
    }

    // Move constructor
    // Test2(Test2&& other) noexcept : data(other.data) {
    //     cout << "Move constructor called for " << *data << endl;
    //     other.data = nullptr; // Reset the source object's pointer
    // }

    // Move operator
    Test2& operator=(Test2&& rhs) noexcept{
        cout << "Move assignment called" << endl;
        if(this != &rhs){
            delete data;
            data = rhs.data;
            rhs.data = nullptr;
        }
        return *this;
    }

    // Destructor
    ~Test2() {
        delete data; // Deallocate dynamically allocated memory
        cout << "Destructor called \n";
    }

    // Print method
    void print() const {
        if(data != nullptr){
            cout << "Data: " << *data << std::endl;
        }else{
            cout << "Data does not exists\n";
        }
    }
};


int main(){
    Test2 obj1(10);
    Test2 obj2(0);
    cout << "\nBefore move assignment\n";
    obj1.print();
    obj2.print();

    obj2 = move(obj1);
    cout << "\nAfter move assignment\n";
    obj1.print();
    obj2.print();
    return 0;
}