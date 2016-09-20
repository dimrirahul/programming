#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

using LL = long long;
using VI = vector<int>;
using VL = vector<LL>;
using PI = pair<int, int>;
using ML = map<PI, LL>;


const bool dbg = true;
ML cache;
VI input;
VL cumSum;

void init() {
    cache.clear();
    input.clear();
    cumSum.clear();
}

LL getSum(int b, int e) {
    return cumSum[e] - cumSum[b] + input[b];
}

bool validSplit(int s, int e, int p) {
    LL lhs = getSum(s, p);
    LL rhs = getSum(p + 1, e);
    if (dbg) cout << "s =" << s << " e=" << e << " p=" << p << " lhs=" << lhs << " rhs=" << rhs << "\n";
    return lhs == rhs;
}

void updateCache(PI p, int v) {
    auto it = cache.find(p);
    if (it != cache.end() && it->second < v) cache.erase(it);;
    cache.insert(make_pair(p, v));
}

int getOptValue(int beg, int end) {
    if (beg >= end) return 0;
    PI p = make_pair(beg, end);
    auto it = cache.find(p);
    if (it != cache.end()) return it->second;
    int res = 0;
    for (int i = beg; i < end; i++) {
        int partSum = 0;
        if (validSplit(beg, end, i)) {
            partSum = 1 + max(getOptValue(beg, i),  getOptValue(i+1, end));
            //partSum = 1 + getOptValue(beg, i) + getOptValue(i+1, end);
            if (dbg) cout << "beg=" << beg << " end=" << end << " split=" << i << " partSum=" << partSum << "\n";
        } else {
            updateCache(make_pair(beg, i), 0);
        }
        res = max(res, partSum);
    }
    updateCache(p, res);
    return res;
}

void solveTc() {
    LL sum = 0;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int t1; cin >> t1;
        sum += t1;
        input.push_back(t1);
        cumSum.push_back(sum);
    }
    cout << getOptValue(0, n-1) << "\n";
}

int main() {
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; i++) {
        init();
        solveTc();
    }
}
