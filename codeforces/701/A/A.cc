#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
using PI = pair<int, int>;
using VPI = vector<pair<int, int>>;

struct Comp {
    bool operator() (const PI& f, const PI& s) const {
        return f.second < s.second;
    }
};

int main() {
    int n;
    VPI vpi;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        vpi.push_back(make_pair(i, t));
    }
    sort(vpi.begin(), vpi.end(), Comp());
    auto i1 = vpi.begin();
    auto i2 = vpi.rbegin();
    for (int i = 0; i < n/2; i++) {
        cout << i1->first << " " << i2->first << "\n";
        i1++;
        i2++;
    }

    return 0;
}
