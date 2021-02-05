#include <stack> 
#include <algorithm>
#include <iostream>

// https://leetcode.com/problems/implement-queue-using-stacks/
class MyQueue {
public:
    /** Push element x to the back of queue. */
    void push(int x) 
    {
        while(!helper.empty())
        {
            nums.push(helper.pop()) ;
        }

        helper.push(x) ;

        while(!nums.empty())
        {
            helper.push(nums.pop()) ;
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        
    }
    
    /** Get the front element. */
    int peek() {
        
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        
    }
private:
    std::stack<int> helper ;
    std::stack<int> nums ;
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
    

}