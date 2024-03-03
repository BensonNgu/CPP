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

//void privateDestructor(){
//    Example *eg = new Example();
//    release(eg);
//}

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

int main(){

//    privateDestructor();

    return 0;
}