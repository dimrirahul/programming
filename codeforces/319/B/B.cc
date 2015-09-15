#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
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
#include <string>
#include <utility>
#include <vector>
#include <stdio.h>


#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

using PI = pair <int, int>;
using VI = vector <int>;
using VS = vector <string>;

typedef long long LL;
const int MR = (int) ((1e6) + 3);
const int MC = (int) ((1e3) + 3);
const bool dbg = true;
struct B {
    int inp[MR];
    bool dp[MC][MC];

    bool test() {
        int n, m;
        cin >> n >> m;
        if (n > m) return true;
        REP(i, n+1) REP(j, m+1) dp[i][j] = false;
        REP(i, n) cin >> inp[i+1];
        for (int i = 1; i < (n + 1); i++) {
            int p1 = inp[i] % m;
            dp[i][p1] = true;
            if (p1 == 0) return true;
            for (int j = 0; j < m; j++) {
                int p2 = (inp[i+1] + j) % m;
                dp[i+1][p2] = dp[i+1][j] = dp[i][j];
                if (p2 == 0 && dp[i+1][p2]) return true;
            }
        }

        return false;
    }

    void start() {
        cout << (test() ? "YES" : "NO") << "\n";
    }    
};

B t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
