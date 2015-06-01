
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define FORU(I,A,B) for(unsigned int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define REPU(I,N)   FORU(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

typedef pair <int, int> PI;
typedef vector <int> VI;
typedef vector <string> VS;

typedef long long LL;
const bool dbg = !true;
class C {
public:

    int x1, y1, x2, y2, s1, e1, s2, e2, p;

    int heightAfterOneSecond(int slope, int x, int c) {
        LL t = (((LL)x * slope) %p + c) %p;
        if (dbg) printf("%s, slope=%d, x=%d, c=%d, res=%llu\n", __func__, slope, x, c, t);
        return t;
    }

    int growthTime(int startH, int endH, int x, int y) {
        int res = 0;
        do {
            res++;
            startH = heightAfterOneSecond(x, startH, y);
            if (startH == endH) break;
        } while (res < p);
        res = (startH != endH) ? -1: res;
        if (dbg) printf("%s, endh=%d, x=%d, y=%d, res=%d\n", __func__, endH, x, y, res);
        return res;
    }

    int getHeightAfterTseconds(int startH, int x, int y, int t) {
        REP(i, t) {
            startH = heightAfterOneSecond(x, startH, y);
        }
        if (dbg) printf("%s, x=%d, y=%d, t=%d, res=%d\n", __func__, x, y, t, startH);
        return startH;
    }

    PI nestEqn(int origX, int origY, int nestFactor) {
        int nx = 1;
        int ny = 0;
        REP (i, nestFactor) {
            LL t = ((LL) nx * origX) % p;
            nx = (int)t;
            LL t2 = ((LL)ny * origX) %p;
            ny = ((int)t2 + origY) % p;
        }
        if (dbg) printf("%s, origX=%d, origY=%d, nestFactor=%d, res.first=%d, res.second=%d\n", __func__, origX, origY, nestFactor, nx, ny);
        return make_pair(nx, ny);
    }
    

    LL solve() {
        int t1 = growthTime(s1, e1, x1, y1);
        if (t1 < 0) return t1;
        int h2 = getHeightAfterTseconds(s2, x2, y2, t1);
        if (h2 == e2) return t1;
        int t3 = growthTime(e1, e1, x1, y1);
        if (t3 < 0) return t3;
        PI coeff = nestEqn(x2, y2, t3);
        int x3 = coeff.first;
        int y3 = coeff.second;
        LL res = t1;
        for (int i = 0; i < p; i++) {
            h2 = heightAfterOneSecond(x3, h2, y3);
            res += t3;
            if (h2 == e2) return res;
        }
        return -1;
    }

    void start() {
        cin >> p >> s1 >> e1 >> x1 >> y1 >> s2 >> e2 >> x2 >> y2;
        cout << solve() << "\n";
    }    
};

C t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
