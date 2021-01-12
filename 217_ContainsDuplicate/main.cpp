#include <iostream>
#include <vector> 
#include <time.h>
#include <set>
#include <unordered_map>

using namespace std ;
class Solution {
public:
    // ref: https://leetcode.com/problems/contains-duplicate/discuss/60898/Single-line-C%2B%2B-solution-60ms
    bool containsDuplicate_set(vector<int>& nums) {
        return nums.size() > set<int>(nums.begin(), nums.end()).size();
    }
    // ref: https://leetcode.com/problems/contains-duplicate/discuss/61110/C%2B%2B-solutions-(sorting-maps-and-sets).
    bool containsDuplicate_unorderedmap(vector<int>& nums) {
        unordered_map<int, bool> myMap;
        for (auto& num: nums) {
            if (myMap.find(num) != myMap.end())
                return true;
            else
                myMap[num] = true;
        }
        return false;
    }


};
int main(int argc, const char * argv[])
{
    Solution *s = new Solution ;
    clock_t tStart = clock();
    vector<int> nums = {0,1,4,5,6} ;
    // bool rs = s->containsDuplicate_unorderedmap(nums) ;
    bool rs2 = s->containsDuplicate_unorderedmap(nums) ;

    if(rs2)
        cout << "the array contains duplicate element. "   << endl ;
    else
        cout << "the array contains distinct. "   << endl ;

    printf("Time taken: %.8fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0 ;
    
}