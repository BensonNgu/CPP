# Function
- All function needs to be declared prior to reaching <code>main()</code>, otherwise the compiler won't be able to recognize it.  
- There are many ways to declare a function
### Method 1 - Function declaration and definition at the same time
```c++
#include <iostream>
using namespace std;
void print(){
    cout << "Hello World" << endl;
}

int main(){
    print();
}
```
---
### Method 2 - Function declaration and definition seperately
```c++
#include <iostream>
using namespace std;
void print();

int main(){
    print();
}

void print(){
    cout << "Hello World" << endl;
}
```
---
### Method 3 - Function Declaration and definition in different files
Please refer to the following file:
- [<kbd>main.cpp</kbd>](src/main.cpp)
- [<kbd>print.cpp</kbd>](src/print.cpp)
- [<kbd>print.h</kbd>](src/print.h)