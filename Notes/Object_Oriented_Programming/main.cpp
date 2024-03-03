#include <iostream>
#include <string>
#include <utility>
#include "Model.cpp"

using namespace std;

void copy1(){
    MyClass myClass(5);
    MyClass myClass2(myClass);
    myClass.display();
    myClass2.display();
}

void copy2(){
    Pointier myPoint(5);
    Pointier myPoint2 = myPoint;        // default copy assignment
    cout << "Break point" << endl;
    myPoint2 = myPoint;              // custom copy assignment
    myPoint.display();
    myPoint2.display();
    // conclusion: to call the custom copy assignment operator, both object need to be initialised first.
}

void move1(){
    Test test(5);
    cout << "Break point" << endl;

    Test test2 = move(test);        // test is now deleted by setting the dynamic data as nullptr
    cout << "Break point" << endl;

    test.print();
    cout << "Break point" << endl;

    test2.print();
}

void move2(){
    Test2 test(10), test1;

    cout << "Break point" << endl;

    test1 = move(test);

    cout << "Break point" << endl;

    test.print();

    cout << "Break point" << endl;

    test1.print();
}

void privateDestructor(){
    Example *eg = new Example();
    release(eg);
}

void associationClass(){
    Person *worker = new Person("John");
    Company *company = new Company("Bell Pty Ltd");
    Contract *cont1 = new Contract(worker, company, 5247, 12);

    cout << worker->getName() << " has a contract number " << worker->getContract()->getContNum() << " with " << worker->getContract()->getCompName() << endl;

    cout << "Duration: " << worker->getContract()->getDuration() << " months" << endl;

    cout << "Rate: $" << worker->getContract()->getRate() << "/hr" << endl;
}

void nestedClasses(){
    A a(5);
    A::C c(10);
    a.createB(5);

    a.display();
    c.display();
}

void nestedClasses2(){

}

void polymorphism1(){
    Contractor ct1("Bob", "Smith", 40, 10);
    ct1.print();
    cout << "\nbreak point\n" << endl;
    ct1.Employee::print();

    cout << "\nbreak point\n" << endl;
    cout << "Calling the base class and derived class display()" << endl;
    ct1.display();
//    ct1.display(2);
    ct1.Employee::display(2);
}

void polymorphism2(){
    Contractor ct1("Bob", "Smith", 40, 10);
    cout << "use derived class reference" << endl;
    Contractor& r1 = ct1;
    r1.print();

    cout << "\nbreak point\n" << endl;

    cout << "use base class reference" << endl;
    Employee& r2 = ct1;
    r2.print();

    cout << "\nbreak point\n" << endl;

    cout << "use derived class pointer" << endl;
    Contractor* p1 = &ct1;
    p1->print();

    cout << "\nbreak point\n" << endl;

    cout << "Use base class pointer" << endl;
    Employee* p2 = &ct1;
    p2->print();

    cout << "\nbreak point\n" << endl;

    cout << "Using static_cast" << endl;
    // p1 = Contractor* and p2 = Employee*
    // static cast the base class pointer to derived class pointer
//    p1 = p2;          // incompatible pointer type assigned to Contractor* from Employee*
    p1 = static_cast<Contractor*>(p2);
    p1->print();
}

void polymorphism3(){
    Contractor ct1("Bob", "Smith", 40, 10);
    Employee e1("John", "Doe");

    // Array of Employee
    Employee* employees[2];
    employees[0] = &ct1;
    employees[1] = &e1;

    for(int i = 0; i < 2; i++){
        employees[i]->print();
    }
}

void virtualFunction(){
    Derived o1;
    Base o2;

    // Array of base class
    Base* arr[2];
    arr[0] = &o1;
    arr[1] = &o2;

    for(int i = 0; i < 2; i++){
        arr[i]->print();
    }
}

void pureVirtualFunction(){
//    Shape shape;        // error: cannot declare variable 'shape' to be of abstract type 'Shape'
    Square square;
    square.draw();

    Rectangle rectangle;
    rectangle.draw();
}

void diamondProblem(){
    W w(1,2,3,4);
    w.showW();

    cout << "\nbreak point\n" << endl;

    W2 w2(1,2,3,4);
    w2.showW();
}

int main(){

    diamondProblem();

    return 0;
}