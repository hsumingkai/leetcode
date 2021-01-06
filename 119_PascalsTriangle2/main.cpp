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

    vector<int> getRow_UpdateFromEnd(int rowIndex) {
        vector<int> A(rowIndex+1, 0);
        A[0] = 1;
        for(int i=1; i<rowIndex+1; i++)
            for(int j=i; j>=1; j--)
                A[j] += A[j-1];
        return A;
    }
};

int main(int argc, const char * argv[])
{
    Solution *s = new Solution ;

    clock_t tStart = clock();
    int rowindex = 30 ;
    vector<int> vec = s->getRow(rowindex) ;
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl ;

    printf("Time taken: %.8fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    clock_t tStart2 = clock();
    vector<int> vec2 = s->getRow_UpdateFromEnd(rowindex) ;
    for (int i = 0; i < vec2.size(); i++)
    {
        cout << vec2[i] << " ";
    }
    cout << endl ;
    printf("Time taken: %.8fs\n", (double)(clock() - tStart2)/CLOCKS_PER_SEC);

    

    return 0 ;
    
}