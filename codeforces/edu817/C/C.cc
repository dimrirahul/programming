#include <iostream>
#include <vector>

using namespace std;
using LL = long long;

LL getSum(LL d) {
    LL s = 0;
    while ( d > 0 ) {
        s += (d % 10);
        d /= 10;
    }
    return s;
}

bool isLarge(LL d, LL s) {
    return ( d - getSum(d) >= s );
}

LL doShit() {
    LL s, n;
    cin >> n >> s;
    LL lt = 0;
    LL pos = s + 1;
    for (; pos <= n; pos++) {
        if (!isLarge(pos, s))
            lt++;
        else
            break;
    }
    if (pos > n) return 0;
    return n - s -lt;
}

int main() {
    cout << doShit() << "\n";

    return 0;
}
