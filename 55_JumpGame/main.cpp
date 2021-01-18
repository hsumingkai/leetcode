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
    bool canJump(vector<int>& nums){
        int maxstep = 0;
        for (int i = 0; i < nums.size() ; ++i)
        {
            if(i > maxstep) 
                return false ;
            maxstep= max(nums[i] + i, maxstep) ;
            
        }

        return true ;
    }
};

int main(int argc, const char * argv[])
{
    Solution *s = new Solution ;
    vector<int> nums = {3,2,1,0,4} ;
    bool rs = s->canJump(nums)  ;
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