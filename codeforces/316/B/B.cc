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
struct B {

    int solve() {
        int n, m; 
        cin >> n >> m;
        if (n == 1) return 1;
        if (m == 1) return m+1;
        if (m == n) return m-1;
        int l = m - 1;
        int r = n - m;
        if (r > l) return m+1;
        return m - 1;
    }
    void start() {
        cout << solve() << "\n";
    }    
};

B t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
