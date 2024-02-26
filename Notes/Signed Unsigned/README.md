# signed and unsigned qualifier
- Variable that declared as unsigned only represent the values that is greater than or equal to zero

```c++
unsigned int x = 1;
unsigned int y = -1;
```

From the above example, line 1 and 2 can be compile.  
Unfortunately, line 2 will be gibberish numbers when pass to cout

[<kbd>Test out the example</kbd>](./test.cpp)