#include <stack> 
#include <algorithm>
#include <iostream>
using namespace std ;
// https://leetcode.com/problems/min-stack/
class MinStack {
private:
    stack<int> s ;
    stack<int> mins ;
public:
    void push(int x) {
        if(s.empty())
        {
            s.push(x) ;
            mins.push(x) ;
        }
        else
        {
            int tmpMin = min(mins.top(), x) ;
            s.push(x) ;
            mins.push(tmpMin) ;
        }
        
    }
    
    void pop() {
        mins.pop() ;
        return s.pop() ;
    }
    
    int top() {
        return s.top() ;
    }
    
    int getMin() {
        return mins.top() ;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
int main(int argc, const char * argv[])
{
    MinStack* obj = new MinStack();
    obj->push(3);
    obj->push(1);
    obj->push(2);
    cout << "the min is " << obj->getMin() << endl ;

    cout << "the top is " << obj->top() << endl ;
    
    obj->pop();


    int param_4 = obj->getMin();

}