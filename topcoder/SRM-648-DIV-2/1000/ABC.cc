
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

typedef pair<int, int> PI;
class ABC
{
public:
    PI isPossible(int n, int k) {
        REP (i, n) {
            REP (j, n) {
                int r = n - (i+j);
                if (i *r + i * j + j * r >= k) {
                    return make_pair(i, j);
                }
            }
        }
        return make_pair(-1, -1);
    }

	string createString(int N, int K)
	{
		PI p = isPossible(N, K);
        if (p == make_pair(-1, -1)) return string();
        //printf("P=%d,%d\n", p.first, p.second);
        int aCnt, bCnt, cCnt;
        bCnt = p.first;
        cCnt = p.second;
        aCnt = N - (bCnt + cCnt);
        int aPos, bPos, cPos;
        aPos = 0;
        bPos = aPos + aCnt;
        cPos = bPos + bCnt;
        int excess = (aCnt * bCnt + bCnt * cCnt + aCnt * cCnt) - K;
        string s;
        REP (i, N) {
            if (i < aCnt) { s += 'A'; }
            else if (i < aCnt + bCnt) { s+= 'B'; }
            else { s += 'C'; }
        }
        while (excess > 0) {
            if (excess >= aCnt + bCnt) {
                swap(s[aPos], s[bPos]);
                swap(s[aPos], s[cPos]);
                aPos++;
                bPos++;
                cPos++;
                excess -= (aCnt + bCnt);
            } else if (excess >= aCnt) {
                swap(s[aPos], s[bPos]);
                aPos++;
                bPos++;
                excess -= (aCnt);
            } else {
                swap(s[bPos - excess], s[bPos]);
                excess = 0;
            }
        }
        return s;
	}
};

