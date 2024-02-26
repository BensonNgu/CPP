# Procedural Programming
- Procedures, AKA routines, subroutines and functions
- declared or defined independently of the main program construct

## Why is it useful
The following is an example list of -procesure calls in a program:
```
Step 1: Call Procedure A
Step 2: Call Procedure B
Step 3: Call Procedure C
Step 4: Call Procedure A
Step 5: Call Procedure C
Step 6: Call Procedure B
Step 7: Call Procedure A
```

- Suppose each procedure has 100 lines of code.  
- Without seperate the program into fews procedure, the main program will have 700 lines of code.  
- The code might be referred to as <kbd>unstructed</kbd> or <kbd>sequential</kbd>
- If there is a bug in procedure A, we may spend too mach time on finding all bugs and debugging them. Which is time-wasting and not efficient.
- <kbd><b>Advantages</b></kbd>
    - code can be reused 
    - code that defined to carry out a specific function can be easily transferred to another program
    - program flow can be more readily tracked
        - easier for debugging
- <kbd><b>Disadvantages</b></kbd>
    - The exactness of the rules
        - Each individual function contain exact rules regarding the input and output
    - Similar but not identical pieces of code must be rewritten

