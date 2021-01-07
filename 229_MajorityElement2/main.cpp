#include <iostream>
#include <vector> 
#include <time.h>
#include <unordered_map>
#include <map>

using namespace std ;
class Solution {
public:
    // time O(n), space O(1)
    vector<int> majorityElement(vector<int>& nums) {
    
        vector<int> res;
        int a = 0, b = 0, cnt1 = 0, cnt2 = 0, n = nums.size();
        for (int num : nums) {
            if (num == a) ++cnt1;
            else if (num == b) ++cnt2;
            else if (cnt1 == 0) { a = num; cnt1 = 1; }
            else if (cnt2 == 0) { b = num; cnt2 = 1; }
            else { --cnt1; --cnt2; }
        }
        cnt1 = cnt2 = 0;
        for (int num : nums) {
            if (num == a) ++cnt1;
            else if (num == b) ++cnt2;
        }
        if (cnt1 > n / 3) res.push_back(a);
        if (cnt2 > n / 3) res.push_back(b);
        return res;
    }

};
int main(int argc, const char * argv[])
{
    Solution *s = new Solution ;
    vector <int> nums = {1,1,1,3,3,2,2,2} ;
    vector <int> rs = s->majorityElement(nums) ;
    for(int n : rs)
        cout << n ;
    cout << endl ;
    vector <int> nums2 = {3,2,3} ;
    vector <int> rs2 = s->majorityElement(nums) ;
    for(int n: rs2)
        cout << n ;
    cout << endl ;


    return 0 ;
}