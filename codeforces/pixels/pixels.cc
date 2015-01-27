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

typedef pair <int, int> PI;
typedef vector <int> VI;
typedef vector <string> VS;

typedef long long LL;
const int MAX_SZ = 1001;
class pixels {
public:
    bool isPainted[MAX_SZ][MAX_SZ];
    int n, m;
    bool check(int t1, int t2) {
        return ( ( t1 -1 >= 0 && t2-1 >= 0 &&  isPainted[t1-1][t2-1] && isPainted[t1-1][t2] && isPainted[t1][t2-1] )||
                (t1 +1 < n && t2 +1 < m && isPainted[t1][t2+1] && isPainted[t1+1][t2] && isPainted[t1+1][t2+1]) ||
                (t1 +1 < n && t2 - 1 >= 0 && isPainted[t1][t2-1] && isPainted[t1+1][t2-1] && isPainted[t1+1][t2]) ||
                (t1 - 1 >= 0 && t2 +1 < m && isPainted[t1-1][t2] && isPainted[t1-1][t2+1] && isPainted[t1][t2+1])
                );
         
    }
    void start() {
        REP(i, MAX_SZ) {
            REP(j, MAX_SZ) {
                isPainted[i][j] = false;
            }
        }
        int k;
        cin >> n >> m >> k;
        for (int i = 0; i < k; i++) {
            int t1, t2;
            cin >> t1 >> t2;
            isPainted[t1-1][t2-1] = true;
            if (check(t1-1, t2-1)) {
                cout << i + 1 << "\n ";
                return;
            }
        }
        cout << 0 << "\n";
    }    
};

pixels t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
