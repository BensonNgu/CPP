#include <string>
using namespace std;


class Person{
private:
    string name;
    int age;
public:
    Person(string name, int age);
    void display();
};


class Company{
private:
    string name;
    Person* employees;
    int numberOfEmployees;
public:
    Company(string name, Person* employees, int numberOfEmployees);
    void displayCompany();
};


void printUserName(string username);
