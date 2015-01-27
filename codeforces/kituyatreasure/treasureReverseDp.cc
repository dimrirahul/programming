#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
const int MAX_SZ = 30002;
const int MAX_WID = 500;
typedef pair<int, int> PI;
class KituyaTreasure {
    public:
        int dp[MAX_SZ][MAX_WID];
        int gemsById[MAX_SZ];
        int startJump;

        void start() {
            int countGems;
            memset(dp, -1, sizeof (dp[0][0]) * MAX_SZ * MAX_WID);
            memset(gemsById, 0, sizeof(int) * MAX_SZ);
            scanf("%d %d\n", &countGems, &startJump);
            for (int i = 0; i < countGems; i++) {
                int p;
                scanf("%d\n", &p);
                gemsById[p]++;
            }
            dp[startJump][getArrOffset(startJump)] = gemsById[startJump];
            int res = max(solve(), gemsById[startJump]);
            cout << res << "\n";
        }
        int getArrOffset(int d) {
            return  d -startJump + 246;
        }
        int getMax(int i, int j) {
            int res = -1;
            if ( i - j < 0 ) return res;
            for (int p = -1; p < 2; p++) {
                if ( j + p <= 0) continue;
                res = max(res, dp[i-j][getArrOffset(j+p)]);
            }
            return res;
        }
        int solve() {
            int res = 0;
            for (int i = startJump; i < MAX_SZ - 1; i++) {
                for (int j = startJump - 246; j < startJump + 246; j++) {
                    if ( j <= 0 || getArrOffset(j) >= 500) continue;
                    int t = getMax(i, j);
                    if ( t < 0 ) continue;
                    dp[i][getArrOffset(j)] = t + gemsById[i];
                    res = max(res, dp[i][getArrOffset(j)]);
                }
            }
            return res;
        }
};

KituyaTreasure kt;
int main(int argc, char **argv) {
    kt.start();
    return 0;
}
