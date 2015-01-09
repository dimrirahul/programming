
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

const int SIZE = 51;
typedef pair< int, int> PI;
const int MAX_D = 1000000 * 50;
class TheTower
{
    public:
        int table[SIZE];
        void init() {
            REP(i, SIZE) table[i] =  MAX_D;
        }
        vector <int> count(vector <int> x, vector <int> y)
        {
            init();
            REP(i, x.size()) {
                REP(j, y.size()) {
                    vector<int> d;
                    REP(k, x.size()) {
                       d.push_back(abs(x[i] - x[k]) + abs(y[j] -y[k]));
                    }
                    sort(ALL(d));
                    int s = 0;
                    REP(k, x.size()) {
                        s += d[k];
                        table[k] = min(table[k], s);
                    }
                }
            }
            vector<int> out;
            REP(i, x.size()) {
                out.push_back(table[i]);
            }
            return out;
        }
};

