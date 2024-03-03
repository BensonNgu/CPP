#include <iostream>
#include <string>
#include <utility>
#include <cstring>
#include <iomanip>

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
class Example{
    friend void release(Example* ex);
protected :
    ~Example(){cout << "destructor called" << endl;}
public :
    Example(){
        cout << "Constructor called" << endl;
    }
};

void release(Example* ex){
    cout << "Release called" << endl;
    delete ex;
}

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
public:
    virtual void print() const{
        cout << "Base::print() called" << endl;
    }
};

class Derived : public Base{
public:
    void display(){
        cout << "Data: " << Base::data << endl;
    }

    void print() const override{
        cout << "Derived::print() called" << endl;
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


// polymorphism
// the following is the code that show the Inheritance only
class Employee{
protected:
    char *firstName;
    char *lastName;
public:
    Employee(const char *first, const char *last) {
        firstName = new char[strlen(first) + 1];
        lastName = new char[strlen(last) + 1];
        strcpy(firstName, first);
        strcpy(lastName, last);
    }
    ~Employee(){
        delete[] firstName;
        delete[] lastName;
    }

    void print() const{
        cout << "Employee::print() called" << endl;
        cout << firstName << " " << lastName << endl;
    }

    void display(int num) const{
        cout << "Employee::display() called" << endl;
        cout << firstName << " " << lastName << endl;
    }
};

class Contractor : public Employee{
private:
    float rate;
    float hours;
public:
    Contractor(const char *first, const char *last, float r, float h) : Employee(first, last), rate(r), hours(h){}
    float getPay() const {return rate * hours;}
    void print() const{
        cout << "Contractor::print() called" << endl;
        Employee::print();          // way to call the base class method
        cout << " is a contractor with pay of $" << setiosflags(ios::fixed | ios::showpoint) << setprecision(2) << getPay() << endl;
    }

    void display(){
        cout << "Contractor::display() called" << endl;
        cout << firstName << " " << lastName << endl;
    }
};

class Shape{
private:
    string name;
public:
    virtual void draw() = 0;
};

class Square : public Shape{

public:
    void draw() override {
        cout << "Drawing a square" << endl;
    }
};

class Rectangle : public Shape{
public:
    void draw() override{
        cout << "Drawing a rectangle" << endl;
    }

};

class Circle final : public Shape{
public:
    virtual void draw() override{
        cout << "Drawing a circle" << endl;
    }
};

//class Oval : public Circle{
//public:
//    void draw() override{
//        cout << "Drawing an oval" << endl;
//    }
//};

class Oval : public Shape{
public:
    void draw() override{
        cout << "Drawing an oval" << endl;
    }
    virtual void print() final{
        cout << "Oval::print() called" << endl;
    }
};

//class AnotherShape : public Oval{
//public:
//    void draw() override{
//        cout << "Drawing another shape" << endl;
//    }
//
//    void print() override{
//        cout << "AnotherShape::print() called" << endl;
//    }
//};



// multiple inheritance
class Boat
{
private:
    string regNumber;
    int length;
    int maxSpeed ;
public:
    Boat(string regNum, int len, int speed) : regNumber(regNum), length(len), maxSpeed(speed){}
    void display() const {cout << "Boat: " << regNumber << " " << length << " " << maxSpeed << endl;}
};


class House {
private:
    int numberOfBeds;
    float hArea;
public:
    House(int n, float area) : numberOfBeds(n), hArea(area) {}
    void display() const {cout << "Number of beds: " << numberOfBeds << " Area: " << hArea << endl;};
};

class HouseBoat : public Boat, public House{
public:
    HouseBoat(string regNum, int len, int speed, int n, float area) : Boat(regNum, len, speed), House(n, area){}
    void display() const{
        cout << "HouseBoat is :" << endl;
        Boat::display();
        House::display();
    }
};


// diamond problem
// base class
class X{
private:
    int x;
public:
    X(int xx){x=xx;}
    void showX(){cout << "x = " << x << endl;}
};

// inherit from X
class U : public X{
private:
    int u;
public:
    U(int xx,int uu):X(xx){u=uu;}
    void showU(){showX();cout << "u = " << u << endl;}
};

class V : public X{
private:
    int v;
public:
    V(int xx,int vv):X(xx){v=vv;}
    void showV(){showX();cout << "v = " << v << endl;}
};

// place where the diamond problem occurs
class W : public U, public V{
private:
    int w;
public:
    W(int,int,int,int);
    void showW(){showU();showV();cout << "w = " << w << endl;}
};

W::W(int xx, int uu, int vv , int ww):U(xx,uu),V(xx+10,vv){w=ww;}

// In this case, W is allowed to hold two copies/instances of class X. Sometime can be annoying

// After adding virtual

// base class
class X2{
private:
    int x;
public:
    X2(int xx){x=xx;}
    X2(){x=0;};
    void showX(){cout << "x = " << x << endl;}
};

// inherit from X
class U2 : virtual public X2{
private:
    int u;
public:
    U2(int uu) {u=uu;}
    void showU(){showX();cout << "u = " << u << endl;}
};

class V2 : virtual public X2{
private:
    int v;
public:
    V2(int vv){v=vv;}
    void showV(){showX();cout << "v = " << v << endl;}
};

// place where the diamond problem occurs
class W2 : public U2, public V2{
private:
    int w;
public:
    W2(int,int,int,int);
    void showW(){showU();showV();cout << "w = " << w << endl;}
};

W2::W2(int xx, int uu, int vv , int ww):X2(xx), U2(uu),V2(vv){w=ww;}