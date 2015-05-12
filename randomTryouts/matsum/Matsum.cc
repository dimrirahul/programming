#include <iostream>

using namespace std;
const int SZ = 5;
int dp[SZ][SZ];
int out[SZ][SZ];

int getVal(int x, int y) {
    if (x < 0 || x == SZ || y < 0 || y == SZ) return 0;
    return out[x][y];
}
int main() {
    for (int i = 0; i < SZ; i++) {
        for (int j = 0; j < SZ; j++) {
            dp[i][j] = 1;
        }
    }
    for (int i = 0; i < SZ; i++) {
        for (int j = 0; j < SZ; j++) {
            out[i][j] = dp[i][j] + getVal(i-1, j) + getVal(i, j-1) - getVal(i-1, j-1);
        }
    }

    for (int i = 0; i < SZ; i++) {
        for (int j = 0; j < SZ; j++) {
            cout << out[i][j] << " ";
        }
        cout << "\n";
    }


}
