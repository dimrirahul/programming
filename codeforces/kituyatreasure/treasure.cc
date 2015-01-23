#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
const int MAX_SZ = 30002;
typedef pair<int, int> PI;
class KituyaTreasure {
    public:
        int dp[MAX_SZ][MAX_SZ];
        int gemsById[MAX_SZ];
        int countGems;

        void start() {
            memset(dp, 0, sizeof (dp[0][0]) * MAX_SZ);
            memset(gemsById, 0, sizeof(int) * MAX_SZ);
            int d;
            scanf("%d %d\n", &countGems, &d);
            for (int i = 0; i < countGems; i++) {
                int p;
                scanf("%d\n", &p);
                gemsById[p]++;
            }
            solve(d);
        }

        int getMax(int j, int p) {
            int res = 0;
            for (int i = p-1; i <= p+1; i++) {
                if (i <= 0 || i > MAX_SZ) continue;
                res = max(res, dp[j][i]);
            }
            return res;
        }
        void solve(int d) {
            dp[d][0] = gemsById[d];
            for (int i = d+1; i < MAX_SZ; i++) {
                for (int j = 0; j < i; j++) {
                    int p = (i - j);
                    int v = getMax(j, p);
                    dp[i][j] = v + gemsById[i];
                }
            }

            int res = 0;
            for (int i = 0; i < MAX_SZ; i++) {
                for (int j = 0; j < MAX_SZ; j++) {
                    res = max(res, dp[i][j]);
                }
            }

            cout << res << "\n";
        }
};

KituyaTreasure kt;
int main(int argc, char **argv) {
    kt.start();
    return 0;
}
