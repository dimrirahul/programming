#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const bool dbg = !true;
int main() {
    vector<int> v;
    int n, a;
    cin >> n >> a;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        int u = t-a;
        v.push_back(u);
    }

    sort(v.begin(), v.end());
    if (dbg) {
        for (auto it : v) cout << it << " ";
        cout << "\n";
    }

    auto itf = v.begin();
    auto itr = v.rbegin();
    auto itf1 = v.begin();
    itf1++;
    auto itr1 = v.rbegin();
    itr1++;
    int res = 0;
    if (v.size() > 1) {
        int v1  = min( abs(*itr1 - *itf) + abs(*itf),
                abs(*itr1 - *itf) + abs(*itr1)
                );


        int v2 = min( abs(*itr - *itf1) + abs(*itf1),
                abs(*itr - *itf1) + abs(*itr)
                );
        res = min(v1, v2);
        if (dbg) cout << "v1=" << v1 << "v2=" << v2 << "\n";
    }

    cout << res << "\n";
    return 0;

};
