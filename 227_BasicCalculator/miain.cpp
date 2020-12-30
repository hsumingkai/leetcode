#include <iostream>
#include <time.h>
#include <vector>
using namespace std ;

class Solution {
public:
    // cyclic replacements 
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size() ;
        int count = 0 ;
        for(int start = 0; count < nums.size(); start++)
        {
            int current = start ;
            int prev = nums[start] ;
            do{
                int next = (current + k ) % nums.size() ;
                int temp = nums[next] ;
                nums[next] = prev ;
                prev = temp ;
                current = next ; 
                count ++ ;
            } while (start != current); 
        }
    }
};


int main(int argc, const char * argv[]) {
    clock_t tStart = clock();

    vector<int> number ;
    number = {1,2,3} ;
    Solution *s = new Solution ;
    s->rotate(number, 2) ;
    for(int n: number)
        cout << n ; 
    




    printf("Time taken: %.8fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0 ;
}
