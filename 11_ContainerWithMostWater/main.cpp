#include <iostream>
#include <vector> 
#include <time.h>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm> 

using namespace std ;
// https://leetcode.com/problems/container-with-most-water/
class Solution {
public:
    // Time: O(n) Space: O(1)
    int maxArea(vector<int>& height) {
        int end = height.size() - 1 ;
        int start = 0 ;
        int maxArea = -1 ;
        int tmpArea, x, y ;

        while(start < end)
        {
            x = end - start ;
            y = min(height[start], height[end]) ;
            tmpArea = x * y ;

            if(tmpArea > maxArea)
                maxArea = tmpArea ;

            if(height[start] < height[end])
                start++ ;
            else
                end -- ;
        }
        return maxArea ;
    }

};

int main(int argc, const char * argv[])
{
    clock_t tStart = clock();

    Solution *s = new Solution ;
    vector<int> nums = {1,8,6,2,5,4,8,3,7} ;
    // vector<int> nums = {1,1} ;

    int rs = s->maxArea(nums) ;

    cout << "the max area is " << rs << endl; 


    printf("Time taken: %.8fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0 ;
}