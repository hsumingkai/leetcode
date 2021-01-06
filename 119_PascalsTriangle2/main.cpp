#include <iostream>
#include <vector> 
#include <time.h>
using namespace std ;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // row index start from 0 ;
        vector<int> row(rowIndex + 1, 1) ;
        vector<int> lastrow(rowIndex + 1, 0) ;
        if(rowIndex == 0)
            return row ;
        // initialize row when rowIndex = 1 ;
        row[0] = 1 ;
        // using two pointer solution  
        int start, end ;
        for(int i = 2;i <= row.size() ; i++)
        {
            start = 0 ;
            end = i -1 ;

            lastrow = row ;
            while(start <= end)
            {
                if(start == 0)
                {
                    row[start] = 1 ;
                    ++start ;
                }
                else if(end == i - 1)
                {
                    row[end] = 1 ;
                    --end ;
                }
                else
                {
                    row[end] = row[start] = lastrow[start] + lastrow[start-1] ;
                    ++start ;
                    --end ;
                }

            }
        }
        return row ;
    }
};

int main(int argc, const char * argv[])
{
    Solution *s = new Solution ;
    clock_t tStart = clock();

    int rowindex = 3 ;
    vector<int> vec = s->getRow(rowindex) ;
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i];
    }
    cout << endl ;

    
    printf("Time taken: %.8fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0 ;
    
}