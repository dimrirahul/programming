#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <array>

using namespace std;
using VI = vector<int>;
using LL = long long;
using PI = pair<int, int>;
using MI = map<int, int>;


const int MAX_SZ = 25;

const bool dbg = !true;
struct A {

    void readInput() {
        cin >> r >> c;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }
    }

    int getPos(int rowNum, int calledByPos) {
        for (int i = 0; i < c; i++) {
            if (sameElementCols[i] || matrix[rowNum][i] == i +1 || i == calledByPos) continue;
            return i;
        }
        return -1;
    }
    void processRow(int rowNum) {
        bool swappedOnce = false;
        for ( int i = 0; i < c && !swappedOnce; i++) {
            if (sameElementCols[i]) {
                if (dbg) cout << "Continuing because sameElementCols at index = " << i << " is true\n";
                continue;
            } else {
                if (dbg) cout << "NOT Continuing because sameElementCols at index = " << i << " is false\n";
            }
            if (matrix[rowNum][i] != i + 1) {
                int p1 = getPos(rowNum, i);
                if (dbg) cout << "Trying to swap with position=" << p1 << "\n";
                if ( p1 == -1 ) {
                    if (dbg) cout << "Things fucked up";
                    continue;
                }
                int t = matrix[rowNum][p1];
                matrix[rowNum][p1] = matrix[rowNum][i];
                matrix[rowNum][i] = t;
                swappedOnce = true;
            }
        }
        if (dbg) {
            cout << "After processing row=" << rowNum << " it looks like\n";
            for (int i = 0 ; i < c; i++) cout << matrix[rowNum][i] << ",";
            cout << "\n";
        }
    }
    void processRows() {
        for (int i = 0; i < r; i++) processRow(i);
    }

    bool isColSame(int col) {
        for (int i = 0; i < r; i++) {
            if (i == 0) continue;
            if (matrix[i][col] != matrix[i-1][col]) return false;
        }
        return true;
    }

    bool areColsSame() {
        for (int j = 0; j < c; j++) {
            if (!isColSame(j)) return false;
        }
        return true;
    }

    bool twoColsOutOfPlace() {
        int outOfPlace = 0;
        for (int i = 0; i < c; i++) {
            if (matrix[0][i] != i+1) outOfPlace++;
        }
        return (outOfPlace == 2 || outOfPlace == 0);
    }
    void populateSameElementCols() {
        sameElementCols.fill(false);
        if (r == 1) return;
        for (int j = 0; j < c; j++)
            sameElementCols[j] = isColSame(j);

        if (dbg) {
            for (int i = 0; i < c; i++) {
                cout << "sameElementCols = " << sameElementCols[i] << " for column= " << i << "\n";
            }
        }
    }

    void start() {
        readInput();
        populateSameElementCols();
        processRows();
        cout << ((areColsSame() && twoColsOutOfPlace()) ? "YES" : "NO") << "\n";
    }

    int matrix[MAX_SZ][MAX_SZ];
    int r, c;
    array <bool, MAX_SZ> sameElementCols;
};

A a;
int main() {
    a.start();
    return 0;
}
