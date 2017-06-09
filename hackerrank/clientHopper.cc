#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;
using VI = vector<int>;
const bool dbg = false;

#define FORN(I, N) for (int (I) = 0; (I) < (N); (I)++)

int g(int x) {
    if (x % 2 == 0) return x/2;
    return x/2 + 1;
}

int solve(const VI& hv) {
    int ev = 0;
    for (auto it = hv.rbegin(); it != hv.rend(); it++) {
        if (dbg) cout << "Ev before=" << ev << " ev after=";
        ev = g(ev + *it);
        if (dbg) cout << ev << "\n";
    }
    return ev;
}

int main() {
    int numBuildings;
    VI heights;
    cin >> numBuildings;

    FORN (i, numBuildings) {
        int t1; cin >> t1;
        heights.push_back(t1);
    }

    cout << solve(heights) << "\n";
}
