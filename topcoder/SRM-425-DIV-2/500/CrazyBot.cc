
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

typedef pair <int, int> PI;
class CrazyBot
{
public:
    set<PI> visited;
    map<PI, double> table;
    double pe, pw, ps, pn;

    double startTraversing(PI s, int n) {
        //printf("Visiting Node = %d, %d\n", s.first, s.second);
        if (visited.count(s) > 0) return (double)0;
        if (n == 0) return (double)1;
        visited.insert(s);
        double res = 0;
        //printf("going up\n");
        res += pe * startTraversing(make_pair(s.first+1, s.second), n-1);
        //printf("going down\n");
        res += pw * startTraversing(make_pair(s.first -1, s.second), n-1);
        //printf("going right\n");
        res += pn * startTraversing(make_pair(s.first, s.second+1), n-1);
        //printf("going left\n");
        res += ps * startTraversing(make_pair(s.first, s.second-1), n-1);
        visited.erase(s);
        return res;
    }
	double getProbability(int n, int east, int west, int south, int north)
	{
        pe = (double)east/100;
        pw = (double)west/100;
        pn = (double)north/100;
        ps = (double)south/100;

        return startTraversing(make_pair(0,0), n);
	}
};

