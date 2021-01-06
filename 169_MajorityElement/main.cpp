#include <iostream>
#include <vector> 
#include <time.h>

using namespace std ;
class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        
    }
};
int main(int argc, const char * argv[])
{
    Solution *s = new Solution ;
    vector nums = {2,3,4,4,4,2,2,2,2} ;
    int rs = s->majorityElement(nums) ;

    cout << "the majority number : " << rs << endl;

    clock_t tStart = clock();

    printf("Time taken: %.8fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0 ;
}