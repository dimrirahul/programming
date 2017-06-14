#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;
#define FORN(I,N) for (int (I) = 0; (I) < (N); (I)++)
#define ALL(X) (X).begin(), (X).end()

using PL = pair<long, int>;
using VPL = vector<PL>;
using LL = long long;

const LL MAX_VAL = 1e16 + 10;

LL minV(const VPL& vpl, int idx) {
    for (int i = idx-1; i >= 0; i--) {
        if (vpl[i].second > vpl[idx].second)
            return vpl[idx].first - vpl[i].first;
    }
    return MAX_VAL;
}

int main() {
    int N; cin >> N;
    VPL vpl;
    FORN (i, N) {
        LL t; cin >> t;
        vpl.push_back(make_pair(t, i));
    }
    sort(ALL(vpl));
    LL res = MAX_VAL;
    for (int i = 1; i < N; i++) {
        res = min(res, minV(vpl, i));
    }
    cout << res << "\n";
    return 0;

}
