#include <stack> 
#include <vector> 
#include <iostream>
#include <string>
using namespace std ; 
class Solution {
    stack<int> nums ;
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.size() == 0)
            return 0 ;
        if(tokens.size() == 1)
            return stoi(tokens[0]) ;

        int rs = 0 ;
        for(string input: tokens)
        {
            if(input == "+")
                rs = do_add(rs) ;
            else if(input == "-")
                rs = do_substract(rs) ;
            else if(input == "*")
                rs = do_multiply(rs) ;
            else if(input == "/")
                rs = do_divide(rs) ;
            else
                nums.push(stoi(input)) ;
        }

        return rs ;
    }
protected:
    int do_add(int rs){
        int n1, n2 ;
        n2 = nums.top() ;
        nums.pop() ;
        n1 = nums.top() ;
        nums.pop() ;
        rs = n1 + n2 ;
        nums.push(rs) ;
        return rs ;
    }

    int do_substract(int rs){
        int n1, n2 ;
        n2 = nums.top() ;
        nums.pop() ;
        n1 = nums.top() ;
        nums.pop() ;
        rs = n1 - n2 ;
        nums.push(rs) ;
        return rs ;
    }

    int do_multiply(int rs){
        int n1, n2 ;
        n2 = nums.top() ;
        nums.pop() ;
        n1 = nums.top() ;
        nums.pop() ;
        rs = n1 * n2 ;
        nums.push(rs) ;

        return rs ;
    }

    int do_divide(int rs){
        int n1, n2 ;
        n2 = nums.top() ;
        nums.pop() ;
        n1 = nums.top() ;
        nums.pop() ;
        rs = n1 / n2 ;
        nums.push(rs) ;
        return rs ;
    }


};
int main(int argc, const char * argv[])
{
    // vector<string> input = {"2", "1", "+", "3", "*"} ;
    vector<string> input = {"4", "13", "5", "/", "+"} ;
    
    Solution * obj = new Solution() ;

    int rs = obj->evalRPN(input) ;

    cout << "the rs is " << rs << endl ;
}