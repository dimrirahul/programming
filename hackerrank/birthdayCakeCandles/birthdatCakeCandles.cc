#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
int solve(vector<int>& candles) {
    int res = 0, max = 0;
    for (auto& it : candles) {
        if (it >= max) {
            res++;
            max = it;
        }
    }
    return res;
}
*/

int solve(vector<int>& candles) {
    map<int, int> mp;
    for (auto& it : candles) {
        auto it1 = mp.find(it);
        if (it1 == mp.end()) {
            mp.insert(make_pair(it, 1));
        } else {
            it1->second++;
        }
    }
    return mp.rbegin()->second;
}

int main() {
    int ne;
    vector<int> candles;
    cin >> ne;
    for (int i = 0; i < ne; i++) {
        int t; cin >> t;
        candles.push_back(t);
    }
    cout << solve(candles) << "\n";
    return 0;
}
