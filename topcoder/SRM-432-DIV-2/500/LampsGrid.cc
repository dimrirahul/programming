
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

class LampsGrid
{
public:
    int canLight(string s, int k) {
        int h = 0;
        REP(i, s.size()) { if (s[i] - '0' == 0) h++; }
        if (h > k) return false;
        if ((k - h) % 2 != 0 ) return false;
        return true;
    }
	int mostLit(vector <string> initial, int K)
	{
        map <string, int> uniq;
        REP (i, initial.size()) {
            if (uniq.count(initial[i]) > 0) {
                uniq[initial[i]] = uniq[initial[i]] + 1;
            } else {
                uniq[initial[i]] = 1;
            }
        }

        int res = 0;
        for (map<string, int>::iterator it = uniq.begin(); it != uniq.end(); it++) {
            if (canLight(it->first, K)) res = max(res, it->second);
        }
        return res;
	}
};

