#include <iostream>
#include <string>

using namespace std;

class Singleton{
private:
    static Singleton* instance;
protected:
    Singleton() {};
public:
    static Singleton* setInstance();
    static void Show() {cout << instance << endl;}
    static void TidyUp();
};

Singleton* Singleton::instance = nullptr;

Singleton* Singleton::setInstance(){
    if(instance == nullptr){
        instance = new Singleton();
    }
    return instance;
}

void Singleton::TidyUp(){
    delete instance;
    instance = nullptr;
}

// monostate

class Admin;

class Lab{
    friend class Admin;
private:
    static int labCapacity;
public:
    int getLapCapacity(){return labCapacity;}
};

int Lab::labCapacity = 25;

class Admin{
private:
    bool permit;
    string password;
public:
    Admin(string password){
        if(this->password == "") this->password = password;
    }

    bool checkPassword(string password){
        permit = (this->password == password);
        if(permit) cout << "Correct password" << endl;
        else cout << "Incorrect password" << endl;
        return permit;
    }

    void setLabCapacity(int newCapacity){
        if(permit){
            Lab::labCapacity = newCapacity;
        }
    }
    
};