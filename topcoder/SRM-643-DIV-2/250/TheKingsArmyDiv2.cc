
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

class TheKingsArmyDiv2
{
public:

    bool isHappy(vector<string>& s, int r, int c) {
        if ( r < 0 || r >= s.size() || c < 0 || c >= s[0].size()) return false;
        return s[r][c] == 'H';
    }
    bool hasHappyNeighbors(vector<string>& s, int r, int c) {
        return (isHappy(s, r-1, c) || isHappy(s, r+1, c) || isHappy(s, r, c+1) || isHappy(s, r, c-1));
    }
	int getNumber(vector <string> state)
	{
        int h = 0;
        REP (i, state.size()) {
            REP (j, state[i].size()) {
                if (state[i][j] == 'H') {
                    if (hasHappyNeighbors(state, i, j)) return 0;
                    h++;
                }
            }
        
        }
	    if (h == 0) return 2;
        else return 1;
	}
};

