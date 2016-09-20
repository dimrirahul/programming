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


const bool dbg = !true;
struct A {
    void start() {
        vector<int> vi;
        int n, c;
        cin >> n >> c;
        for (int i = 0; i < n; i++) {
            int t; cin >> t;
            auto it = vi.rbegin();
            if (it != vi.rend() && t - *it > c) {
                if (dbg) cout << "Clearing \n";
                vi.clear();
            }
            if (dbg) cout << "Pushing back: " << t << "\n";
            vi.push_back(t);
        }
        cout << vi.size() << "\n";
    }
};

A a;
int main() {
    a.start();
    return 0;
}
