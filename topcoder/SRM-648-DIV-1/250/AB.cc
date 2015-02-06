
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

class AB
{
public:
    int isPossible(int n, int k) {
        for (int i = 1; i < n; i++) {
            if ( i * (n - i) >= k ) return i;
        }
        return -1;
    }
	string createString(int N, int K)
	{
        int bCount = isPossible(N, K);
        if (bCount < 0) return string();
        int aCount = N - bCount;
        string s;
        REP (i, N) {
            if (i < aCount) s += 'A';
            else s += 'B';
        }
        int excess = ((N - bCount) * bCount) - K;
        int aPos = 0;
        while (excess > 0) {
            if (excess >= aCount) {
                swap(s[aPos], s[aCount + aPos]);
                aPos++;
                excess -= aCount;
            } else {
                swap(s[aCount + aPos], s[aCount + aPos - excess]);
                excess = 0;
            }
        }
		return s;
	}
};

