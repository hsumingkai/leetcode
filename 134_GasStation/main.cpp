#include <iostream>
#include <vector> 
#include <time.h>
using namespace std ;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start, gastank, travel ;
        start = -1 ;
        for(int tmpstart = 0; tmpstart < gas.size() ; tmpstart++)
        {
            // initialize gastank and add gas in first the step
            gastank = gas[tmpstart] - cost[tmpstart] ;
            travel = tmpstart ;
            if(gastank < 0)
            {
                continue ;
            }

            travel++ ;
            if(travel == gas.size())
                travel = 0  ;

            while(tmpstart != travel)
            {
                // when travel to end of vector and let's reset "travel"
                

                gastank = gastank + gas[travel] - cost[travel] ;
                if(gastank < 0)
                    break ;

                travel++ ;
                if(travel == gas.size())
                    travel = 0  ;
            }
            if(tmpstart >= 0 && gastank >= 0) 
                start = tmpstart ;
        }

        if(start == -1)
        {
            return -1 ;
        }
        else
        {
            return start ;
        }
    }

    int canCompleteCircuit_SumCompare(vector<int> &gas, vector<int> &cost) 
    {
        int start(0),total(0),tank(0);
        //if car fails at 'start', record the next station
        for(int i=0;i<gas.size();i++)
        {
            if((tank=tank+gas[i]-cost[i])<0) 
            {
                start=i+1;
                total+=tank;
                tank=0;
            }
        }

        return (total+tank<0)? -1:start;
    }
};

int main(int argc, const char * argv[])
{
    Solution *s = new Solution ;
    vector<int> gas, cost ;
    vector<int> gas2, cost2 ;
    int rs ; 

    gas = {1,2,3,4,5} ;
    cost = {3,4,5,1,2} ;
    clock_t tStart = clock();
    rs = s->canCompleteCircuit(gas, cost) ;

    if(rs == -1)
        cout << "there is not solution" << endl ;
    else
        cout << "the start index is " << rs << endl ;
    printf("Time taken: %.8fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    rs = s->canCompleteCircuit_SumCompare(gas, cost) ;

    clock_t tStart2 = clock();
    if(rs == -1)
        cout << "there is not solution" << endl ;
    else
        cout << "the start index is " << rs << endl ;

    printf("Time taken: %.8fs\n", (double)(clock() - tStart2)/CLOCKS_PER_SEC);
        

    gas2 = {3,1,1} ;
    cost2 = {1,2,2} ;
    rs = s->canCompleteCircuit(gas2, cost2) ;

    if(rs == -1)
        cout << "there is not solution" << endl ;
    else
        cout << "the start index is " << rs << endl ;

    


    return 0 ;
    
}