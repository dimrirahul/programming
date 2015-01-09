
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

typedef unsigned long long UL;
const int SIZE = 201;
const int MAX_RANK = 1000000001;
class TheDictionary
{
    public:
        string find(int n, int m, int k) {
            int C[SIZE][SIZE];
            C[0][0] = 1;
            for (int i=1; i<=200; i++) {
                C[i][0] = 1;
                C[i][i] = 1;
                for (int j=1; j<i; j++)
                    C[i][j] = min(C[i-1][j] + C[i-1][j-1], 1000000001);
            }

            if (C[n+m][m] < k) return "";
            string s = "";
            int L = n + m;
            for (int i=0; i<L; i++) {
                if (n>0 && C[n+m-1][m] >= k) {
                    s += "a";
                    n--;
                } else {
                    s += "z";
                    k -= C[n+m-1][m];
                    m--;
                }
            }
            return s;
        }	
};

