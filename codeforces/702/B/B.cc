#include <map>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <iostream>

using namespace std;

using VI = vector<int>;
using MI = map<int, VI>;

const bool dbg = !true;
int main() {
    VI pow2;
    MI entries;
    long long res = 0;
    for (int i = 0; i < 31; i++) pow2.push_back(1 << i);
    int n; cin >> n;
    for (int i = 0; i < n;  i++) {
        int t; cin >> t;
        auto  it = entries.find(t);
        if (it == entries.end()) {
            VI v;
            v.push_back(i+1);
            entries.insert(make_pair(t, v));
        } else {
            it->second.push_back(i+1);
        }
    }
    for (auto& it: entries) sort(it.second.begin(), it.second.end());
    for (auto& it1 : entries) {
        for (auto& pow2iter : pow2) {
            int key = pow2iter - it1.first;
            if (key < 0) continue;
            if (dbg) cout << "Key=" << key << "\n";
            auto it3 = entries.find(key);
            if (it3 == entries.end()) continue;
            VI& v1 = it1.second;
            VI& v2 = it3->second;
            if (dbg) {
                cout << "v1 found this is the first\n";
                for (auto& it : v1) cout << it << " ";
                cout << "\nv2 found this is the second\n";
                for (auto& it : v2) cout << it << " ";
            }
            for (auto& it4 : v1) {
                auto it5 = upper_bound(v2.begin(), v2.end(), it4);
                res += distance(it5, v2.end());
            }
        }
    }
    cout << res << "\n";
    return 0;
}
