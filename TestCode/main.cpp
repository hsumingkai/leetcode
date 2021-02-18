#include <algorithm>
#include <iostream>
#include <stack> 
#include <string> 
#include <sstream> 
using namespace std ; 
int main(int argc, const char * argv[])
{
    string path = "/a/../../b/../c//.//" ;
    string res, s;
    stack<string>stk;
    stringstream ss(path);
}