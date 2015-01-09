
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

class TheSimpleGame
{
public:

	int count(int n, vector <int> x, vector <int> y)
	{
        int res = 0; 
        n--;
        REP(i, x.size()) {
            x[i]--; 
            y[i]--;
            int d1 = abs(x[i] ) + abs (y[i]);
            int d2 = abs(n-x[i]) + abs(y[i]);
            int d3 = abs(n-x[i]) + abs (n-y[i]);
            int d4 = abs(x[i]) + abs(n-y[i]);
            int d = min( min(d1, d2), min (d3, d4));
            res += d;
        }
		return res;
	}
};

