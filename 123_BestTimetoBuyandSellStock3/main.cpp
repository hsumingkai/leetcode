#include <iostream>
#include <vector> 
#include <time.h>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm> 

using namespace std ;
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
class Solution {
public:

    // https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/39611/Is-it-Best-Solution-with-O(n)-O(1).
    // time:O(n) , space:O(1)
    int maxProfit(vector<int>& prices) {
        int hold1 = INT_MIN, hold2 = INT_MIN;
        int release1 = 0, release2 = 0;
        for(int i:prices){                              // Assume we only have 0 money at first
            release2 = max(release2, hold2+i);     // The maximum if we've just sold 2nd stock so far.
            hold2    = max(hold2,    release1-i);  // The maximum if we've just buy  2nd stock so far.
            release1 = max(release1, hold1+i);     // The maximum if we've just sold 1nd stock so far.
            hold1    = max(hold1,    -i);          // The maximum if we've just buy  1st stock so far. 
        }
        return release2; ///Since release1 is initiated as 0, so release2 will always higher than release1.

    }

    // https://www.youtube.com/watch?v=a8xKiVTpdks
    // time:O(n) , space:O(n)
    int maxProfit_dp(vector<int>& prices)
    {

    }
};

int main(int argc, const char * argv[])
{
    clock_t tStart = clock();

    Solution *s = new Solution ;
    vector<int> nums = {3,3,5} ;
    // vector<int> nums = {7,1,5,3,6,4} ;
    // vector<int> nums = {0,1} ;
    int rs = s->maxProfit(nums) ;

    cout << "the max profit is " << rs << endl; 


    printf("Time taken: %.8fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0 ;
}