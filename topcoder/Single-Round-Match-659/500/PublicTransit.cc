
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

typedef pair <int , int> PI;
typedef pair <PI, PI> PPI;
class PublicTransit
{
public:
        map<PPI, int> dp;
        int R, C;
        int getD(PI p1, PI p2) {
            return abs(p1.first - p2.first) + abs (p1.second - p2.second);
        }
        int getD(PI start, PI end, PI t1, PI t2) {
            return min (getD(start, end), min(getD(start, t1) + getD(end, t2), getD(start, t2) + getD(end, t1)));
        }
        int solve(PI t1, PI t2) {
            if (dp.count(make_pair(t1, t2)) > 0) return dp[make_pair(t1, t2)];
            int res = 0;
            REP(i, R) {
                REP (j, C) {
                    REP (k, R) {
                        REP (l, C) {
                            res = max(res, getD(make_pair(i, j), make_pair(k, l), t1, t2));
                        }
                    }
                }
            }
            dp[make_pair(t1, t2)] = res;
            dp[make_pair(t2, t1)] = res;
            return res;
        }
	int minimumLongestDistance(int r, int c)
	{
            R = r;
            C = c;
            int res = 5000;
            REP(i, R) {
                REP (j, C) {
                    REP(k, R) {
                        REP(l, C) {
                            res = min(res, solve(make_pair(i, j), make_pair(k, l)));
                        }
                    }
                }
            }
		return res;
	}
};

