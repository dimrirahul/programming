
// {{{ Boilerplate Code <--------------------------------------------------
// vim:filetype=cpp:foldmethod=marker:foldmarker={{{,}}}

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
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
#include <utility>
#include <vector>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

// }}}
const int SZ = 1000;
using VI = vector<int>;
typedef long long LL;
class OrderedNim
{
    public:
        /*
        int winner(vector<int>& layout, int pos) {
            if (pos == layout.size() -1) return 0;
            if (layout[pos] == 1) {
                return (winner(layout, ++pos) + 1) % 2;
            }
            return 0;
        }
        string winner(vector <int> layout) {
            return winner(layout, 0) == 0 ? string("Alice") : string("Bob");
        }
        */
        int f(vector<int>& l, int pos) {
            if (pos == l.size() - 1) return 1;
            int prev = f(l, pos + 1);
            if (l[pos] == 1) return (prev + 1) % 2;
            else {
                if (prev == 1) return 1; //pick one stone.
                if (prev == 0) return 1; //pick both stones.
            }
        }
        string winner(vector <int> layout) {
            for (auto i: layout) {}
            if (f(layout, 0) == 1) return string("Alice");
            else return string("Bob");
        }
};
