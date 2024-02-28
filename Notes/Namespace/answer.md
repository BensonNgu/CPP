## Given `date::year`, what is date? Class? Namespace?
1. If year is a ==static variable==, then date could be a class name
    ```cpp
    class date{
    private:
        static int year;
    }

    int date::year = 2004;
    int main(){

    }
    ```
2. If year is a ==variable==, then date could be a namespace
    ```cpp
    namespace date{
        int year;
    }

    int main(){
        date::year = 2004;

    }
    ```
3. If year is a ==class name==, then date could be a namespace
    ```cpp
    namespace date{
        class year{
            // declaration and definition
        }
    }

    int main(){
        date::year obj;
    }
    ```