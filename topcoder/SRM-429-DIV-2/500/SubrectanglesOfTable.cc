
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
const int SIZE=100;
const int MAX_CHARS = 26;
typedef long long LL;
class SubrectanglesOfTable
{
public:
    char store[SIZE][SIZE];
    int R, C;
    long long count[MAX_CHARS];

    void init(vector<string>& t) {
        C = t[0].size() * 2;
        R = t.size() * 2;
        REP(i, t.size()) {
            REP(j, t[i].size()) {
                store[i][j] = store[i + R/2][j] = store[i][j+ C/2] = store[i+R/2][j+C/2] = t[i][j];
            }
        }
        REP(i, MAX_CHARS) count[i] = 0;
    }
	vector<long long> getQuantity(vector <string> table)
	{
        init(table);
        LL rc = (LL)R * C;
        REP(i, R) {
            REP (j, C) {
                count[store[i][j] - 'A'] += (LL) (i+1) * (R - (i)) * (j+1) * (C - (j));
            }
        }
        vector<LL> res;
        REP(i, MAX_CHARS) res.push_back(count[i]);
		return res;
	}
};

