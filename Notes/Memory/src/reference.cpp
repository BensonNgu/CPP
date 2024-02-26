#include <iostream>

using namespace std;

// pass by value
int addOne(int x);

// pass by reference
void plusOne(int &x);

// mix
void sum(int x, int y, int &result);



int main(){
    // pass by value
    int x = 1;
    x = addOne(x);
    cout << "x: " << x << endl;

    // pass b y reference
    int y = 2;
    plusOne(y);
    cout << "y: " << y << endl;

    // mix
    // x = 2, y = 3, sum of x and y = 5
    int result;
    sum(x, y, result);
    cout << "result: " << result << endl;

}

int addOne(int x){
    return ++x;
}

void plusOne(int &x){
    ++x;
}


void sum(int x, int y, int &result){
    result = x + y;
}