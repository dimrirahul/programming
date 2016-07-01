#include <iostream>

using namespace std;
using LL = unsigned long long;
int main() {
    int n, m, less, more;
    cin >> n >> m;
    auto fn = [](LL p, int x) { return (p + x) / 5;};
    LL res = 0;
    res += fn(n, 0) * fn(m, 0);
    for (int i = 1; i < 5; i++)
        res += fn(n, i) * fn(m, 5-i);
    cout << res << "\n";
    return 0;
}
