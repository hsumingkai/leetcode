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
    bool canJump_Greedy(vector<int>& nums){
        int maxstep = 0;
        for (int i = 0; i < nums.size() ; ++i)
        {
            if(i > maxstep) 
                return false ;
            maxstep= max(nums[i] + i, maxstep) ;
            
        }

        return true ;
    }

    bool canJump_Greedy2(vector<int>& nums)
    {
        int lastPos = nums.size() -1 ;
        for(int i = nums.size()-1; i>=0 ; i--)
        {
            if(i+nums[i] >= lastPos)
            {
                lastPos = i ;
            }
        }
        return lastPos == 0 ;

    }
};

int main(int argc, const char * argv[])
{
    Solution *s = new Solution ;
    vector<int> nums = {1,0,2,3,4} ;
    bool rs = s->canJump_Greedy(nums)  ;
    if(rs)
    {
        cout << "can jump to end" ;
    }
    else
    {
        cout << "cant jump to end" ;
    }
    

    return 0 ;
    
}