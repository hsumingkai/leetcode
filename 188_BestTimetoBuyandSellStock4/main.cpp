#include <iostream>
#include <vector> 
#include <time.h>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm> 

using namespace std ;
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
class Solution {
public:
    
    // https://www.youtube.com/watch?v=oDhu5uGq_ic
    int maxProfit_twopointer(int k, vector<int>& prices) {
    }
};

int main(int argc, const char * argv[])
{
    clock_t tStart = clock();

    Solution *s = new Solution ;
    vector<int> nums = {3,2,6,5,0,3} ;
    int k = 2 ;
    int rs = s->maxProfit_twopointer(nums, k) ;

    cout << "the max profit is " << rs << endl; 


    printf("Time taken: %.8fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0 ;
}