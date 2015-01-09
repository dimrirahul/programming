
// {{{ Boilerplate Code <--------------------------------------------------
// vim:filetype=cpp:foldmethod=marker:foldmarker={{{,}}}

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

// }}}

class PalindromizationDiv2
{
public:
    int getAtPos(int num, int pos) {
        return ( num / (int) pow(10, pos)) % 10;
    }

    int getLength(int num) {
        int len = 1;
        while (num / 10 > 0) {
            len++;
            num = num / 10;
        }
        return len;
    }

    bool isPalindrome(int num) {
        int len = getLength(num);
        for (int i  = 0; i < len/2 ; i++) {
            if ( getAtPos(num, i) != getAtPos(num, len -1 -i) ) {
                return false;
            }
        }
        return true;
    }
	int getMinimumCost(int x)
	{
        int high, low;
        high = low = x;
        while(true) {
            if (isPalindrome(high)) {
                break;
            } 
            high++;
        }

        while (true) {
            if (isPalindrome(low)) {
                break;
            }
            low--;
        }

        return min(high-x, x-low);
		
	}
};

