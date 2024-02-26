#include <fstream>
#include <iostream>

using namespace std;

void loadData(){
    ifstream inData;
    inData.open("numbers.txt");
    string number;

    while(inData >> number){
        cout << number << " ";
    }

    inData.close();
}

void loadData2(){
    ifstream inData;
    inData.open("numbers.txt");
    string number;

    while(!inData.eof()){
        inData >> number;
        cout << number << " ";
    }

    inData.close();
}

void loadData3(){
    ifstream inData;
    ofstream outData;

    inData.open("names.txt");
    outData.open("marks.txt");

    string firstName, lastName;

    inData >> firstName >> lastName;

    outData << firstName << " " << lastName << " got " << 86.5 << " for Mathematics" << endl;

    inData.close();
    outData.close();

    cout << "First name: " << firstName << endl << "Last name: " << lastName << endl;
}

void loadData4(){
    int length = 20;
    float price;
    char productName[length];
    char filename[] = "expense.txt";
    ifstream inData;

    inData.open(filename);
    inData >> price;

    inData.getline(productName, length);
    cout << price << endl;
    cout << productName << endl;
}

void loadData5(){
    int length = 30;
    float price;
    char productName[length];
    char filename[] = "expense.txt";
    ifstream inData;
    inData.open(filename);
    inData.getline(productName, 30);
    cout << "Product Name: " << productName << endl;
}

int main(){
    loadData5();
}