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
    LL solve(LL l1, LL r1, LL l2, LL r2, LL k) {
        if ( l2 >= r1 || r2 <= l1) return 0;
        LL l= max(l1, l2);
        LL r = min(r1, r2);
        LL res = r - l;
        if ( k >=l && k < r) res--;
        return res;
    }
    void start() {
        LL l1, r1, l2, r2, k;
        cin >> l1 >> r1 >> l2 >> r2 >> k;
        r1++; r2++;
        cout << solve(l1, r1, l2, r2, k) << "\n";
    }
};

A a;
int main() {
    a.start();
    return 0;
}
