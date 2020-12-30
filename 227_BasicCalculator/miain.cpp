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

    void rotate_reverse(vector<int>& nums, int k)
    {
        k = k % nums.size() ;
        reverse(nums,0, nums.size() -1); 
        reverse(nums,0, k-1); 
        reverse(nums,k, nums.size() - 1); 
    }

    void reverse(vector<int>&nums, int start, int end)
    {
        while(start < end)
        {
            int tmp ;
            tmp = nums[start] ;
            nums[start] = nums[end] ;
            nums[end] = tmp ;
            start ++ ;
            end -- ;
        }
    }

};


int main(int argc, const char * argv[]) {
    clock_t tStart = clock();

    vector<int> number, number2 ;
    number = {1,2,3} ;
    Solution *s = new Solution ;
    s->rotate(number, 2) ;
    for(int n: number)
        cout << n ; 
    cout << endl ;

    number2 = {1,2,3,4,5} ;
    s->rotate_reverse(number2 , 7) ;
    for(int n2: number2)
        cout << n2 ;
    cout << endl ;
    




    printf("Time taken: %.8fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0 ;
}
