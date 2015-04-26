#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int SZ = 21;
class OilComp {
public:
    int dp[SZ][SZ];
    int input[SZ][SZ];
    int W, H;
    int solve(int x, int y, int dir) {
        if ( x < 0 || y < 0 || x >= H || y >= W ) return 0;
        if (dp[x][y] != -1) return dp[x][y];
        int ex = dp[x-1][y] + dp[x+1][y] + dp[x][y-1] + dp[x][y+1];
        int inc = input[x][y];
        if (dir == 1) {
            inc += solve(x-1, y+1, 2) + solve(x+1, y-1, 4) + solve(x+1, y+1, 1); 
        } if (dir == 2) {
            inc += solve(x-1, y-1, 3) + solve(x+1, y-1, 2) + solve(x+1, y+1, 1); 
        } if (dir == 3) {
            inc += solve(x-1, y-1, 3) + solve(x+1, y-1, 2) + solve(x+1, y-1, 4); 
        } else {
            inc += solve(x-1, y-1, 3) + solve(x+1, y-1, 4) + solve(x+1, y+1, 1); 
        }
        dp[x][y] = max (inc, ex);
        return dp[x][y];
    }
    void start(int tc) {
        for (int i = 0; i < SZ; i++) {
            for (int j = 0; j < SZ; j++) {
                dp[i][j] = -1;
                input[i][j] = 0;
            }
        }
        cin >> W >> H;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> input[i][j];
            }
        }
        int res = 0;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (dp[i][j] == -1) {
                    solve(i, j, 1);
                }
                res = max(res, dp[i][j])
            }
        }
        cout << "Case " << tc << ": " << res << "\n";

    }
};

int main() {
    int t; cin >> t;
    for (int i = 0; i < t; i++) oilComp.start(i+1);
    return 0;
}
