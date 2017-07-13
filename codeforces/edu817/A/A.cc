#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <set>


using namespace std;
using PI = pair<int, int>;
const int MX_VAL = (int)1e5;

bool isInt(int s, int e, int d) {
    return (e - s) % d == 0;
}
int main() {
    int sx, sy, ex, ey, a, b;
    cin >> sx >> sy >> ex >> ey >> a >> b;
    bool res = isInt(sx, ex, a) && isInt(sy, ey, b);
    if (res) {
        int d1 = abs(ex - sx) / a;
        int d2 = abs(ey - sy) / b;

        res = ( d1 % 2 == d2 % 2);
    }
    cout << (res ? "YES" : "NO") << "\n";


    return 0;
}
