#ifndef _DELAY_H_
#define _DELAY_H_
// global variable within the delay.h
namespace NS_Delay{
    int upperbound;
    int lowerbound;
    class delay {
    private:
       // local variable within the class
        int count;
    
    public:
        delay(int n) {
            if(n<=upperbound) count = n;
            else count = upperbound;
        }
        void reset(int n){
            if(n<=upperbound) count=n;
        }
        int run() {
            if(count > lowerbound) return count--;
            else return lowerbound;
        }
    };
}
#endif