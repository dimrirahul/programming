#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using VI = vector<int>;

const bool dbg = !true;
bool isDone(const VI& vi, int x) {
    for (auto it : vi) {
        if (it != x) return false;
    }
    return true;
}

void extend(VI& curr, int y) {
    sort(curr.begin(), curr.end());
    int x = curr[1] + curr[2] -1;
    x = (x > y) ? y : x;
    curr[0] = x;
}

int main() {
    int x, y;
    cin >> x >> y;
    int res = 0;
    VI curr;
    curr.push_back(y);
    curr.push_back(y);
    curr.push_back(y);
    while (!isDone(curr, x)) {
        res++;
        extend(curr, x);
        if (dbg) cout << "After cut= " << res << " values are (" << curr[0] << "," << curr[1] << "," << curr[2] << ")\n";
    }
    cout << res << "\n";
    return 0;
};
