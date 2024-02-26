# Compilation
## One file 
- file:  <kbd>main.cpp</kbd>
syntax:
```shell
g++ filename.cpp -o applicationName.extentionName
```
> The extention name may be differ for different OS

example:
```shell
C:\Users\benson> g++ main.cpp -o main.exe
C:\Users\benson> ./main
```

## Multiple files
file: 
- <kbd>main.cpp</kbd>  <- This file use some function in print.cpp
- <kbd>print.h</kbd>    <- This file contains all the function declarations for functions in print.cpp
- <kbd>print.cpp</kbd>  <- This file contains all the function definitions  
[<kbd>Example</kbd>](../Functions/README.md)

### Methos 1 - Direct compilation
```shell
C:\Users\benson> g++ main.cpp print.cpp -o main.exe
C:\Users\benson> ./main
```
### Method 2 - Create object file
```shell
C:\Users\benson> g++ -c print.cpp 
C:\Users\benson> g++ main.cpp print.o -o main.exe
C:\Users\benson> ./main
```
