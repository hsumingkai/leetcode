#include <algorithm>
#include <iostream>
#include <queue> 
using namespace std ; 
// https://leetcode.com/problems/implement-stack-using-queues/

class MyStack {
private:
queue<int> nums ;
queue<int> helper ;

public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        nums.push(x) ;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int num ;
        while(!nums.empty()){
            helper.push(nums.front()) ;
            num = nums.front() ;
            nums.pop() ;
        }

        while(!helper.empty()){
            if(helper.size() != 1)
            {
                nums.push(helper.front()) ;
            }
            helper.pop() ;
        }

        return num ;
    }
    
    /** Get the top element. */
    int top() {
        int num ;
        while(!nums.empty()){
            helper.push(nums.front()) ;
            num = nums.front() ;
            nums.pop() ;
        }

        while(!helper.empty()){
            nums.push(helper.front()) ;
            helper.pop() ;
        }

        return num ;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return nums.empty() ;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
int main(int argc, const char * argv[])
{
    MyStack* obj = new MyStack();
    obj->push(1) ;
    obj->push(12) ;
    int param_2 = obj->pop();
    int param_3 = obj->top();
    bool param_4 = obj->empty();

    cout << "the param 2 is " << param_2 << endl ;
    cout << "the param 3 is " << param_3 << endl ;
    if(param_4)
    {
        cout << "the queue is empty " << endl ;
    }
    else
    {
        cout << "the queue is not empty" << endl ;
    }
    
}