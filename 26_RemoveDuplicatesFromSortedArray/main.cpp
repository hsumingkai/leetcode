#include <time.h>
#include <iostream>
#include <vector>
#include "array"
using namespace std ;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int n : nums)
            if (!i || n > nums[i-1])
                nums[i++] = n;
        return i;
    }
    
    int remmoveDuplicates_twoPointor(vector<int> &nums)
    {
        if(nums.size() == 0)
            return 0 ;
        int i =0,  j = 1 ;
        while(j != nums.size())
        {
            if(nums[i] == nums[j])
            {
                nums[i+1] = nums[j] ;
                j++ ;
                
            }
            else
            {
                nums[i+1] = nums[j] ;
                i++ ;
                j++ ;
            }
        }
        
        return i +1 ;
    }
};

int main(int argc, const char * argv[]) {
    clock_t tStart = clock();
    vector<int> number, number2;
    
    number =number2  = {1,2,2,2,3,4,5,6,7,7,7,8} ;
    Solution* s = new Solution ;
    cout << s->removeDuplicates(number) << endl ;
    
    for(int n: number)
    cout << n  ;
    cout << endl ;
    cout << s->remmoveDuplicates_twoPointor(number2) << endl ;

    for(int n: number2)
        cout << n  ;
    cout << endl ;
    printf("Time taken: %.10fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0 ;
}

