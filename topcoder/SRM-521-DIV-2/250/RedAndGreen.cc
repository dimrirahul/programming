
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

class RedAndGreen
{
public:
    int minPaints(string row)
    {
        int res = 1000;
        int mid = row.size()/2;
        int numReds = 0;
        for (int j = 0; j <= row.size(); j++) {
            int count = 0;
            REP(i, row.size()) {
                if (i < j && row[i] == 'G') {
                    count++;
                }
                if ( i >= j && row[i] == 'R') {
                    count++;
                }
            }
            res = min(res, count);
        }
        return res;
    }
};

