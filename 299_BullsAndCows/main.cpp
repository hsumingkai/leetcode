#include <iostream>
#include <vector> 
#include <time.h>
#include <string>
#include <algorithm>
using namespace std ;

class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> Vec(10, 0) ;
        int Bull, Cow, i ;
        i = Bull = Cow = 0 ;

        if(secret.size() != guess.size() || secret.size() == 0 || guess.size() == 0 ) return "0A0B" ;
        while(i < secret.size())
        {
            if(secret[i] == guess[i])
            {
                Bull++ ;
            }
            else
            {
                if(Vec[secret[i]-'0']++ < 0)
                    Cow++ ;
                if(Vec[guess[i]-'0']-- > 0)
                    Cow++ ;
            }
            i++ ;
        }

        return to_string(Bull) + 'A' + to_string(Cow) + 'B';
    }
};

int main(int argc, const char * argv[])
{
    clock_t tStart = clock();
    string secret = "1123" ;
    string g = "0111" ;
    string test = "" ;
    Solution *s = new Solution ; 
    cout << s->getHint(secret, g) ;

    printf("Time taken: %.8fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0 ;

}