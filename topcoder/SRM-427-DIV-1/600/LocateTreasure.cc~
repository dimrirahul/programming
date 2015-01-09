
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
class LocateTreasure
{
    public:
        int dig(int d) {
            return d%9 == 0? 9: d%9;
        }
        string location(int K, int multi)
        {
            if(K > 12) {
                K %= 12;
                if (K < 2) { K += 12; }
            }

            int x = 0, y = 0;
            int X[] = {0, 1, 0, -1};
            int Y[] = {1, 0, -1, 0};
            int d = 1;
            REP(i, K) {
                x += X[i%4] * d;
                y += Y[i%4] * d;
                d = dig(d*multi);
            }
            char buf[100];
            sprintf(buf, "%d %d", x, y);
            string s(buf);
            return s;
        }
};

