
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

class TravellingSalesmanEasy
{
public:
    vector<int> itemsByCity[101];
    int nextPos[101];
	int getMaxProfit(int M, vector <int> profit, vector <int> city, vector <int> visit)
	{
        REP(i, 101) {
            nextPos[i] = 0;
        }
        for (int i = 0; i < profit.size(); i++) {
            itemsByCity[city[i]].push_back(profit[i]);
        }
        for (int i = 0; i < 101; i++) {
            sort(ALL(itemsByCity[i]));
            reverse(ALL(itemsByCity[i]));
        }
        int res = 0;
        for (int i = 0; i < visit.size(); i++) {
            if (nextPos[visit[i]] >= itemsByCity[visit[i]].size()) continue;
            res += itemsByCity[visit[i]][nextPos[visit[i]]++];
        }

		return res;
	}
};

