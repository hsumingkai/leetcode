#include <iostream>
#include <vector> 
#include <time.h>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm> 

using namespace std ;
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/submissions/
class Solution {
public:
    // time: O(n), space: O(1)
    int maxProfit_twopointer(vector<int>& prices) {
        if(prices.size() <= 1)
            return 0 ;
        int first, end, profit ;
        profit = first = 0 ;
        end = 1 ;

        while(end <= prices.size() -1)
        {
            if(prices[first] < prices[end])
            {
                profit += prices[end] - prices[first] ;
                first = end ;
                end++ ;
            }
            else
            {
                first++;
                end++ ;
            }
        }
        return profit ;
    }
};

int main(int argc, const char * argv[])
{
    clock_t tStart = clock();

    Solution *s = new Solution ;
    vector<int> nums = {1,2,3,4,5} ;
    // vector<int> nums = {7,1,5,3,6,4} ;
    // vector<int> nums = {0,1} ;
    int rs = s->maxProfit(nums) ;

    cout << "the max profit is " << rs << endl; 


    printf("Time taken: %.8fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0 ;
}