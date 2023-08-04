using namespace std;

#include"stack"

class MinStack {

private:
stack<int>A;
stack<int>B;

public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        A.push(x);
        if(!B.empty())
        {
            B.push(::min(B.top(),x));
        }
        else
        {
            B.push(x);
        }
    }
    
    void pop() {
       
        A.pop();
        B.pop();
        

    }
    
    int top() {
        return A.top();

    }
    
    int min() {
        return B.top();

    }
};