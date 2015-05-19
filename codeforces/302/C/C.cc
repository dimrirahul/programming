#include<bits/stdc++.h>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define FORU(I,A,B) for(unsigned int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define REPU(I,N)   FORU(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

typedef pair <int, int> PI;
typedef vector <int> VI;
typedef vector <string> VS;

typedef long long LL;
const int SZ = 510;
const bool dbg = !true;
class C {
public:
    int dp[2][SZ][SZ];
    int n, m, b, md;
    VI bugsPerLine;

    void solve() {
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= b; k++) {
                    if (dbg) printf("i=%d, j=%d, k=%d\n", i, j, k);
                    LL res = dp[(i-1) % 2][j][k];
                    if (bugsPerLine[i-1] <= k && j > 0) {
                        res += dp[i%2][j-1][k - bugsPerLine[i-1]];
                        res %= md;
                    }
                    dp[i%2][j][k] = (int) res;
                    if (dbg) cout << "res = " << (int)res << "\n";
                }
            }
        }

    }

    void start() {
        memset(dp, 0, sizeof(int) * 2 * SZ * SZ);
        dp[0][0][0] = 1;
        cin >> n >> m >> b >> md;
        REP(i, n) {
            int t; cin >> t;
            bugsPerLine.push_back(t);
        }
        solve();
        LL res = 0; 
        for (int j = 0; j <= b; j++) {
            res += dp[n%2][m][j];
            res %= md;
        }
        cout << res << "\n";

    }    
};

C t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
