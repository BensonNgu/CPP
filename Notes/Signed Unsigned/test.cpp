#include <iostream>
using namespace std; 

int main(){
    unsigned int x = 1;
    unsigned int y = -1;


    cout << "x: " << x << endl << "y: " << y << endl;

    if(x < y){
        cout << "X is smaller than Y" << endl;
    }else if(x >= y){
        cout << "X is equal to Y" << endl;
    }else{
        cout << "X is larger than Y" << endl;
    }

    

    // this is a comment
    

    return 0;
}