#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <cstdio>
#include <algorithm>

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
class Piece {
    public:
        int s, e;;
        Piece(int _s, int _e) {
            s = _s;
            e = _e;
        }

        bool operator<(Piece other) const {
            if (getLen() != other.getLen()) return getLen() < other.getLen();
            return s < other.s;
        }

        int getLen() const { return e - s;}
};
typedef set<int> SI;
typedef set<Piece> SP;
class glassCarving {
public:
    SP xOrd, yOrd;
    SI xCuts, yCuts;

    void update(SP& sp, SI& si, int l) {
        si.insert(l);
        SI::const_iterator it = si.find(l);
        it--;
        int p1 = *it;
        it++; it++;
        int p2 = *it;
        SP::const_iterator it1 = sp.find(Piece(p1, p2));
        Piece p = *it1;
        sp.erase(it1);
        sp.insert(Piece(p.s, l));
        sp.insert(Piece(l, p.e));
    }
    void findOverlaps(int l, bool isVertical) {
        if (isVertical) {
            update(xOrd, xCuts, l);
        } else {
            update(yOrd, yCuts, l);
        }
    }
    void start() {
        int x1, y1, n;
        cin >> x1 >> y1 >> n;
        xCuts.insert(0);
        xCuts.insert(x1);
        yCuts.insert(0);
        yCuts.insert(y1);
        xOrd.insert(Piece(0, x1));
        yOrd.insert(Piece(0, y1));
        REP(i, n) {
            char t1;
            int t2;
            cin >> t1 >> t2;
            bool isVertical = (t1 == 'V');
            findOverlaps(t2, isVertical);
            SP::const_iterator it1 = xOrd.end();
            it1--;
            LL prod = it1->getLen();
            it1 = yOrd.end();
            it1--;
            prod *= it1->getLen();
            cout << prod << "\n";
        }
    }    
};

glassCarving t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
