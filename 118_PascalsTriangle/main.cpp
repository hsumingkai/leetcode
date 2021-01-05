#include <iostream>
#include <vector> 
#include <time.h>
using namespace std ;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> PascalsTriangle(numRows) ;
        if(numRows == 0)
            return PascalsTriangle ;
        
        vector<int> prelevel(1,1) ;

        PascalsTriangle[0] = prelevel ;

        // size of row
        for(int size = 2; size <=numRows; size++)
        {
            vector<int> level(size, 0) ;
            // j = 0 
            for(int j = 0; j < size; j++)
            {
                if(j == 0 || j==size - 1){
                    level[j] = 1 ;
                }
                else
                {
                    level[j] = prelevel[j] + prelevel[j-1];
                }

            }

            PascalsTriangle[size -1] = level ;
            prelevel = level ;
        }

        return PascalsTriangle ;
    }
};

int main(int argc, const char * argv[])
{
    Solution *s = new Solution ;
    clock_t tStart = clock();
    int n = 5 ;
    vector<vector<int>> vec = s->generate(n) ;
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j];
        }
        cout << endl ;
    }

    
    printf("Time taken: %.8fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0 ;
    
}