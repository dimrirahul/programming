
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

const int SZ = 64;
typedef unsigned long long LL;
class BitwiseEquations
{
public:
    void printLongLong(LL n) {
        for (int i = 63; i >= 0 ; i--) { printf("%d", (n & (1 << i)) ? 1 : 0 ); }
        printf("\n");
    }

	long long kthPlusOrSolution(int x, int k)
	{
        LL res = 0LL;
        REP(i, 64) { res &= 1 << i; }
        REP(i, 31) {
            if (x & (1 << i)) { res |= 1 << i; }
        }
        printLongLong(res);
        int pos = 0;
        REP(i, 30) {
            while (res & (1 << pos) ) pos++;
            if (k & (1 << i)) {res |= (1 << pos);};
            pos++;
        }
        return (long long) (res - (LL)x);
	}

};

