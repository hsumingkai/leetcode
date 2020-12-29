#include <time.h>
#include <iostream>
#include <vector>

using namespace std ;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int n : nums)
            if (i < 2 || n > nums[i-2])
                nums[i++] = n;
        return i;
    }
};

int main(int argc, const char * argv[]) {
    clock_t tStart = clock();
    vector<int> number, number2;
    
    number = {1,2,2,2,3,3,3,4,4} ;
    Solution* s = new Solution ;
    cout << s->removeDuplicates(number) << endl ;
    
    for(int n:number)
        cout << n ; 

    
    printf("Time taken: %.10fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0 ;
}