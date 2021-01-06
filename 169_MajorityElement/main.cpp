#include <iostream>
#include <vector> 
#include <time.h>

using namespace std ;
class Solution {
public:
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
};
int main(int argc, const char * argv[])
{
    Solution *s = new Solution ;
    // vector nums = {7, 7, 5, 7, 5, 1 , 5, 7 , 5, 5, 7, 7 , 7, 7, 7, 7} ;
    vector nums = {1} ;
    int rs = s->majorityElement_BoyerMooreVoting(nums) ;

    cout << "the majority number : " << rs << endl;

    clock_t tStart = clock();

    printf("Time taken: %.8fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0 ;
}