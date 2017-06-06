#include <iostream>

using namespace std;
const bool dbg = !true;
int ret(int p, int q) {
    int r = p * q;
    return r % 10;
}

int getQuickest(int n, int p) {
    if (dbg) cout << "Calling for n=" << n << " p=" << p << "\n";
    int res = n;
    if (p == 1) return res;
    if (p == 0) return 1;
    int pw = 1;
    while ((2 * pw) < p) {
        res = ret(res, res);
        pw *= 2;
    }
    //pw /= 2;
    if (pw < p) {
        return ret(res, getQuickest(n, p - pw));
    }
    return res;

}

int main() {
    int n; cin >> n;
    cout << getQuickest(8, n);
    return 0;
}

