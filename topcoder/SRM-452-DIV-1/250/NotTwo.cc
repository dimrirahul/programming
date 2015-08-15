
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

class NotTwo
{
    public:
        int m[1001][1001];
        
        void set(int x, int y, int val=1) {
            int &p = m[x][y];
            if (p == 0) p = val;
        }

        void placeShit(int r, int c, int row, int cols) {
            if (c+1 < cols) set(r, c+1);
            if (r+1 < row) set(r+1, c);
            if (r+1 < row && c+1 < cols) set(r+1, c+1);
        }

        void makeHoles(int r, int c, int row, int cols) {
            if (c+2 < cols) set(r, c+2, 2);
            if (r+2 < row) set(r+2, c, 2);
        }

        int maxStones(int cols, int row){
            int res = 0;
            REP(i, row) REP(j, cols) m[i][j] = 0;
            REP(i, row) {
                REP(j, cols) {
                    if (m[i][j] == 0) {
                        m[i][j] = 1;
                        placeShit(i, j, row, cols);
                        makeHoles(i, j, row, cols);
                    }
                    else if (m[i][j] == 1) makeHoles(i, j, row, cols);
                }
            }
            REP(i, row) REP(j, cols) if(m[i][j] == 1) res++;
            return res;
        }
};

