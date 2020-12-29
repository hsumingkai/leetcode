#include <iostream>
#include <time.h>
#include <vector>
using namespace std ;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k == nums.size())
            return ;
        int tmp, nextindex ; 
        for(int i = 0; i < nums.size(); i++)
        {
            nextindex = (i + k) % nums.size() ;
            tmp = nums[nextindex] ;
            nums[nextindex] = nums[i] ;
        }
    }
};


int main(int argc, const char * argv[]) {
    clock_t tStart = clock();

    vector<int> number ;
    number = {1,2,3,4,5,6} ;
    Solution *s = new Solution ;
    s->rotate(number, 1) ;
    for(int n: number)
        cout << n ; 
    




    printf("Time taken: %.8fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0 ;
}
