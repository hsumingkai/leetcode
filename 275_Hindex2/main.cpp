#include <iostream>
#include <vector> 
#include <time.h>
#include <algorithm>
using namespace std ;

class Solution {
public:
    int hIndex_BST(vector<int>& citations) {
        int left=0, len = citations.size(), right= len-1,  mid;
        while(left<=right)
        {
            mid=left+ (right-left)/2;
            if(citations[mid] >= (len-mid)) right = mid - 1;
            else left = mid + 1;
        }
        return len - left;
    }
};

int main(int argc, const char * argv[])
{
    Solution *s = new Solution ;
    clock_t tStart = clock();
    vector<int> nums = {0,1,4,5,6} ;
    cout << "the h-index is " << s->hIndex_BST(nums) << endl ;

    printf("Time taken: %.8fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0 ;
    
}