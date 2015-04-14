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
class Quartet {
    public:
        int a, b, c, d;
        Quartet(int _a, int _b, int _c, int _d) {
            a = _a; b = _b; c = _c; d = _d;
        }
        Quartet() {
            a = b = c = d = -1;
        }

        bool operator <(Quartet o) const {
            if (a != o.a) return a < o.a;
            if (b != o.b) return b < o.b;
            if (c != o.c) return c < o.c;
            return d  < o.d;
        }
};

class coveredPath {
public:

    int v1, v2, d, t;
    map<Quartet, int> cache;

    int getDistance(int s1, int s2, int t) {
        //printf("Solving for s1=%d, s2=%d, t=%d\n", s1, s2, t);
        Quartet q(s1, s2, d, t);
        if ( t == 1) {
            if ( s2 != s1) return -1;
            return s2;
        }
        /*
        if ( t == 1) {
            if(abs(s2 - s1) > d) return -1;
            else return abs(s2 - s1);
        }
        */
        if (cache.count(q) > 0) return cache[q];
        int res = 0;
        for (int i = d; i >= -d; i--) {
            int dist = getDistance(s1 + i, s2, t -1);
            if (dist > 0) {
                res = max(res, s1 + dist);
            }
        }
        cache[q] = res;
        //printf("Res for s1=%d, s2=%d, t=%d =%d\n", s1, s2, t, res);
        return res;
    }

    void start() {
        cin >> v1 >> v2 >> t >> d;
        cout << getDistance(v1, v2, t);
    }    
};

coveredPath t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
