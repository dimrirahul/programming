
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
const int MAX_DIFF = 100;
class DifferentStrings
{
    public:
        int getDifference(string s1, string s2, int sps2) {
            int diff = 0;
            if (s1.size() + sps2 > s2.size()) return MAX_DIFF;
            for (int i = 0; i < s1.size(); i++) {
                if (s1[i] != s2[sps2 + i]) {
                    diff++;
                }
            }
            return diff;
        }
        int minimize(string A, string B)
        {
            if (A.size() ==  B.size()) {
                return getDifference(A, B, 0);
            }

            int res = MAX_DIFF;
            for (int i = 0; i < B.size(); i++) {
                res = min(res, getDifference(A, B, i));
            }
            return res;
        }
};

