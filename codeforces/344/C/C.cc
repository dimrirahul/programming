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
struct Element {
    int _l;
    int _t;
    Element(int l, int t) : _l(l), _t(t) {}
    Element() : _l(-1), _t(-1) {};
    bool shouldTryToPush(const Element& other) {
        if (other._t != _t) return true;
        if (other._l > _l) return true;
        return false;
    }
};

struct C {
    vector<Element> _elements;
    vector<int> _values;
    int _n;
    int _m;

    size_t binsearch(size_t beg, size_t end, const Element& e) {
        while (beg < end) {
            int mid = (beg + end) / 2;
            if (_elements[mid]._l > e._l) {
                beg = mid;
            } else {
                end = mid;
            }
        }
        return beg;
    }

    void start() {
        cin >> _n >> _m;
        REP(i, _n) {
            int t; cin >> t;
            _values.push_back(t);
        }
        REP(i, _m) {
            int t1, t2;
            cin >> t1 >> t2;
            Element e(t1, t2);
            if (_elements.empty()) _elements.push_back(e);
            else {
                vector<Element>::const_iterator it = _elements.back();
                if (!it->shouldTryToPush(e)) continue;

            }

        }
    }    
};

C t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
