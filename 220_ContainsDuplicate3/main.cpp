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

    // https://leetcode.com/problems/contains-duplicate-iii/discuss/824578/C%2B%2B-O(N)-time-complexity-or-Explained-or-Buckets-or-O(K)-space-complexity
    bool containsNearbyAlmostDuplicate_bucket_slidewinodw(vector<int>& nums, int k, int t) {
        int n = nums.size();
        
        if(n == 0 || k < 0  || t < 0) return false;
        
        unordered_map<int,int> buckets;
        
        for(int i=0; i<n; ++i) {
            int bucket = nums[i] / ((long)t + 1);
            
			// For negative numbers, we need to decrement bucket by 1
			// to ensure floor division.
			// For example, -1/2 = 0 but -1 should be put in Bucket[-1].
			// Therefore, decrement by 1.
            if(nums[i] < 0) --bucket;
            
            if(buckets.find(bucket) != buckets.end()) return true;
            else {
                buckets[bucket] = nums[i];
                if(buckets.find(bucket-1) != buckets.end() && (long) nums[i] - buckets[bucket-1] <= t) return true;
                if(buckets.find(bucket+1) != buckets.end() && (long) buckets[bucket+1] - nums[i] <= t) return true;
                
                if(buckets.size() > k) {
                    int key_to_remove = nums[i-k] / ((long)t + 1);
                    
                    if(nums[i-k] < 0) --key_to_remove;
                    
                    buckets.erase(key_to_remove);
                }
            }
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