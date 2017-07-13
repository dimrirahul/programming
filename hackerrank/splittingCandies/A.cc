#include <iostream>
#include <vector>
#include <array>

using namespace std;
using VI = vector<int>;
using LL = long long;
const bool dbg = true;

int main() {
    int n;
    cin >> n;
    VI v;
    VI score;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        v.push_back(t);
    }
    LL res = 1, prevCost = 1, currCost;
    if (dbg) score.push_back(1);
    for (int i = 1; i < n; i++) {
        if (v[i] == v[i-1]) currCost = 1;
        else if (v[i] > v[i-1]) {
            currCost = prevCost + 1;
        } else {
            if (prevCost == 1) {
                res += i;
                if (dbg) {
                    for (auto &it : score) it++;
                }
            }
            currCost = 1;
        }
        if (dbg) score.push_back(currCost);
        res += currCost;
        prevCost = currCost;
    }
    cout << res << "\n";
    if (dbg) {
        cout << "Score: \n";
        for (auto it = score.begin(); it != score.end(); ++it) {
            if (it != score.begin()) cout << ",";
            cout << *it;
        }
    }
    return 0;
};
