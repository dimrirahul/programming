
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

const int SZ = 63;
class MutaliskEasy
{
public:
    int dp[SZ][SZ][SZ];
        int solve(int a, int b, int c) {
            if (( a  == b ) && (c == 0) && (b == c))return 0;
            if (dp[a][b][c] != -1) return dp[a][b][c];
            int v1 = solve(max(a-9, 0), max(b-3, 0), max(c-1, 0));
            int v2 = solve(max(a-9, 0), max(b-1, 0), max(c-3, 0));
            int v3 = solve(max(a-3, 0), max(b-9, 0), max(c-1, 0));
            int v4 = solve(max(a-3, 0), max(b-1, 0), max(c-9, 0));
            int v5 = solve(max(a-1, 0), max(b-9, 0), max(c-3, 0));
            int v6 = solve(max(a-1, 0), max(b-3, 0), max(c-9, 0));
            int res = min(min(min(min(min(v1, v2), v3), v4), v5),v6);
            dp[a][b][c] = dp[a][c][b] = dp[b][a][c] = dp[b][c][a] = dp[c][a][b] = dp[c][b][a] = res + 1;
            return res+1;
        }
	int minimalAttacks(vector <int> x)
	{
            REP(i, SZ) REP(j, SZ) REP(k, SZ) dp[i][j][k] = -1;
		return solve(x[0], x[1], x[2]);
	}
};

