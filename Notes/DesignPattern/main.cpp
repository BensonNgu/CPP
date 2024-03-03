#include "Model.cpp"

void singleton(){
    Singleton::Show();
    Singleton *eg = Singleton::setInstance();
    eg->Show();

    eg->TidyUp();

    Singleton::Show();
}

void monostate(){
    Lab lab1, lab2;
    Admin admin1("psd1234"), admin2("mypas");

    cout << lab1.getLapCapacity() << endl << lab2.getLapCapacity() << endl;

    if(admin1.checkPassword("psd1234")){
        admin1.setLabCapacity(20);
    }

    cout << lab1.getLapCapacity() << endl << lab2.getLapCapacity() << endl;

    if(admin2.checkPassword("psd1234")){
        admin2.setLabCapacity(30);
    }

    cout << lab1.getLapCapacity() << endl << lab2.getLapCapacity() << endl;


}

int main(){
    monostate();

    return 0;
}