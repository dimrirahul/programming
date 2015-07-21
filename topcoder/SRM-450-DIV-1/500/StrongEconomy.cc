
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

//using LL = long long;
using LL = __uint128_t;
const bool dbg = true;
class StrongEconomy
{
    public:
        int p, t;
        LL findSpinIterations(LL target, LL sv, LL n, LL k) {
            if ((target - sv) < (n * k)) return 0;
            LL res = (target - sv) / (n * k);
            if ((res * n * k) < (target - sv)) res++;
            return res;
        }

        LL solve(LL n, LL k, LL c) {
            LL spinLoop = 0;
            if (c < p) {
                spinLoop = findSpinIterations(p, c, n, k);
                c += (spinLoop * n * k);
            }

            LL t1 = findSpinIterations(t, c, n, k);
            LL nn = n; LL nk = k;
            if (nn < nk) nn++;
            else nk++;

            LL t2 = findSpinIterations(t, c - p, nn, nk);
            if (t1 < t2) {
                return spinLoop + t1;
            } else {
                return spinLoop + solve(nn, nk, c - p);
            }
        }

        long long earn(long long n, long long k, long long price, long long target) {
            p = price; t = target;
            if (p >= target) return findSpinIterations(t, 0, n, k);
            return solve(n, k, 0);
        }
};

