#include<bits/stdc++.h>

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
class C {
public:

    int x1, y1, x2, y2, s1, e1, s2, e2, p;

    int heightAfterOneSecond(int slope, int x, int c) {
        int t = (x * slope) %p;
        t += c;
        return t % p;
    }
    int getTime(int startH, int endH, int x, int y) {
        int res = 0;
        do {
            res++;
            startH = heightAfterOneSecond(x, startH, y);
            if (startH == endH) return res;
        } while (res < p);
        return -1;
    }

    int getHeightAfterTseconds(int startH, int x, int y, int t) {
        REP(i, t) {
            startH = heightAfterOneSecond(startH, x, y);
        }
        return startH;
    }

    PI nestEq(int origX, int origY, int nestFactor) {
        int nX = 1;
        int nY = 0;
        REP (i, nestFactor) {
            nx = (nx * origX) % p;
            ny = ((ny * origX) % p + origY) % p;
        }
        return make_pair(nx, ny);
    }
    

    int solve() {
        int t1 = getTime(s1, e1, x1, y1);
        if (t1 < 0) return t1;
        int h2 = getHeightAfterTseconds(s2, x2, y2);
        if (h2 == e2) return t1;
        int t3 = getTime(e1, e1, x1, y1);
        if (t3 < 0) return t3;
        PI coeff = nestEq(x2, y2, t3);
        int x3 = coeff.first;
        int y3 = coeff.second;
        int res = t1;
        for (int i = 0; i < p; i++) {
            h2 = heightAfterOneSecond(x3, h2, y3);
            res += t3;
            if (h2 == e2) return res;
        }
        return -1;
    }

    void start() {
        cin << p << s1 << e1 << x1 << y1 << s2 << e2 << x2 << y2;
        cout << solve() << "\n";
    }    
};

C t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
