#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
vector<int> ap {1, 2, 4, 6, 12, 24, 36, 48, 60, 120, 180, 240, 360, 720, 840, 1260, 1680, 2520, 5040, 7560, 10080, 15120, 20160, 25200, 27720, 45360, 50400, 55440, 83160, 110880, 166320, 221760, 277200, 332640, 498960, 554400, 665280, 720720, 1081080, 1441440, 2162160, 2882880, 3603600, 4324320, 6486480, 7207200, 8648640, 10810800, 14414400};

int main() {
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        auto it = lower_bound(ap.begin(), ap.end(), t);
        cout << *it << "\n";
    }
    return 0;
}
