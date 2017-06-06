#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int c = 0;
    int d = 0;
    for (int i = 0; i < n; i++) {
        int w; cin >> w;
        int ceil = (w + k - 1)/k + c;
        d += ceil / 2;
        if (ceil % 2 == 1) c = 1;
        else c = 0;
    }
    if (c == 1) d++;
    cout << d << "\n";
    return 0;
}

