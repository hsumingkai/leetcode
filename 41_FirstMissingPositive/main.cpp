#include <iostream>
#include <vector> 
#include <time.h>
using namespace std ;

class Solution {
public:
    // 把可能最小的正整數擺到相對應的index
    // ex: 
    // vector size : 4 
    // when value : 3, index : origin -> 2
    // when value : 2, index : origin -> 1
    // when value : 5, ignore
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size() == 0 )
            return 1 ;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(nums[i]<=0 || nums[i]>nums.size() || nums[i] == nums[nums[i] - 1])
                continue ;

            
            swap(nums[i], nums[nums[i]-1]) ;
            i-- ;
        }
        int i; 
        for(i = 0 ; i < nums.size() ; i++)
        {
            cout << nums[i] ;
            if(nums[i]-1 != i)
                return i+ 1 ;
        }
        cout << endl ;
        return i + 1;
    }
};

int main(int argc, const char * argv[])
{
    clock_t tStart = clock();
    Solution *s = new Solution ;
    vector<int> numbers, numbers2 ;
    numbers = {0,1,2} ;
    cout << s->firstMissingPositive(numbers) << endl ;
    cout << "---------" << endl ;
    numbers = {1} ;
    cout << s->firstMissingPositive(numbers) << endl ;



    printf("Time taken: %.8fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0 ;
    
}