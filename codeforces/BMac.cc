#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> rots;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        int v;
        if (i % 2 == 0) {
            v = i - t;
        } else {
            v = t - i;
        }
        if (v < 0) v+= n;
        rots.push_back(v);
    }
    bool possible = true;
    for (int i = 1; i < n; i++) {
        int d = rots[i] - rots[i-1];
        if (!(d == 0 || d == n )) {
            possible = false;
            break; 
        }
    }

    cout << ((possible) ? "Yes": "No") << "\n";
}
