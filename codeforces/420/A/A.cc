#include <bits/stdc++.h>


using namespace std;
const int MX_SZ = 51;

using VI = vector<int>;
struct A {
    int matrix[MX_SZ][MX_SZ];
    vector<int> sortedRow[MX_SZ];
    int N;

    bool check(int r, int c) {
        if (matrix[r][c] == 1) return true;
        for (int i = 0; i < N; i++) {
            if (i == r) continue;
            int d = matrix[r][c] - matrix[i][c];
            auto it = lower_bound(sortedRow[r].begin(), sortedRow[r].end(), d);
            if (it != sortedRow[r].end() && *it == d) return true;
        }
        return false;
    }
    bool goodLab() {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (!check(i, j)) return false;

        return true;
    }
    void start() {
        cin >> N;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> matrix[i][j];
                sortedRow[i].push_back(matrix[i][j]);
            }
        }
        for (int i = 0; i < N; i++)
            sort(sortedRow[i].begin(), sortedRow[i].end());

        cout << ( goodLab() ? "Yes" : "No") << "\n";
        
    }
};

A a;
int main() {
    a.start();
    return 0;
}
