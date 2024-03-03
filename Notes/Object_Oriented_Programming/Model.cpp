#include <iostream>
#include <string>
#include <utility>

using namespace std;
// copy constructor
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

    void display(){
        cout << data << endl;
    }
};

// copy assignment operator (=) overload
class Pointier
{
public:
    int *x;
    Pointier(){x = new int(1);cout << "Default constructor called" << endl;}
    Pointier(int num){
        x = new int(num);
        cout << "Normal constructor called" << endl;
    }
    // overloading
    Pointier& operator=(const Pointier& point){
        cout << "Copy assignment operator" << endl;
        x = new int(*point.x);
        return *this;
    }
    void display()	{ cout << *x << endl; }
};

// move constructor
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

// move assignment operator (=) overloading
class Test2 {
private:
    int* data; // Pointer to dynamically allocated data

public:
    // Constructor
    Test2(int value) : data(new int(value)) {
        cout << "Constructor called for " << *data << endl;
    }

    Test2() : data(new int(0)){
        cout << "default Constructor called for " << *data << endl;
    }

    // Move operator
    Test2& operator=(Test2&& rhs) noexcept{
        cout << "Move assignment called" << endl;
        if(this != &rhs){
            delete data;        // dealocate the current data
            data = rhs.data;    // copy the another object's data
            rhs.data = nullptr; // delete the another object's data
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


// protected destructor
//class Example{
//    friend void release(Example* ex);
//protected :
//    ~Example(){cout << "destructor called" << endl;}
//public :
//    Example(){
//        cout << "Constructor called" << endl;
//    }
//};
//
//void release(Example* ex){
//    cout << "Release called" << endl;
//    delete ex;
//}

// Association classes
class Person;
class Contract;
class Company{
    string name;
    string address;
    Contract *contr;
public:
    Company(string name = "") : name(name),contr(NULL){};
    string getName() { return name;}
    void setContract(Contract *cn){contr = cn;}
    Contract *getContract() const {return contr;}
};

class Person{
    string name;
    Contract *contr;
public:
    Person(string name = "") : name(name),contr(NULL){}
    string getName() { return name;}
    void setContract(Contract *cn){contr = cn;}
    Contract *getContract() const {return contr;}
};

class Contract{
    Person *pers;
    Company *comp;
    int contNum;
    int duration;
    static float rate;
public:
    Contract (Person *worker, Company *company, int cN, int dr) : pers(worker), comp(company), contNum(cN), duration(dr){
        worker->setContract(this);
        company->setContract(this);
    }

    string getPersonName() {return pers->getName();}
    string getCompName() {return comp->getName();}
    float getRate() const {return rate;}
    int getDuration() const {return duration;}
    int getContNum() const {return contNum;}
};

float Contract::rate = 70;

class Base{
protected:
    int data;
};

class Derived : public Base{
public:
    void display(){
        cout << "Data: " << Base::data << endl;
    }
};

// nested class
class A{
private:
    int a;
    class B{
    private:
        int b;
    public:
        // contructor for B
        B(int bb) : b(bb){}

        void display(){cout << b << endl;}
    };
    B b;
public:
    // constructor for A
    A(int aa) : a(aa), b(0){}
    class C{
    private:
        int c;
    public:
        // constructor for C
        C(int cc) : c(cc) {}
        void display() {cout << c << endl;}
    };
    void display(){cout << a << endl;}
    void createB(int bb){
        b = B(bb);
    }
    void displayB(){b.display();}
};

class Cube
{
private:
    struct Vertex{
        int x, y, z;
    };
    int volume;
    Vertex node[8];
public:
    Cube(){};
    void setNode(int a, int b, int c){}

};