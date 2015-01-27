
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

class PeacefulLine
{
public:
    map<int, int> m;
	string makeLine(vector <int> x)
	{
        for (int i = 0; i < x.size(); i++) {
            if (m.count(x[i]) == 0) {
                m[x[i]] = 1;
            } else {
                m[x[i]]++;
            }
        }

        for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
            //printf("%d, %d\n", it->first, it->second);
            if (it->second > ((1 + x.size())/2)) return string("impossible");
        }
        return string("possible");
	}
};

