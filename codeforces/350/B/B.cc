#include <iostream>
#include <vector>

using namespace std;
const bool dbg = !true;
using UL = unsigned long;
UL nC2(int p) {
    UL ret = p;
    ret *= (p + 1);
    return ret / 2;
}

int main(int argc, char **argv) {
    int n;
    UL k;
    vector<int> vi;
    cin >> n >> k;
    vi.reserve(n);
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        vi.push_back(t);
    }

    int pos = 1;
    for (; pos <= n + 2; pos++) {
        if (nC2(pos) > k) break;
    }

    pos--;
    UL newPos = k - nC2(pos);
    if (newPos > 0) {
        newPos--;
    } else {
        newPos = pos - 1;
    }

    if (dbg) {
        cout << "pos=" << pos << " k=" << k << " newPos=" << newPos << "\n";
    }

    cout << vi[newPos] << "\n";
    return 0;
}
