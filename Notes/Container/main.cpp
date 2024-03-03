#include <iostream>
#include <string>

#include <vector>

using namespace std;

int main(){
    vector<int> arr;
    // insert item at the end of the array
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    vector<int>::iterator it = arr.begin();
    // way to move the iterator
    it++;
    // way to access the data
    cout << *(it+1) << endl;
    cout << typeid(it).name() << endl;

    // pop the last element
    arr.pop_back();
    cout << arr.size() << endl;
    return 0;
}