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
struct D {

    const bool areColinear(PI& a, PI& b, PI& c) {
        bool res = (
                (a.first * (b.second - c.second) +
                 b.first * (c.second - a.second) +
                 c.first * (a.second - b.second)
                ) == 0);
        return res;
    }
    void start() {
        int t ; cin >> t;
        VPI pts;
        REP (i, t) {
            int t2, t3;
            cin >> t2 >> t3;
            pts.push_back(make_pair(t2, t3));
        }
        int res = 0;
        for (int i = 0; i < pts.size(); i++) {
            for (int j = i+1; j < pts.size(); j++) {
                for (int k = j+1; k < pts.size(); k++) {
                    if (!areColinear(pts[i], pts[j], pts[k])) res++;
                }
            }
        }
        cout << res << "\n";
    }    
};

D t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
