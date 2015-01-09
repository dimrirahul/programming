
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
typedef unsigned long long UL;
class BitwiseEquations
{
public:
    void printLong(UL n) {
        bitset<sizeof(long long) * 8> b(n);
        printf("bitsetsays =%s\n", b.to_string().c_str());
        
        for(int i = 63; i >= 0; i--) {
            printf("%d", (n & (1<<i)) ? 1:0);
        }
    }
	long long kthPlusOrSolution(int x, int k)
	{
        UL res = (UL)x; 
        printLong(res);
        int xpos = 0;
        REP(i, 31) {
            while ( res & (1 << xpos) ) xpos++;
            printf("xpos=%d res=%llu ", xpos, res);
            if (k & (1 << i)) {
                res |= (1 << xpos) ;
                printf("k's %d bit is set setting bit %d in res res=%llu\n", i, xpos, res);
            } 
            xpos++;
        }
        printLong(res);
        printf("\n");
        printLong((UL) x);
        printf("res=%llu  x=%lld\n", res, (UL)x);
		return res - (UL)x;
	}
};

