
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

class GameOfStones
{
public:
	int count(vector <int> stones)
	{
        if (stones.size() == 1) return 0;
        int sum = 0;
        REP(i, stones.size()) { sum += stones[i]; }
        if (sum % stones.size() != 0) return -1;
        int ss = sum / stones.size();
        int moves = 0;
        REP(i, stones.size()) {
            int diff = abs(ss - stones[i]);
            if (diff % 2 != 0) return -1;
            moves += (diff/2);
        }
        return moves/2;
	}
};

