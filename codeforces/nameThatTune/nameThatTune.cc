//#include<bits/stdc++.h>
#include <vector>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

typedef pair <int, int> PI;
typedef vector <int> VI;
typedef vector <string> VS;

typedef long long LL;
const int SZ = 5001;
class nameThatTune {
public:
    double dp[SZ][SZ];
    int N, T;
    vector <PI> vpi;
    double getProbability(int p, int s, int l, int t) {
        if (t < s) return 0;
        if (t >= s && t < s + l -1) {
            double p1 = (double)p / 100;
            return p1 * pow (1-p1, t - s);
        } else {
            return 1;
        }
    }
    void start() {
        memset(dp, 0, sizeof(int) * SZ * SZ);
        cin >> N >> T;
        REP (i, N) {
            int t1, t2;
            cin >> t1 >> t2;
            vpi.push_back(make_pair(t1, t2));
        }
        dp[0][0] = 1;
        REP (i, vpi.size()) {
            int p = vpi[i].first;
            int l = vpi[i].second;
            REP (j, T +1) {
                if (j < i + 1) continue;
                for (int k =1; k <= l; k++) {
                    //printf("i+1=%d, j=%d, k=%d\n", i +1, j, k);
                    double t2;
                    double prevP = (j-k >= 0) ? dp[i][j-k]: (double)0;
                    dp[i + 1][j] += prevP *(t2 = getProbability(p, j - k +1, l, j));
                    //cout << "dp[" << i+1 << "," << j << "] Probability part =  " << t2 << " net = " << dp[i+1][j] << "\n";
                }
            }
        }
        double sum = 0;
        REP (i, N+1) {
            sum += dp[i][T];
        }
        cout << sum << "\n";
    }    
    void printDp(int r = SZ, int c = SZ) {
        REP (i, r+1) {
            REP (j, c+1) {
                cout << dp[i][j] << "  ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
};

nameThatTune t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
