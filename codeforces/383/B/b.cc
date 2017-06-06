#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const bool dbg = !true;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> v;
    v.reserve(n);
    for (int i = 0; i < n; i++) {
        int t; cin >>  t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    long long res = 0;
    for (auto it : v) {
        int val = it ^ x;
        if (dbg) cout << "looking for val=" << val << " in the array value at pos=" << it <<  "\n";
        auto it1 = lower_bound(v.begin(), v.end(), val);
        if (it1 == v.end()) continue;
        auto it2 = upper_bound(v.begin(), v.end(), val);
        res += distance(it1, it2);
    }
    res /= 2;
    cout << res;
    return 0;
}
