
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

const int SZ = 3001;
class KSubstring
{
public:
    int N;
    vector <int> seq;
    int dp[SZ][SZ];

    void populateSeq(int a, int x, int y, int m) {
        int curr = 0;
        REP (i, N) {
            if (i == 0) {
                curr = a;
            } else {
                long long u = curr;
                u *= x;
                u %= m;
                u += y;
                u %= m;
                curr = (int)u;
            }
            seq.push_back(curr);
        }
    }

    void populateDp() {
        REP (i, N) {
            for (int j = 0; i + j < N; j++) {
                if (j == 0) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i][j-1];
                }
                dp[i][j] += seq[i + j];
            }
        }
    }

    vector<int> findResult() {
        int minV = 1000000000;
        int maxK = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i+1; j < N; j++) {
                for (int k = 0; i + k < j && j + k < N; k++) {
                    int v = abs(dp[i][k] - dp[j][k]);
                    if (v < minV) {
                        minV = v;
                        maxK = k;
                    } else if (v == minV && maxK < k) {
                        maxK = k;
                    } 
                }
            }
        }
        vector <int> res;
        res.push_back(maxK + 1);
        res.push_back(minV);
        return res;
    }
	vector <int> maxSubstring(int A0, int X, int Y, int M, int n)
	{
        N = n;
        populateSeq(A0, X, Y, M);
        populateDp();
        return findResult();
	}
};

