#include <iostream>
#include <vector> 
#include <time.h>
#include <algorithm>
using namespace std ;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return false ;
    }
};
int main(int argc, const char * argv[])
{
    Solution *s = new Solution ;
    clock_t tStart = clock();
    vector<int> nums = {0,1,4,5,6} ;
    bool rs = s->containsDuplicate(nums) ;

    if(rs)
        cout << "the array contains duplicate element. "   << endl ;
    else
        cout << "the array contains distinct. "   << endl ;


    printf("Time taken: %.8fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0 ;
    
}