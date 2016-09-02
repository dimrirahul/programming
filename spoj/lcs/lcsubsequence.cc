#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
//const int MX_SZ = 25000 + 10;
//const bool dbg = !true;
using PI = pair<int, int>;
map<PI, int> dp;

int getDp(int i, int j) {
    PI p = make_pair(i, j);
    auto it = dp.find(p);
    if (it == dp.end()) return 0;
    return it->second;
}

int setDp(int i, int j, int v) {
    PI p = make_pair(i, j);
    int res;
    auto it = dp.find(p);
    if (it == dp.end()) {
        res = v;
        if (v != 0) {
            dp.insert(make_pair(p, v));
        }
    } else {
        res = max(v, it->second);
        it->second = res;
    }
    return res;
}


int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int l1 = s1.size();
    int l2 = s2.size();
    //for (int i = 0; i < MX_SZ; i++) for (int j = 0; j < MX_SZ; j++) dp[i][j] = 0;
    int res = 0;
    for (int i = 0; i < l1; i++) {
        for (int j = 0; j < l2; j++) {
            int p1 = 0, p2 = 0, p3 = 0;
            if ( i > 0 && j > 0 && s1[i] == s2[j-1]) {
               p1 = setDp(i, j-1, getDp(i-1, j-1));
               res = max(res, p1);
            }
            if (i > 0 && j > 0 && s1[i-1] == s2[j]) {
                p2 = setDp(i-1, j, getDp(i-1, j-1));
                res = max(res, p2);
            }
            if (s1[i] == s2[j]) {
                p3 = setDp(i, j, getDp(i-1, j-1) + 1);
                res = max(res, p3);
            }
            /*
            if (dbg) cout << "dp[" << i << "][" << j << "]=" << dp[i][j] << "\n";
            if (dbg && i == 1 && j == 6) {
                cout << "dp prev = " << getDp(i-1, j-1) << " and curr= " << dp[i][j] << " i,j= " << i << " " <<  j << "\n";
                cout << "dp prev = " << dp[i-1][j-1] << " and curr= " << dp[i][j] << " i,j= " << i << " " <<  j << "\n";
            }
            if (dbg && i == 0 && j == 5) {
                cout << "dp prev = " << getDp(i-1, j-1) << " and curr= " << dp[i][j] << " i,j= " << i << " " <<  j << "\n";
            }
            */
        }
    }
    cout << res << "\n";
    return 0;
}
