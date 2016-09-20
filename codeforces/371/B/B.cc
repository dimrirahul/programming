#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;
using VI = vector<int>;
using LL = long long;
using PI = pair<int, int>;
using MI = map<int, int>;


struct A {
    void start() {
        MI m;
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            auto it = m.find(t);
            if (it == m.end()) m.insert(make_pair(t, 1));
            else it->second++;
        }
        bool res = false;
        if (m.size() > 3) {
            res = false;
        } else if (m.size() == 1) {
            res = true;
        } else if (m.size() == 2) {
            res = true;
        } else {
            vector<PI> vpi;
            for (auto it : m) vpi.push_back(it);
            if ( (vpi[1].first - vpi[0].first) == (vpi[2].first - vpi[1].first)) {
                res = true;
            }
        }

        cout << (res ? "YES" : "NO") << "\n";
    }
};

A a;
int main() {
    a.start();
    return 0;
}
