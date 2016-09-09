#include <iostream>

using namespace std;
int main() {
    int res = 0;
    int w = 0;
    int n, b, d;
    cin >> n >> b >> d;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a > b) continue;
        w += a;
        if (w > d) {
            res++;
            w = 0;
        }
    }
    cout << res << "\n";
}

