#include <string>
#include <iostream>
#include "class_declaration.h"

using namespace std;

Person::Person(string name, int age){
    this->name = name;
    this->age = age;
};

void Person::display(){
    cout << "Person's name: " << name << endl;
};

Company::Company(string name, Person* employees, int numberOfEmployees){
    this->name = name;
    this->employees = employees;
    this->numberOfEmployees = numberOfEmployees;
};

void Company::displayCompany(){
    cout << "Company's name: " << name << endl;
    cout << "Number of employees: " << numberOfEmployees << endl;
    for(int i = 0; i < numberOfEmployees; i++){
        employees[i].display();
    }
}

void printUserName(string username){
    cout << "User name: " << username << endl;
}