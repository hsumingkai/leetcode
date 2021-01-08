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
};

int main(int argc, const char * argv[])
{
    Solution *s = new Solution ;
    clock_t tStart = clock();
    vector<int> nums = {3,0,6,1,5} ;
    cout << "the h-index is " << s->hIndex(nums) ;

    printf("Time taken: %.8fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0 ;
    
}