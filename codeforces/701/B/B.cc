#include <iostream>
#include <map>
#include <algorithm>
#include <set>

using namespace std;
using SI = set<int>;
using LL = long long;
int main() {
    int n, m;
    cin >> n >> m;
    LL totsq = 1;
    totsq *= n;
    totsq *= n;
    SI ar, ac;
    for (int i = 1; i <= n; i++) {
        ar.insert(i);
        ac.insert(i);
    }
    for (int i = 0; i < m; i++) {
        int r, c;
        cin >> r >> c;
        bool isOnRow = ar.count(r) == 0;
        bool isOnCols = ac.count(c) == 0;
        if (!isOnRow) {
            totsq -= ac.size();
            ar.erase(r);
        }
        if (!isOnCols) {
            totsq -= ar.size();
            ac.erase(c);
        }
        cout << totsq << " ";
    }
    return 0;
}
