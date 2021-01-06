#include <iostream>
#include <vector> 
#include <time.h>
#include <unordered_map>

using namespace std ;
class Solution {
public:
    // time O(n), space O(1)
    int majorityElement_BoyerMooreVoting(vector<int>& nums) 
    {
        int candidate, sum = 0 ; 
        for(int i = 0; i < nums.size(); i++)
        {
            if(sum == 0)
                candidate = nums[i] ;

            if(nums[i] == candidate)
            {
                ++sum ;
            }
            else
            {
                --sum ;
            }
        }
        return candidate ;
    }

    int majorityElement_unorderMap(vector<int>& nums) 
    {
        unordered_map<int, int> counter;
        for (int num : nums) {
            if (++counter[num] > nums.size() / 2) {
                return num;
            }
        }
        return 0;
    }

};
int main(int argc, const char * argv[])
{
    Solution *s = new Solution ;
    clock_t tStart = clock();
    vector <int> nums = {7, 7, 5, 7, 5, 1 , 5, 7 , 5, 5, 7, 7 , 7, 7, 7, 7} ;
    int rs = s->majorityElement_BoyerMooreVoting(nums) ;
    cout << "the majority number : " << rs << endl;
    printf("Time taken: %.8fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    clock_t tStart2 = clock();
    vector <int> nums2 = {7, 7, 5, 7, 5, 1 , 5, 7 , 5, 5, 7, 7 , 7, 7, 7, 7} ;
    int rs2 = s->majorityElement_unorderMap(nums2) ;
    cout << "the majority number : " << rs2 << endl;
    printf("Time taken: %.8fs\n", (double)(clock() - tStart2)/CLOCKS_PER_SEC);




    return 0 ;
}