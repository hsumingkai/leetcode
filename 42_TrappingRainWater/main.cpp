#include <iostream>
#include <vector> 
#include <time.h>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm> 

using namespace std ;
// https://leetcode.com/problems/trapping-rain-water/
class Solution {
public:
    int maxArea(vector<int>& height) {
        
    }

};

int main(int argc, const char * argv[])
{
    clock_t tStart = clock();

    Solution *s = new Solution ;
    vector<int> nums = {1,8,6,2,5,4,8,3,7} ;


    printf("Time taken: %.8fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0 ;
}