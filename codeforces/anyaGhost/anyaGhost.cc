#include<bits/stdc++.h>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

typedef pair <int, int> PI;
typedef vector <int> VI;
typedef vector <string> VS;

typedef long long LL;
const int SZ = 903;
class anyaGhost {
    public:
        int dp[SZ];
        bool isCandleLight[SZ];
        int M, T, R;
        void start() {
            memset(dp, 0, sizeof(int) *SZ);
            memset(isCandleLight, 0, sizeof(bool) * SZ);
            cin >> M >> T >> R;
            int res = solve();
            cout << res << "\n";
        }

        void lightCandle(int x) {
            isCandleLight[x] = true;
            REP(i, T) dp[i + x +1]++;
        }

        int solve() {
            if (R > T) return -1;
            int res = 0;
            REP (i, M) {
                int w;
                cin >> w;
                while (dp[w + 301]  < R) {
                    for (int i = 1; i <= T; i++) {
                        if (!isCandleLight[w + 301 - i]) {
                            lightCandle( w + 301 -i);
                            res++;
                            break;
                        }
                    }
                }
            }
            return res;
        }
};

anyaGhost t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
