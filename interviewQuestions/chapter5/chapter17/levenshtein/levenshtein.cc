#include <bits/stdc++.h>

using namespace std;
const int SZ = 100;
const bool dbg = false;
class Levenshtein {
    public:
        int dp[SZ][SZ];
        void initDp() {
            for (int i = 0; i < SZ; i++) {
                for (int j = 0; j < SZ; j++) {
                    dp[i][j] = -1;
                }
            }
        }
        string s1, s2;
        int solve(int i, int j) {
            if (dbg) cout << "Solving for " << i << " " << j << "\n";
            if ( i < 0 || j < 0) return 0;
            if (dp[i][j] != -1) return dp[i][j];
            if (s1[i] == s2[j]) {
                dp[i][j] = solve(i-1, j-1);
            } else {
                dp[i][j] = min(min(solve(i-1, j), solve(i, j-1)), solve(i-1, j-1)) + 1;
            }
            return dp[i][j];
        }

        int findDistance(string _s1, string _s2) {
            initDp();
            s1 = _s1; s2 = _s2;
            return solve(s1.size(), s2.size());
        }
};
Levenshtein lv;
int main(int argc, char **argv) {
    string s1, s2;
    cin >> s1 >> s2;
    cout << "Distance = " << lv.findDistance(s1, s2) << "\n";
    return 0;
}
