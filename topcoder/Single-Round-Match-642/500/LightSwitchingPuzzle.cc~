
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

class LightSwitchingPuzzle
{
public:
    void flip(string &s, int pos) {
        for (int i = pos; i <= s.size(); i++) {
            if (i % pos == 0) {
                if (s[i-1] == 'Y') s[i-1] = 'N';
                else s[i-1] = 'Y';
            }
        }
    }
	int minFlips(string state)
	{ 
        int count  = 0;
        string s = state;
        for (int i = 1; i <= s.size(); i++) {
            if (s[i -1] == 'Y') {
                count++;
                flip(s, i);
            }
        }
		return count;
	}
};

