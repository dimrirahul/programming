#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <stdio.h>


#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

using PI = pair <int, int>;

const int SZ = 100;
typedef long long LL;
struct Rect {
    int x1, y1, x2, y2;
    Rect(int _x1, int _y1, int _x2, int _y2) {
        x1 = _x1; y1 =_y1; x2 = _x2; y2 = _y2;
    }

    bool contains(int x, int y) {
        return (x >= x1 && x <= x2 && y >= y1 && y <= y2);
    }
};

struct A {
    int matrix[SZ][SZ];
    void start() {
        memset(matrix, 0, sizeof(int) * SZ * SZ);
        int t; cin >> t;
        vector<Rect> rectV;
        REP(i, t) {
            int p, q, r, s;
            cin >> p >> q >> r >> s;
            rectV.push_back(Rect(q-1, p-1, s-1, r-1));
        }
        LL res = 0;
        REP(i, SZ) {
            REP(j, SZ) {
                REP(k, rectV.size()) {
                    if (rectV[k].contains(i, j)) matrix[i][j]++;
                }
            }
        }
        REP (i, SZ) REP (j, SZ) res += matrix[i][j];
        cout << res << "\n";
    }    
};

A t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
