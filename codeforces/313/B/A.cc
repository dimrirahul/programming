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
struct Pict {
    int l, w;
    Pict(int _l, int _w): l(_l), w(_w) { 
    }
    bool canFit(const Pict& o1, const Pict& o2) const {
        return ((o1.w + o2.w <= w) && (l >= max(o1.l, o2.l)));
    }
    Pict flip() const {
        return Pict(w, l);
    }
};

struct A {

    bool testConfig(const Pict& board, const Pict& p1, const Pict& p2) {
        bool r1 = board.canFit(p1, p2);
        bool r2 = board.canFit(p1, p2.flip());
        bool r3 = board.canFit(p1.flip(), p2);
        bool r4 = board.canFit(p1.flip(), p2.flip());
        return r1 || r2 || r3 || r4;
    }


    bool canFit(const Pict& board, const Pict& p1, const Pict& p2) {
        bool r1 = testConfig(board, p1, p2);
        bool r2 = testConfig(board.flip(), p1, p2);
        return r1 || r2;
    }

    void start() {
        int t1, t2;
        cin >> t1 >> t2;
        Pict b1(t1, t2);
        cin >> t1 >> t2;
        Pict x1(t1, t2);
        cin >> t1 >> t2;
        Pict y1(t1, t2);
        if (canFit(b1, x1, y1)) cout << "YES\n";
        else cout << "NO\n";
    }    
};

A t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
