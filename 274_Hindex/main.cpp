#include <iostream>
#include <vector> 
#include <time.h>
using namespace std ;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int hIndex , tmph ;
        tmph = 0 ;
        for(int n : citations) 
        {
            int count = 0 ;
            for(int m : citations)
            {
                if(n <= m)
                    ++count ; 
            }
            if(n > count && count > tmph)
                tmph = count ;
            else if(count >= n && n > tmph)
                tmph = n ;
        }
        

        return tmph ;
    }
    // ref :https://leetcode.com/problems/h-index/discuss/785356/C%2B%2B-bucket-sort-O(n)
    int hIndex_BucketSort(vector<int>& citations)
    {
        int N = citations.size();
        vector<int> buckets(N+1, 0);

        for(int i : citations){
            if (i >= N){
                buckets[N]++;
            } else {
                buckets[i]++;
            }
        }

        int count = 0;
        for(int i = N; i >= 0; i--){
            count += buckets[i];
            if(count >= i) {
                return i;
            }
        }

        // should not reach here
        return 0;
    }
};

int main(int argc, const char * argv[])
{
    Solution *s = new Solution ;
    clock_t tStart = clock();
    vector<int> nums = {3,0,6,1,5} ;
    cout << "the h-index is " << s->hIndex(nums) << endl ;

    cout << "the h-index is " << s->hIndex_BucketSort(nums) << endl ;

    printf("Time taken: %.8fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0 ;
    
}