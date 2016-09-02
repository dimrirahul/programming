#include <iostream>

using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    bool otherColors = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0 ; j < m; j++) {
            char c;
            cin >> c;
            if (c == 'B' || c == 'W' || c == 'G') continue;
            otherColors = true;
        }
    }
    cout << (otherColors ?"#Color" : "#Black&White") << "\n";
    return 0;
}

