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
    // time:O(n^2) space: O(1)
    int maxProfit_bruteforce(vector<int>& prices) {
        if(prices.size() <= 1)
            return 0 ;

        int profit = 0 ;
        for(int i = 0; i < prices.size() ; i ++)
        {
            for(int j = i +1; j < prices.size() ; j ++)
            {
                if(prices[j] - prices[i] > profit)
                    profit = prices[j] - prices[i] ;
            }
        }
        return profit ;
    }
    // ref: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/solution/
    // time: O(n), space: O(1)
    int maxProfit(vector<int>& prices) {
        int minprice = INT_MAX;
        int maxprofit = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < minprice)
                minprice = prices[i];
            else if (prices[i] - minprice > maxprofit)
                maxprofit = prices[i] - minprice;
        }
        return maxprofit;
    }
    // ref: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/discuss/39038/Kadane's-Algorithm-Since-no-one-has-mentioned-about-this-so-far-%3A)-(In-case-if-interviewer-twists-the-input)
    // time: O(n), space: O(1)
    int maxProfit_Kadane(vector<int>& prices) {
        int maxCur = 0, maxSoFar = 0;
        for(int i = 1; i < prices.size(); i++) {
            maxCur = max(0, maxCur += prices[i] - prices[i-1]);
            maxSoFar = max(maxCur, maxSoFar);
        }
        return maxSoFar;
    }
};

int main(int argc, const char * argv[])
{
    clock_t tStart = clock();

    Solution *s = new Solution ;
    // vector<int> nums = {7,1,5,3,6,4} ;
    vector<int> nums = {0,1} ;
    int rs = s->maxProfit_Kadane(nums) ;

    cout << "the max profit is " << rs << endl; 


    printf("Time taken: %.8fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0 ;
}