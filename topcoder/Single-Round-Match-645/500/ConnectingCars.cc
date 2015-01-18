
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

class ConnectingCars
{
public:
    vector<int> pos;
    vector<int> len;
    vector<int> cumPos;
    long long calcCost(int p) {
        long long res = 0;
        for (int i = 0; i < cumPos.size(); i++) {
            int costRightEdge = (p + cumPos[i] - pos[i]);
            res += abs(costRightEdge);
        }
        return res;
    }
	long long minimizeCost(vector <int> positions, vector <int> lengths)
	{
        vector<pair<int, int> > vp;
        for (int i = 0; i < positions.size(); i++) {
            vp.push_back(make_pair(positions[i], lengths[i]));
        }
        sort(ALL(vp));
        int cp = 0;
        int xSum = 0;
        int lenSum = 0;
        for (int i = 0; i < vp.size(); i++) {
            pos.push_back(vp[i].first);
            len.push_back(vp[i].second);
            xSum += vp[i].first;
            lenSum += vp[i].second;
        }
        int cm = xSum/pos.size();
        for (int i = 0; i < pos.size(); i++) {
            cumPos.push_back(cp);
            cp += len[i];
        }
		return min(calcCost(s), calcCost(e));
	}
};

