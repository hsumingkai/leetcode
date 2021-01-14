#include <iostream>
#include <vector> 
#include <time.h>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std ;
class Solution {
public:
    // ref: https://leetcode.com/problems/contains-duplicate-iii/discuss/61641/C%2B%2B-using-set-(less-10-lines)-with-simple-explanation.
    bool containsNearbyAlmostDuplicate_unorderedset(vector<int>& nums, int k, int t) {
        set<long> window; // set is ordered automatically 
        for (int i = 0; i < nums.size(); i++) {
            // keep the set contains nums i j at most k
            long n = nums[i] ;
            if (i > k) window.erase(nums[i-k-1]); 
            // |x - nums[i]| <= t  ==> -t <= x - nums[i] <= t;
            // x-nums[i] >= -t ==> x >= nums[i]-t 
            auto pos = window.lower_bound(n - t); 
            // x - nums[i] <= t ==> |x - nums[i]| <= t    
            if (pos != window.end() && *pos - n <= t) return true;
            window.insert(n);
        }
        return false;
    }
};
int main(int argc, const char * argv[])
{
    Solution *s = new Solution ;
    clock_t tStart = clock();
    vector<int> nums = {1,5,9} ;

    bool rs2 = s->containsNearbyAlmostDuplicate_unorderedset(nums, 3, 3) ;

    if(rs2)
        cout << "rs is true . "   << endl ;
    else
        cout << "rs is false. "   << endl ;

    printf("Time taken: %.8fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0 ;
    
}