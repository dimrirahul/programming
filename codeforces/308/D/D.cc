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
        if (dx != 0) {
            for (int i = -100; i <= 100; i++) {
                int t1 = dy * (i - a.first);
                if ((t1 % dx) != 0) continue;
                t1 /= dx;
                int y = t1 + a.second;
                if (abs(y) <= 100) res.push_back(make_pair(i, y));
            }
        } else {
            for (int i = -100; i <= 100; i++) res.push_back(make_pair(a.first, i));
        }
        return res;
    }

    VPI filterColinerPts(VPI& sortedPts, VPI& input) {
        VPI res;
        for (auto& i: input) {
            auto iter = lower_bound(ALL(sortedPts), i);
            if (*iter == i) res.insert(end(res), i);
        }
        return res;
    }

    LL nC3(LL p) {
        return  (p * (p-1) * (p-2))/ 6;
    }

    void insertPairIntoVisitedMap(set<pair<PI, PI>>& s, const PI& p1, const PI& p2) {
        s.insert(make_pair(p1, p2));
        s.insert(make_pair(p2, p1));
    }

    void generatePairwisePts(VPI& pts, set<pair<PI, PI>>& s) {
        for (int i = 0; i < pts.size(); i++) {
            for (int j = i+1; j < pts.size(); j++) {
                insertPairIntoVisitedMap(s, pts[i], pts[j]);
            }
        }
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
        auto res = nC3(pts.size());
        for (int i = 0; i < pts.size(); i++) {
            for (int j = i+1; j < pts.size(); j++) {
                if (visited.count(make_pair(pts[i], pts[j])) > 0) continue;
                VPI clPts = generateColinearPts(pts[i], pts[j]);
                clPts = filterColinerPts(pts, clPts);
                generatePairwisePts(clPts, visited);
                res -= nC3(clPts.size());
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
