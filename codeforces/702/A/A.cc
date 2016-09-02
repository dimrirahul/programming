#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using VI = vector<int>;

int main() {
    int prevVal = 0, prevCount = 0, res = 0, n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        int currCount = t > prevVal ? prevCount + 1 : 1;
        prevVal = t;
        prevCount = currCount;
        res = max(res, currCount);
    }
    cout << res << "\n";
    return 0;
}
