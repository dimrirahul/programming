
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
    
    void populateSeq(int _a, int _x, int _y, int _m, int _n) {
        long long temp = _a;
        for (int i = 0; i < _n; i++) {
            seq.push_back((int) temp);
            temp *= _x;
            temp %= _m;
            temp += _y;
            temp %= _m;
        }
    }
    //n^3 solution which should not run.
    //1) Populate DP array i, j where i is the starting position and j is the length of the string.
    //2) Brute force for all strings begining with i and j of lenght k find result and update it.


    vector<int> bruteForce(int _a, int _x, int _y, int _m, int _n) {
        N = _n;
        int n = _n;
        for (int i = 0 ; i < n; i++) {
            for (int j = 1; i + j <= n; j++) {
                if (j == 1) {
                    dp[i][j] = seq[i];
                    continue;
                }
                dp[i][j] = dp[i][j-1] + seq[i+j];
            }
        }

        int mv = 1000000000; int mk = 0;
        for (int k = 1; k < n; k++) {
            for (int i = 0; i + k < n; i++) {
                for (int j = i + 1; j + k < n && i + k <= j; j++) {
                    int v = abs(dp[i][k] - dp[j][k]);
                    if (v < mv) {
                        mv = v;
                        mk = k;
                    } else if (v == mv && mk < k) {
                        mk = k;
                    } 
                }
            }
        }
        vector <int> res;
        res.push_back(mk);
        res.push_back(mv);
        return res;
    }

	vector <int> maxSubstring(int A0, int X, int Y, int M, int n) {
        populateSeq(A0, X, Y, M, N);
        return bruteForce(A0, X, Y, M, N);
	}
};

