#include <iostream>

using namespace std;

using LL = long long;

void solve(LL n) {
    if (n < 3) {
        cout << -1 << "\n";
        return;
    }
    if (n % 2 == 0) {
        //n is even;
        LL m = n/2;
        LL o1 = m * m  - 1;
        LL o2 = m * m + 1;
        cout << o1 << " " << o2 << "\n";
    } else {
        LL o1 = (n + 1)/2;
        LL o2 = (n - 1)/2;
        cout << 2 * o1 * o2 << " " << o1 * o1 + o2 * o2 << "\n";
    }
}
int main() {
    LL n;
    cin >> n;
    solve(n);
    return 0;
}
