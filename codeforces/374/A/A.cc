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
        int n; cin >> n;
        VI res;
        int count = 0;
        for (int i = 0; i < n; i++) {
            char c;
            cin >> c;
            if (c == 'B') count++;
            else {
                if (count > 0) res.push_back(count);
                count = 0;
            }
        }
        if (count > 0) res.push_back(count);
        cout << res.size() << "\n";
        for (auto it : res) cout << it << " ";
    }
};

A a;
int main() {
    a.start();
    return 0;
}
