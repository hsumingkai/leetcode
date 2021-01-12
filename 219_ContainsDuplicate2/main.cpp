#include <iostream>
#include <vector> 
#include <time.h>
#include <set>
#include <unordered_set>

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
           if (s.find(nums[i]) != s.end()) return true;
           s.insert(nums[i]);
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
    bool rs2 = s->containsDuplicate_unorderedset(nums, 3) ;

    if(rs2)
        cout << "there is duplicate element in the array . "   << endl ;
    else
        cout << "the array is distinct. "   << endl ;

    printf("Time taken: %.8fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0 ;
    
}