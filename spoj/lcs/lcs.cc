#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MX_SZ = 250 + 10;
int dp[MX_SZ][MX_SZ];

int getDp(int i, int j) {
    if ( i < 0 || j < 0) return 0;
    return dp[i][j];
}


int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int l1 = s1.size();
    int l2 = s2.size();
    for (int i = 0; i < MX_SZ; i++) for (int j = 0; j < MX_SZ; j++) dp[i][j] = 0;
    int res = 0;
    for (int i = 1; i < l1; i++) {
        for (int j = 1; j < l2; j++) {
            int p1 = 0, p2 = 0, p3 = 0;
            if (s1[i] == s2[j-1]) {
               p1 = dp[i][j-1] = getDp(i-1, j-1);
               res = max(res, p1);
            }
            if (s1[i-1] == s2[j]) {
                p2 = dp[i-1][j] = getDp(i-1, j-1);
                res = max(res, p2);
            }
            if (s1[i] == s2[j]) {
                p3 = dp[i][j] = getDp(i-1, j-1);
                res = max(res, p3);
            }
        }
    }
    cout << res << "\n";
    return 0;
}
