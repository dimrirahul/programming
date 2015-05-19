
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

class FilipTheFrog
{
public:
	int countReachableIslands(vector <int> positions, int L)
	{
            int res = 1;
            int start = positions[0];
            sort(ALL(positions));
            int pos = 0;
            while (positions[pos] != start) pos++;
            int p2 = pos + 1;
            while (p2 < positions.size() && positions[p2] - positions[p2-1] <= L) {
                res++;
                p2++;
            }
            p2 = pos - 1;
            while(p2 >= 0 && abs(positions[p2] - positions[p2 + 1]) <= L) {
                res++;
                p2--;
            }
            return res;
	}
};

