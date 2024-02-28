#ifndef _COUNTER_H_
#define _COUNTER_H_
// global variable within the counter.h
int upperbound;
int lowerbound;
class counter {
public:
    counter(int n) {
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
private:
    // local variable in this class 
    int count;
};
#endif