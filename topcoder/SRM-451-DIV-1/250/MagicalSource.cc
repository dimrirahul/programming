
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

using LL = long long;
class MagicalSource
{
    public:
        LL pow(int exp) {
            LL res = 1;
            REP(i, exp) res *= 10;
            return res;
        }

        long long calculate(long long x) {
            LL num = 9 * x;
            LL res = num;
            for (int i = 1;; i++) {
                LL den = pow(i) - 1;
                LL t = num / den;
                if ( t == 0) break;
                if (den * t == num) res = t;
            }
            return res;
        }
};

