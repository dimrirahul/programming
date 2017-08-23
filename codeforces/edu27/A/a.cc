#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using VI = vector<int>;

int main() {
    VI v;
    int t;
    cin >> t;
    t *= 2;
    for (int i = 0; i < t; i++) {
        int t1; cin >> t1;
        v.push_back(t1);
    }
    sort(v.begin(), v.end());
    cout << ((v[t/2 - 1] < v[t/2]) ? "YES" : "NO") << "\n";
    return 0;
}
