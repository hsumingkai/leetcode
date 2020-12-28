#include <iostream>
#include <time.h>
#include <vector>
using namespace std ;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0)
            return 0 ; 

        int begin = 0, tail = nums.size() -1 ; 
        while(begin <= tail)
        {
            if(nums[begin] == val)
            {
                if(nums[tail] != nums[begin])
                {
                    nums[begin] = nums[tail] ;
                    tail-- ;
                }
                else 
                {
                    tail-- ;
                }
            }
            else
            {
                begin++ ;
            }
        }

        return tail + 1 ;
    }
};


int main(int argc, const char * argv[]) {
    clock_t tStart = clock();
    vector<int> number ;
    number = {3,2,2,3,3,2,3,4,3} ;
    cout << "the raw vector length is: " << number.size() << endl ;

    Solution* s = new Solution ;
    
    cout << "the new vector length is: " << s->removeElement(number, 3) << endl ;
    for(int n : number)
         cout<< n ;
    cout << endl ;



    printf("Time taken: %.8fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0 ;
}
