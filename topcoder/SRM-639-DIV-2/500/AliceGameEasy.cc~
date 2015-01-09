
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

typedef long long LL;
class AliceGameEasy
{
public:
    LL isPossible(LL x, LL y) {
        LL p = 1 + 8 * (x + y);
        LL q = floor(sqrt(p));
        if ((q * q) != p) return (LL)-1;
        if ((q -1) %2 == 1 ) return (LL)-1;
        return (q-1)/2;
    }

	long long findMinimumValue(long long x, long long y)
	{
        LL n = isPossible(x, y);
        if (n < 0) return n;
        int res = 0;
        while (x > 0) {
            if (x < n) { res++; break; }
            else { x -= n; n--; res++;}
        }
        return res;
	}
};

