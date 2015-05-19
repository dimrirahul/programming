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
const int SZ = 102;
const bool dbg = false;
class D {
public:
    double dp[SZ][SZ][SZ];
    int a, b, c;
    double s1, s2, s3;

    void solve(int R, int S, int P) {
        dp[R][S][P] = (double)1;
        for (int i = R; i >= 0; i--) {
            for (int j = S; j >= 0; j--) {
                for (int k = P; k >= 0; k--) {
                    if (i == 0 && j == 0) continue;
                    if (j == 0 && k == 0) continue;
                    if (i == 0 && k == 0) continue;
                    double den = dp[i][j][k]/( i * j + j * k + k * i);
                    if ( i > 0) dp[i-1][j][k] += ( den * k * i);
                    if ( j > 0) dp[i][j-1][k] += ( den * i * j);
                    if ( k > 0) dp[i][j][k-1] += ( den * j * k);
                }
            }
        }
    }

    void solve2(int R, int S, int P) {
        dp[R][S][P] = 1;
        for (int r = R; r >= 0; r--) {
            for (int s = S; s >= 0; s--) {
                for (int p  = P ; p >= 0; p--) {
                    if (r == 0 && s == 0) continue;
                    if (r == 0 && p == 0) continue;
                    if (s == 0 && p == 0) continue;
                    double cur = dp[r][s][p];
                    int waysR = r * s;
                    int waysS = s * p;
                    int waysP = p * r;
                    int totalWays = waysR + waysS + waysP;
                    if (r > 0) dp[r - 1][s][p] += cur * waysP / totalWays;
                    if (s > 0) dp[r][s - 1][p] += cur * waysR / totalWays;
                    if (p > 0) dp[r][s][p - 1] += cur * waysS / totalWays;
                }
            } 
        }
    }
    void printDp() {
        if (!dbg) return;
        cout << "\n================\n";
        REP(i, a+1) REP(j, b+1) REP(k, c+1) {
            if (dbg) {
                printf("[%d, %d, %d]", i, j, k);
                cout << dp[i][j][k]  << "\n";
            }
        }
    }

    void start() {
        cin >> a >> b >> c;
        s1 = s2 = s3 = 0;
        REP(i, a+1) REP(j, b+1) REP(k, c+1) dp[i][j][k] = 0;
        solve(a, b, c);
        if (dbg) printDp();
        FOR(i, 1, a+1) s1 += dp[i][0][0];
        FOR(i, 1, b+1) s2 += dp[0][i][0];
        FOR(i, 1, c+1) s3 += dp[0][0][i];
        cout << setprecision(12) << fixed;
        cout << s1 << " " << s2 << " " << s3 << "\n";
    }    
};

D t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
