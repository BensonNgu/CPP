#ifndef KEYBOARD_H
#define KEYBOARD_H
// input
string readString(string);
char readChar(string);
int readInt(string);
double readDouble(string);
bool readBool(string);                  // default true false option
bool readBool(string, string, string);  // custom true false option

// menu 
void line(string, unsigned);
void displayStudentInfo();
void displayMenu(string, string[], int);
int getUserOption(string, string[], int);


// program
void pause();
#endif