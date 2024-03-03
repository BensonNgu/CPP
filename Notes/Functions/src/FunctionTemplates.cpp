#include <string>
#include <iostream>

using namespace std;

template <typename T, typename F = less<T>>
int compare(const T &v1, const T &v2, F f=F()){
    if(f(v1, v2)) return -1;
    if(f(v2, v1)) return 1;
    return 0;
}

int main(){
    int x = 1;
    int y = 2;
    cout << compare(x, y) << endl;
    return 0;
}