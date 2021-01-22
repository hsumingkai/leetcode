#include <iostream>
#include <vector> 
#include <time.h>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm> 

using namespace std ;
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
    }
};

int main(int argc, const char * argv[])
{
    clock_t tStart = clock();

    Solution *s = new Solution ;
    vector<int> nums = {7,1,5,3,6,4} ;


    printf("Time taken: %.8fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0 ;
}