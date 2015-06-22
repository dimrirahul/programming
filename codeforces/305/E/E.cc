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
using VI = vector <int>;
using VS = vector <string>;
using LL = long long;
using VB = vector <bool>;

const int MAX_VAL = ((int) 5e5) + 10;
const int MAX_SZ = ((int) 2e2) + 10;
struct E {
    int numElements;
    int numQueries;
    VI inp;
    VB present;
    int table[MAX_SZ][MAX_SZ];
    

    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a%b);
    }

    void preprocess() {
        memset(table, 0, sizeof(int) * MAX_SZ * MAX_SZ);
        for (int i = 0; i < inp.size(); i++) {
            for (int j = i +1; j < inp.size(); j++) {
                if (table[i][j] != 0) continue;
                int t1 = gcd(inp[i], inp[j]);
                table[i][j] = table[j][i] = t1;
            }
        }
    }

    void process(int idx) {
        present[idx] = !present[idx];
        int res = 0;
        for (int j = 1; j < inp.size(); j++) {
            for (int i = 0; i < j; i++) {
                if (present[i] && present[j] && (table[i][j] == 1)) res++;
            }
        }
        cout << res << "\n";
    }


    void start() {
        cin >> numElements >> numQueries;
        REP(i, numElements) {
            int t; cin >> t;
            inp.insert(end(inp), t);
            present.insert(end(present), false);
        }
        
        preprocess();
        REP(i, numQueries) { 
            int t; cin >> t;
            process(t-1);
        }
    }    
};

E t;
int main(int argc, char **argv) {
    t.start();
    return 0;
}
