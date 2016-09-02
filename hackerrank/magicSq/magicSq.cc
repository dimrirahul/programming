#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isMagic(vector<int>& v) {
    vector<int> r, c, d;
    bool inited = false;
    int currs = 0;
    for (int i = 0; i < 3; i++) {
        int cs = v[i] + v[i + 3] + v[i+ 6];
        if (!inited) {
            inited =  true;
            currs = cs;
        }
        int rid = i * 3;
        int rs = v[rid] + v[rid + 1] + v[rid + 2];
        c.push_back(cs);
        r.push_back(rs);
        if (rs != currs || cs != currs) return false;
    }
    int d1 = v[0] + v[4] + v[8];
    int d2 = v[2] + v[4] + v[6];
    if (d1 != currs || d2 != currs) return false;
    for (int i = 0; i < 3; i++) {
        if (r[i] != currs || c[i] != currs) return false;
    }
    return true;
}

int getCost(vector<int>& v1, vector<int>& v2) {
    int s = 0;
    for (int i = 0; i < v1.size(); i++) {
        s += abs(v1[i] - v2[i]);
    }
    return s;
}

int main() {
    vector<int> orig;
    vector<int> perms;
    for (int i = 1; i < 10; i++) {
        int t;
        cin >> t;
        orig.push_back(t);
        perms.push_back(i);
    }

    int res = 9*3;
    do {
        if (isMagic(perms))
            res = min(getCost(orig, perms), res);

    } while (next_permutation(perms.begin(), perms.end()));
    cout << res << "\n";

    return 0;

}
