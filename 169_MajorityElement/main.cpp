#include <iostream>
#include <vector> 
#include <time.h>
#include <unordered_map>
#include <map>

using namespace std ;
class Solution {
public:
    // time O(n), space O(1)
    int majorityElement_BoyerMooreVoting(vector<int>& nums) 
    {
        int candidate, sum = 0 ; 
        for(int i = 0; i < nums.size(); i++)
        {
            if(sum == 0)
                candidate = nums[i] ;

            if(nums[i] == candidate)
            {
                ++sum ;
            }
            else
            {
                --sum ;
            }
        }
        return candidate ;
    }

    // time O(n), space O(n)
    int majorityElement_unorderMap(vector<int>& nums) 
    {
        unordered_map<int, int> counter;
        for (int num : nums) {
            if (++counter[num] > nums.size() / 2) {
                return num;
            }
        }
        return 0;
    }

    // time O(n), space O(n)
    int majorityElement_Random(vector<int>& nums) 
    {
        bool flag = 1;
        int n = nums.size();
        while(1){
            int x = rand()%n;
            int val = nums[x], cnt = 0;
            for(int i=0;i<n;i++){
                if(nums[i]==val) cnt++;
            }
            if(cnt>n/2) return val;
        }
        return nums[0];
    }

    // time O(nlogk), space O(n)
    int majorityElement_BST(vector<int>& nums) {
        map<int, int> count;
        const int n = nums.size();
        for (const int num : nums)
            if (++count[num] > n / 2) return num;
        return -1;
    }

    int majorityElement_BitVoting(vector<int>& nums) {
        const int n = nums.size();
        int majority = 0;
        for (int i = 0; i < 32; ++i) {
            int mask = 1 << i;
            int count = 0;
            for (const int num : nums)
                if ((num & mask) && (++count > n /2)) {
                    majority |= mask;
                    break;
                }
        }
        return majority;
    }

};
int main(int argc, const char * argv[])
{
    Solution *s = new Solution ;
    vector <int> nums = {7, 7, 5, 7, 5, 1 , 5, 7 , 5, 5, 7, 7 , 7, 7, 7, 7} ;

    clock_t tStart = clock();
    int rs = s->majorityElement_BoyerMooreVoting(nums) ;
    cout << "the majority number : " << rs << endl;
    printf("Time taken: %.8fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    clock_t tStart2 = clock();
    int rs2 = s->majorityElement_unorderMap(nums) ;
    cout << "the majority number : " << rs2 << endl;
    printf("Time taken: %.8fs\n", (double)(clock() - tStart2)/CLOCKS_PER_SEC);

    clock_t tStart3 = clock();
    int rs3 = s->majorityElement_Random(nums) ;
    cout << "the majority number : " << rs3 << endl;
    printf("Time taken: %.8fs\n", (double)(clock() - tStart3)/CLOCKS_PER_SEC);

    clock_t tStart4 = clock();
    int rs4 = s->majorityElement_BST(nums) ;
    cout << "the majority number : " << rs4 << endl;
    printf("Time taken: %.8fs\n", (double)(clock() - tStart4)/CLOCKS_PER_SEC);
    
    clock_t tStart5 = clock();
    int rs5 = s->majorityElement_BitVoting(nums) ;
    cout << "the majority number : " << rs5 << endl;
    printf("Time taken: %.8fs\n", (double)(clock() - tStart5)/CLOCKS_PER_SEC);
    





    return 0 ;
}