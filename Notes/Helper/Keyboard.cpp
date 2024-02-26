#include "Keyboard.h"

#include <string>
#include <iostream>
#include <limits>
#include <sstream>

using namespace std;

typedef numeric_limits<streamsize> size;

const int FIXED_LENGTH = 40;
const string NAME = "Ngu Cheng Jie";
const string ID = "8245800";

// input
string readString(string prompt){
    string result;
    cout << prompt;
    getline(cin, result);
    cin.ignore();
    return result;
}
char readChar(string prompt){
    char result;
    cout << prompt;
    
    while(!cin>>result){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Please try again: ";
    }
    return result;
}
int readInt(string prompt){
    int result;
    cout << prompt;
    while(!(cin >> result)){
        cout << "Invalid input. Please enter an integer !!!" << endl << prompt;
        cin.clear();
        cin.ignore(size::max(), '\n');
    }
}
double readDouble(string prompt){

}
bool readBool(string prompt){        // default true false option

}                  
bool readBool(string prompt, string trueString, string falseString){    // custom true false option
    string result;
    ostringstream os;
    os << prompt << " (" << trueString << "/" << falseString << "): ";
    while(true){
        result = readString(os.str());
        if(result == trueString) return true;
        if(result == falseString) return false;
        cout << "Invalid input. Please enter again !!!" << endl;
    }
}  

// menu 
void line(string s, unsigned len = FIXED_LENGTH){
    string r, si = s;
    for(unsigned q = len / s.size(); q > 0; q >>= 1){
        if(q & 1) r += si;
        si+=si;
    }
    r += s.substr(0, len - r.size());

    cout << r << endl;
}
void displayStudentInfo(){
    cout << "Student ID: " << ID << endl << "Student Name: " << NAME << endl;
}

// NOTE: the menu item should include the exit program or back to previous page option
void displayMenu(string title, string menuItem[], int size){
    line("-");
    cout << title << endl;
    line("=");
    for(int i = 0; i < size; i++){
        cout << (i+1) << ")\t" << menuItem[i] << endl;
    }
}

int getUserOption(string title, string menuItem[], int size){
    displayMenu(title, menuItem, size);
    while(true){
        int option = readInt("\nPlease enter your option: ");
        if(option < 1 || option > (size)){
            cout << "Invalid option. Please enter again !!!" << endl;
        }else{
            return option;
        }
    }
}


// program
void pause(){
    cout << "Press <enter> to continue..." << endl;
    cin.ignore();
}