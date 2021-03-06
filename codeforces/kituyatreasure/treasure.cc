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
            int res = solve(startJump, startJump);
            cout << res << "\n";
        }
        int getArrOffset(int p, int d) {
            return  d -startJump + 246;
        }
        int solve(int pos, int d) {
            if (pos >= MAX_SZ) return 0;
            int arrPos = getArrOffset(pos, d);
            if (arrPos >= MAX_WID) return 0;
            if (dp[pos][arrPos] != -1) return dp[pos][arrPos];
            int res = max(solve(pos + d, d) , solve(pos + d + 1, d+1));
            if (d > 1) {
                res = max(res, solve(pos + d - 1, d - 1));
            }
            res += gemsById[pos];
            dp[pos][arrPos] = res;
            return res;
        }
};

KituyaTreasure kt;
int main(int argc, char **argv) {
    kt.start();
    return 0;
}
