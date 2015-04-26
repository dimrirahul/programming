//#include<bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <queue>
#include <cstring>



#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

typedef pair <int, int> PI;
typedef vector <int> VI;
typedef vector <string> VS;

typedef long long LL;
const int SZ = 2000;


class foxAndDots {
    public:
        double dp[SZ][SZ];
        void start() {
            memset(dp, 0, sizeof(double) * SZ * SZ);
            int n, p1, t;
            cin >> n >> p1 >> t;
            double pass = (double)p1/100;
            double fail = (double)1 - pass;
            REP (i, t + 1) {
                dp[0][i] = 1;
                dp[i][0] = 1;
            }
            FOR (i, 1,  n + 1) {
                FOR (j, 1, t+1) {
                    dp[i][j] = pass * dp[i-1][j-1] + fail * dp[i][j-1];
                }
            }
        }    
};

foxAndDots t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
