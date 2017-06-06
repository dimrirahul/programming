#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int INF = -1;

int solve(set<int>& ignored, int b, int q, long long l) {
    bool ignoreZero = ignored.find(0) != ignored.end();
    bool ignoredStart = ignored.find(b) != ignored.end();
    bool ignoredNegativeB = ignored.find(b * -1) != ignored.end();
    int res = 0;

    if (abs(b) > l) return 0;

    if (b == 0) return ignoreZero ? 0 : INF;

    if (q == 0) {
        if (!ignoreZero) return INF;
        return (ignoredStart) ? 0: 1;
    }

    if (q == 1) {
        return ignoredStart ? 0 : INF;
    }

    if (q == -1) {
        if (ignoredStart && ignoredNegativeB) return 0;
        return INF;
    }

    long long p = b;
    while (abs(p) <= l) {
        if (ignored.find(p) == ignored.end()) res++;
        p *= q;
    }
    return res;

}

int main() {
    int b, q, l, m;
    cin >> b >> q >> l >> m;
    set<int> ignored;
    for (int i = 0; i < m; i++) {
        int t; cin >> t;
        ignored.insert(t);
    }
    int res = solve(ignored, b, q, l);
    if (res == INF) {
        cout << "inf\n";
    } else {
        cout << res << "\n";
    }
    return 0;

}
