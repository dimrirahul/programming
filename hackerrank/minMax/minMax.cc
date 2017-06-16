#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

using VI = vector<int>;
const bool dbg = !true;

int main() {
    int N, K;
    cin >> N >> K;
    VI inp;
    for (int i = 0; i < N; i++) {
        int t; cin >> t;
        inp.push_back(t);
    }
    K--;
    sort(inp.begin(), inp.end());
    if (dbg) {
        for_each(inp.begin(), inp.end(),[](const int& i) { cout << i << ",";});
        cout << "\n";
    }
    int res = inp[K] - inp[0];
    for (int pos = 0; pos + K < inp.size(); pos++) {
        if (dbg) cout << "pos=" << pos << " more=" << inp[pos + K] << " less=" << inp[pos] << " res before=" << res; 
        res = min(res, inp[pos + K] - inp[pos]);
        if (dbg) cout << " res After=" << res << "\n";
    }
    cout << res << "\n";
    return 0;
}
