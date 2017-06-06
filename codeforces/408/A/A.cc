#include <iostream>
#include <vector>

using namespace std;
const bool dbg = !true;
int main(int argc, char **Argv) {
    vector<int> c;
    int m, n, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        c.push_back(t);
    }
    int res = c.size();
    m--;
    int r = -1;
    for (int i = m+1; i < n; i++) {
        if (c[i] != 0 && c[i] <= k) {
            r = i;
            break;
        }
    }

    int l = -1;
    for (int i = m-1 ; i >= 0; i--) {
        if (c[i] != 0 && c[i] <= k) {
            l = i;
            break;
        }
    }

    if (dbg) {
        cout << "right = " << r << " left = " << l << "\n";
    }

    if ( r != -1) {
        res = min(res, abs(r - m));
    }
    if (dbg) {
        cout << "res= " << res << "\n";
    }

    if ( l != -1) {
        res = min(res,abs(l - m));
    }
    if (dbg) {
        cout << "res= " << res << "\n";
    }

    cout << res * 10 << "\n";
    return 0;
}
