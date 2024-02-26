# Memory

## Pointing to memory

- Primitive types mao directly on to memory entities like bytes and words
- most processors are designed to work with these entities
- Allows C++ to efficiently use the hardware withiout there being an abstraction in between
- Memory is effectively seen as a sequence of bytes 
- each typed object is govcen a location in memory, and values are placed in such objects

## Referencing

- We can access to the memory location of the variable by using the address-of operator `&`
```c++
int value = 5;

cout << "Value: " << value << endl << "Address: " << &value << endl;
```

- We can use this operator to create an alies for specific variable
```c++
int value = 5;
int &referenceValue = value;

cout << "Value: " << value << endl << "Address: " << &value << endl;
cout << "referenceValue: " << referenceValue << endl << "Address: " << &referenceValue << endl;
```
> Be careful !!!  
 Since the value as well as the memory location for both `value` and `referenceValue` are the same  
 Any changes on value for both of the variable will take affect on both variable

```c++
int otherValue = referenceValue;
cout << "otherValue: " << otherValue << endl << "Address: " << &otherValue << endl;
```
- The above code show a declaration of a new variable `otherValue` with an initial value equal to the value in `value`
- This is because `referenceValue` is the alias of `value` 
- At the end, `otherValue` only shared the same initial value as `value` but not the same memory location

## Pass by reference

- Ways to pass variable to function:
    - pass by value
    ```c++
    int addOne(int x);
    ```
    - pass by reference
    ```c++
    void addOne(int &x);
    ```
    - mix
    ```c++
    void sum(int x, int y, int &result);
    ```

    [<kbd>Example</kbd>](./src/reference.cpp)

## Pointers
- an object that store the memory address of the variable
- Use the `*`, AKA deferencing operator, to declare a pointer
> Be careful  
 It is tied to the variable name, not the type name 
```c++
// Declaring a single pointer in a single line
int* ptr1;
int * ptr2;
int *ptr3;

// Declaring multiple pointers in a single line
int * ptr4, * ptr5;
```
- since the above are the pointer to an `int`, so it stores the location of an `int` 

### How to use pointers
```c++
int value;
int * ptr;
ptr = &value;
```
Explaination  
1. A variable `value` is declared and alocates a memory address to it without any value
2. An integer pointer `ptr` is declared and alocates a memory address to it without any value
3. The memory address of the variable `value` is then assigned to the pointer `ptr`

#### Other usage of pointers
- change value of the variable that it is pointed to
```c++
*ptr = 5;
cout << value << endl;
// value = 5
```

### Summary of `&` and `*` operators
- `&` can be used to `extract` the memory address of the variable
- `*` can be used to `dereference` the memory address of the variable and access to the variable's value