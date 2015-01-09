
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
typedef long long LL;
class BitwiseEquations
{
public:
    int arr[SZ];
	long long kthPlusOrSolution(int x, int k)
	{
        REP (i, SZ) arr[i] = 0;
        REP (i, 31) arr[i] = (x & (1 << i)) ? 1 : 0;
        int pos = 0;
        REP (i, 31) {
            while (arr[pos] == 1) pos++;
            if (k & (1 << i)) arr[pos] = 1;
            pos++;
        }
        LL res = 0;
        REP (i, 64) {
            res += arr[pos] * (1 << i);
        }

        return res - (LL)x;
	}

};

