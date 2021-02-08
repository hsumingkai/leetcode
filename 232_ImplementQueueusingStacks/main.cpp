#include <algorithm>
#include <iostream>
#include <stack> 
using namespace std ; 

// https://leetcode.com/problems/implement-queue-using-stacks/
class MyQueue {
private:
    stack<int> helper ;
    stack<int> nums ;
public:
    /** Push element x to the back of queue. */
    void push(int x) 
    {
        while(!nums.empty())
        {
            helper.push(nums.top()) ;
            nums.pop() ;
        }

        helper.push(x) ;

        while(!helper.empty())
        {
            nums.push(helper.top()) ;
            helper.pop() ;
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int num = nums.top() ;
        nums.pop() ;
        return num ;
    }
    
    /** Get the front element. */
    int peek() {
        return nums.top() ; 
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return nums.empty() ;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
int main(int argc, const char * argv[])
{
    MyQueue* obj = new MyQueue();
    obj->push(1) ;
    obj->push(12) ;
    int param_2 = obj->pop();
    int param_3 = obj->peek();
    bool param_4 = obj->empty();

    cout << "the param 2 is " << param_2 ;
    cout << "the param 3 is " << param_3 ;
    if(param_4)
    {
        cout << "the queue is empty " << param_4 ;
    }



}