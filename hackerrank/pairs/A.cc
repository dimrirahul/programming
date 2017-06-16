#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

using LL = long long;
using SL = set<LL>;
using VL = vector<LL>;

int main() {
    LL N, K;
    cin >> N >> K;
    VL vl;
    SL sl;
    for (int i = 0; i < N; i++) {
        LL t;
        cin >> t;
        vl.push_back(t);
        sl.insert(t);
    }

    int res = 0;
    for_each(vl.begin(), vl.end(),
            [&res, sl, K] (const LL& v) {
                LL f = K + v;
                if (sl.count(f) > 0) res++;
            }
    );

    cout << res << "\n";
    return 0;
}
