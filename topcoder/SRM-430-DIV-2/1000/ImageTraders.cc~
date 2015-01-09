
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

const int SZ = 15;
class ImageTraders
{
public:

    vector <string> cost;
    map < pair<int, int>, int > dpMap;
    int getCost(int r, int c) { return cost[r][c] - '0'; }
    
    int getResult(int nodeId, int costPrice, int visited) {
        if (costPrice == 9) return 1;
        visited |= 1 << nodeId;
        int cpCopy = costPrice;
        cpCopy = cpCopy << 16;
        cpCopy |= visited;
        pair <int, int> nodeIdPricePair = make_pair(nodeId, cpCopy);
        if (dpMap.count(nodeIdPricePair) != 0) return dpMap[nodeIdPricePair];
        int res = 0;
        REP (i, cost.size()) {
            if ( visited & (1 << i) || getCost(nodeId, i) < costPrice ) continue;
            res = max(res, getResult(i, getCost(nodeId, i), visited));
        }
        res++;
        dpMap[nodeIdPricePair] = res;

        return res;
    }

	int maxOwners(vector <string> price)
	{
        cost.insert(cost.begin(), ALL(price));
		return getResult(0, 0, 0);
	}
};

