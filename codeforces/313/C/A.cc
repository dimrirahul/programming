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
using VPI = vector<PI>;

const bool dbg = !true;
typedef long long LL;

struct A {

    void start() {
        set<int> s;
        REP(i, 6) {
            int t; cin >> t; 
            s.insert(t);
        }
        if (s.size() > 2) {
            cout << -1 << "\n";
            return;
        }
        VI v;
        v.insert(v.end(), ALL(s));
        LL res = 0, l1, l2;
        if (s.size() == 1) {
            l1 = l2 = v[0];
        } else {
            l1 = v[0];
            l2 = v[1];
        }
        res = (4 * l1 * l2) + (l1 * l1) + (l2 * l2);
        cout << res << "\n";
    }    
};

A t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
