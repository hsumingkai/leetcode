#include <algorithm>
#include <iostream>
#include <stack> 
#include <string> 
#include <sstream> 
using namespace std ; 
// https://leetcode.com/problems/simplify-path/
class Solution {
public:
    // https://leetcode.com/problems/simplify-path/discuss/25687/C%2B%2B-using-stack
    string simplifyPath(string path)  {
        string res, s;
        stack<string>stk;
        stringstream ss(path);
        while(getline(ss, s, '/')) {
            if (s == "" || s == ".") continue;
            if (s == ".." && !stk.empty()) stk.pop();
            else if (s != "..") stk.push(s);
        }
        while(!stk.empty()){
            res = "/"+ stk.top() + res;
            stk.pop();
        }
        return res.empty() ? "/" : res;
    }
};

int main(int argc, const char * argv[])
{
    Solution * obj = new Solution() ;
    string s1 ; 
    // string input = "/a/./b/../../c/" ;
    string input = "/a/../../b/../c//.//" ;
    // string input = "/../../" ;

    cout << "the canonical path is " << obj->simplifyPath(input)  << endl ;

}