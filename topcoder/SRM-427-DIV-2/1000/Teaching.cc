
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
class Teaching
{
    public:
        int lm[SIZE];
        int res, numElements;
        void init(vector<string> w) {
            res = 0;
            REP(i, w.size()) {
                lm[i] = 0;
                REP(j, w[i].size()) {
                    lm[i] |= 1 << (25 - (w[i][j] - 'a'));
                }
                if (i != 0) {lm[i] &= ~lm[0];}
            }
        }

        void printMask(int mask) {
            REP(i, 26) {
                printf( (mask & (1 << (25-i))) ? "1":"0");
            }
            printf("\n");
        }
        void evaluate(int mask) {
            //printMask(mask);
            int t = 0;
            FOR(i, 1, numElements + 1) {
                //printMask(lm[i]);
                if((lm[i] &(~mask)) == 0) t++;
            }
            res = max(res, t);
        }

        void setBits(int s, int e, int b, int& mask) {
            //printf("s=%d, e=%d, b=%d\n", s, e, b);
            if ( s > e || (e - s) < b) return;
            else if (b == 0) { evaluate(mask); }
            else {
                FOR(i, s, e) {
                    char c = i + 'a';
                    if (c == 'a' || c == 'n' || c == 't' || c == 'i' || c== 'c') continue;
                    //printf("Solving for=%c\n", c);
                    mask |= 1 << (e - 1 - i);
                    setBits(i+1, e, b-1, mask);
                    mask &= ~(1 << (e -1 - i));
                }
            }
        }

        int count(vector <string> words, int K)
        {
            numElements = words.size();
            if (K < 5) return 0;
            words.insert(words.begin(), string("antic"));
            init(words);
            int mask = 0;
            setBits(0, 26, K-5, mask);
            return res;

        }
};
