#include <iostream>
#include <vector> 
#include <time.h>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std ;
class Solution {
public:
    // https://leetcode.com/problems/contains-duplicate-ii/discuss/61390/C%2B%2B-solution-with-unordered_set
    bool containsDuplicate_unorderedset(vector<int>& nums, int k){
       unordered_set<int> s;
       
        if (k <= 0) return false;
        if (k >= nums.size()) k = nums.size() - 1;
       
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > k) s.erase(nums[i - k - 1]);
            // check whether nums[i] is found in unordered_set
            if (s.find(nums[i]) != s.end()) 
            {
                return true;

            }
            s.insert(nums[i]);
        }
       
        return false;
    }
    bool containsNearbyDuplicate_unorderedmap(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap;
        for(int i = 0; i < nums.size(); ++i) {
            if(hashMap.find(nums[i]) != hashMap.end() && i - hashMap[nums[i]] <= k)  return true;
            hashMap[nums[i]] = i;
        }
        return false;
    }



};
int main(int argc, const char * argv[])
{
    Solution *s = new Solution ;
    clock_t tStart = clock();
    vector<int> nums = {1,2,3,1,2,3} ;
    // bool rs = s->containsDuplicate_unorderedmap(nums) ;
    bool rs2 = s->containsDuplicate_unorderedset(nums, 2) ;

    if(rs2)
        cout << "rs is true . "   << endl ;
    else
        cout << "rs is false. "   << endl ;

    printf("Time taken: %.8fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0 ;
    
}