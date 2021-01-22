#include <iostream>
#include <vector> 
#include <time.h>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm> 
 

using namespace std ;

class Solution {
public:
    int jump_BFS(vector<int>& nums){
        // https://leetcode.com/problems/jump-game-ii/discuss/18014/Concise-O(n)-one-loop-JAVA-solution-based-on-Greedy
        int jumps, curEnd, curFarthest ;
        jumps = curEnd = curFarthest = 0 ;
        for(int i = 0; i < nums.size()-1; i++)
        {
            curFarthest = max(curFarthest, i + nums[i]) ;

            if(i == curEnd)
            {
                jumps++ ;
                curEnd = curFarthest ;
            }
        }

        return jumps ;
    }
    int jump_BFS2(vector<int>& nums) {
        int n = nums.size(), step = 0, start = 0, end = 0;
        while (end < n - 1) {
            step++; 
			int maxend = end + 1;
			for (int i = start; i <= end; i++) {
                if (i + nums[i] >= n - 1) return step;
				maxend = max(maxend, i + nums[i]);
			}
            start = end + 1;
            end = maxend;
        }
		return step;
    }
};

int main(int argc, const char * argv[])
{
    Solution *s = new Solution ;
    vector<int> nums = {1,0,2,3,4} ;
    // vector<int> nums = {2,3,1,1,4} ;
    // vector<int> nums = {2,3,0,1,4} ;
    int rs = s->canJump_Greedy(nums)  ;
    
    cout << "the minimum jump number is " << rs ;
    

    return 0 ;
    
}