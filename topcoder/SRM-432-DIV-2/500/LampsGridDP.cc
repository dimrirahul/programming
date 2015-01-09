
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
typedef pair <int , int> PI;
const int SIZE = 50;
class LampsGrid
{
    public:
        vector<string> matrix;
        int R, C;
        map <PI, PI> dp; 

        PI countAllColsSet(int c) {
            PI res = make_pair(0, 0);
            REP(i, R) {
                bool allSet = true;
                for (int j = 0; j <= c; j++) {
                    if (matrix[i][j] - '0' == 0) {
                        allSet = false;
                        break;
                    }
                }

                if (allSet) {
                    if (i < SIZE/2) {
                        res.first |= 1 << i;
                    } else {
                        res.second |= 1 << (i - SIZE/2);
                    }
                }
            }
            printf("All Cols set for col=%d\n", c);
            printBitmap(res);
            return res;
        }

        PI convertToBitmap(int c) {
            PI res = make_pair(0, 0);
            REP (i, R) {
                if (matrix[i][c] - '0' == 1) {
                    if ( i < SIZE/2 ) res.first |= 1 << i;
                    else res.second |= 1 << (i - SIZE/2);
                }
            }
            return res;
        }

        PI flip(PI p) {
            p.first = ~p.first;
            p.second = ~p.second;
            return p;
        }

        int countBits(PI p) {
            int res = 0;
            REP (i, R) {
                if (p.first & (1 << i)) res++;
                if ( (SIZE/2 + i) < R && p.second & (1 << 1 << i)) res++;
            }
            printf("Count Bits\n");
            printBitmap(p);
            printf("count = %d\n", res);

            return res;
        }
        
        PI getAllSet() {
            PI res = make_pair(0, 0);
            REP (i, SIZE/2) {
                res.first |= 1 << i;
                res.second |= 1 << i;
            }
            return res;
        }

        void printBitmap(PI p) {
            for (int i = 30; i >= 0; i--) {
                printf("%d", (p.first & (1 << i)) ? 1:0);
            }
            printf("  ");
            for (int i = 30; i >= 0; i--) {
                printf("%d", (p.second & (1 << i)) ? 1:0);
            }
            printf("\n");
            
        }

        PI solve(int c, int l) {
            printf("Entering solve %d %d\n", c, l);
            PI res = make_pair(0, 0);
            PI p = make_pair(c, l);
            if (dp.count(p) > 0) return dp[p];
            if (l == 0) {
                res = countAllColsSet(c);
            } else {
                PI p1 = (c > 0) ? solve(c-1, l) : getAllSet();
                PI p2 = (c > 0) ? solve(c-1, l-1): getAllSet();
                PI me = convertToBitmap(c);
                PI meInverse = flip(me);
                printf("p1=");
                printBitmap(p1);
                printf("p2=");
                printBitmap(p2);
                printf("me=");
                printBitmap(me);
                printf("meInverse=");
                printBitmap(meInverse);
                PI resMe = make_pair(p1.first & me.first, p1.second & me.second);
                PI resMeInverse = make_pair(p2.first & meInverse.first, p2.second & meInverse.second);
                printf("resMe=");
                printBitmap(resMe);
                printf("resMeInverse=");
                printBitmap(resMeInverse);
                if (countBits(resMe) > countBits(resMeInverse)) res = resMe;
                else res = resMeInverse;
            }
            dp[p] = res;
            printf("Exiting solve %d %d\n", c, l);
            return res;
 
        }
        int mostLit(vector <string> initial, int K)
        {
            matrix.insert(matrix.end(), ALL(initial));
            R = initial.size();
            C = initial[0].size();
            return countBits(solve(C-1, K));
        }
};

