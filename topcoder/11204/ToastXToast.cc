
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

class ToastXToast
{
public:
    int getValue(vector<int> &u, vector<int> &o, int ustart, int uend, int ostart, int oend) {

        if (o[ostart] < u[ustart] || u[uend-1] > o[oend-1]) { 
            return -1;
        }

        while (ustart < uend && u[ustart] < o[ostart]) {
            ustart++;
        }

        if (ustart == uend) {
            return 1;
        }

        return 2;

    }
	int bake(vector <int> U, vector <int> O)
	{
        sort(U.begin(), U.end());
        sort(O.begin(), O.end());
        int count = getValue(U, O, 0, U.size(), 0, O.size());
        if (count > 1) {
            return 2;
        } else {
            return count;
        }
	}
};

