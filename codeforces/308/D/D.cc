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
    set<pair<PI, PI>> visited;
    VPI generateColinearPts(PI& a, PI& b) {
        VPI res;
        int dy = b.second - a.second;
        int dx = b.first - a.first;
        for (int i = -100; i <= 100; i++) {
            int t1 = dy * (i - a.first);
            if ((t1 % dx) != 0) continue;
            t1 /= dx;
            int y = t1 + a.second;
            if (abs(y) <= 100) res.push_back(i, y);
        }
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
        sort(ALL(pts));
        int res = 0;
        int sp = 0;
        for (int i = 0; i < pts.size(); i++) {
            for (int j = i+1; j < pts.size(); j++) {
                if (visited.count(make_pair(pts[i], pts[j])) > 0) continue;
                VPI clPts = generateColinearPts(pts[i], pts[j]);
                for (auto p: clPts) {
                    auto ptr = lower_bound(ALL(pts), p);
                    if (*ptr == p) {
                        sp++;
                        visited.insert(make_pair(p, pts[i]));
                        visited.insert(make_pair(pts[i], p));
                        visited.insert(make_pair(p, pts[j]));
                        visited.insert(make_pair(pts[j], p));
                    }
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
