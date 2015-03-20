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
class Piece {
    public:
        int x, y, w, h;
        Piece(int _x, int _y, int _w, int _h) {
            x = _x; y = _y; w = _w; h = _h;
        }
        Piece() { x = y = w = h = 0;}
        bool isOnLine(int line, bool isVertical) {
            if (isVertical) return line > x && line < w+x;
            else return line > y && line < y + h;
        }
        
        LL getArea() const { return (LL)w * h;}

        bool operator<(Piece other) const {
            if (getArea() != other.getArea()) return getArea() < other.getArea();
            if ( x != other.x) return x < other.x;
            return y < other.y;
        }

        pair<Piece, Piece> split(int l, bool isVertical) const {
            Piece p1, p2;
            if (isVertical) {
                p1.y = p2.y = y;
                p1.h = p2.h = h;
                p1.x = x;
                p1.w = l - x;
                p2.x = l;
                p2.w = w + x - l;
            } else {
                p1.x = p2.x = x;
                p1.w = p2.w = w;
                p1.y = y;
                p1.h = l - y;
                p2.y = l;
                p2.h = y + h - l;
            }
            if (0) {
                cout << "Piece ";
                print();
                cout << " got split into ";
                p1.print();
                p2.print();
                cout << "===\n";
                if (getArea() != p1.getArea() + p2.getArea()) {
                    cout << "Area calculation got fed\n";
                    print();
                    p1.print();
                    p2.print();
                    cout << "===\n";
                }
            }
            return make_pair(p1, p2);
        }

        void print() const {
            cout << "[" << x << "," << y << "," << w << "," << h << "," << getArea() << "]\n";
        }
            
};
typedef set<int> SI;
typedef set<Piece> SP;
class glassCarving {
public:
    set<Piece> v;
    SI xCuts, yCuts;
    SP findOverlaps(int l, bool isVertical) {
        SP res;
        if (isVertical) {
            xCuts.insert(l);
            SI::const_iterator it = xCuts.find(l);
            it--;
            int x1 = *it;
            it++; it++;
            int x2 = *it;
            int w = x2 - x1;
            SI::const_iterator it1 = yCuts.begin();
            int y1 = *it1;
            it1++;
            while(it1 != yCuts.end()) {
                int y2 = *it1;
                int h = y2 - y1;
                SP::const_iterator it2 = v.find(Piece(x1, y1, w, h));
                res.insert(*it2);
                y1 = y2;
                it1++;
            }
        } else {
            yCuts.insert(l);
            SI::const_iterator it = yCuts.find(l);
            it--;
            int y1 = *it;
            it++; it++;
            int y2 = *it;
            int h = y2 - y1;
            SI::const_iterator it1 = xCuts.begin();
            int x1 = *it1;
            it1++;
            while(it1 != xCuts.end()) {
                int x2 = *it1;
                int w = x2 - x1;
                SP::const_iterator it2 = v.find(Piece(x1, y1, w, h));
                res.insert(*it2);
                x1 = x2;
                it1++;
            }
        }
        return res;
    }
    void start() {
        int x1, y1, n;
        cin >> x1 >> y1 >> n;
        xCuts.insert(0);
        xCuts.insert(x1);
        yCuts.insert(0);
        yCuts.insert(y1);
        Piece maxP(0, 0, x1, y1);
        v.insert(maxP);
        REP(i, n) {
            char t1;
            int t2;
            cin >> t1 >> t2;
            bool isVertical = (t1 == 'V');
            SP overlap = findOverlaps(t2, isVertical);
            for (SP::const_iterator it = overlap.begin(); it != overlap.end(); it++) {
                /*
                cout << "Erasing ";
                it->print();
                */
                v.erase(*it);
            }
            for(SP::const_iterator it = overlap.begin(); it != overlap.end(); it++) {
                pair<Piece, Piece> p = it->split(t2, isVertical);
                v.insert(p.first);
                v.insert(p.second);
            }
            SP::const_iterator it1 = v.end();
            it1--;
            cout << it1->getArea() << "\n";
        }
    }    
};

glassCarving t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
