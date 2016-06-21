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

typedef long long LL;
struct A {

    void start() {
        VI a, b;
        int sa, sb, k, m;
        cin >> sa >> sb;
        cin >> k >> m;
        REP (i, sa) {
            int t;
            cin >> t;
            a.push_back(t);
        }
        REP (i, sb) { int t; cin >> t; b.push_back(t); }
        if (a[k-1] >= b[b.size() - m -1]) cout << "NO\n";
        else cout << "YES\n";
    }    
};

A t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
