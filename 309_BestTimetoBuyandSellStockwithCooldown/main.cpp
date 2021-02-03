#include <iostream>
#include <vector> 
#include <time.h>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm> 

using namespace std ;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
class Solution {
public:
    // https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/75928/Share-my-DP-solution-(By-State-Machine-Thinking)
    // https://www.youtube.com/watch?v=oL6mRyTn56M
    // Time: O(n), Space: O(n) 
    int maxProfit_dp(vector<int>& prices) {
		if (prices.size() <= 1) return 0;
		vector<int> s0(prices.size(), 0);
		vector<int> s1(prices.size(), 0);
		vector<int> s2(prices.size(), 0);
		s1[0] = -prices[0];
		s0[0] = 0;
		s2[0] = INT_MIN;
		for (int i = 1; i < prices.size(); i++) {
			s0[i] = max(s0[i - 1], s2[i - 1]); // max profit in rest
			s1[i] = max(s1[i - 1], s0[i - 1] - prices[i]); // minimun cost for next turn
			s2[i] = s1[i - 1] + prices[i]; // max sell profit
		}
		return max(s0[prices.size() - 1], s2[prices.size() - 1]);
	}

    // http://zxi.mytechroad.com/blog/dynamic-programming/leetcode-309-best-time-to-buy-and-sell-stock-with-cooldown/
    int maxProfit_dp2(vector<int>& prices) {
        int sold = 0;
        int rest = 0;
        int hold = INT_MIN;
        for (const int price : prices) {
            int prev_sold = sold;
            sold = hold + price;
            hold = max(hold, rest - price);
            rest = max(rest, prev_sold);
        }
        return max(rest, sold);
    }

};

int main(int argc, const char * argv[])
{
    clock_t tStart = clock();

    Solution *s = new Solution ;
    // vector<int> nums = {1,2,3,0,2} ;
    // vector<int> nums = {2,1,3,0, 0,2} ;
    vector<int> nums = {1,50,100,1,1,100} ;

    int rs = s->maxProfit_dp2(nums) ;

    cout << "the max profit is " << rs << endl; 


    printf("Time taken: %.8fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0 ;
}