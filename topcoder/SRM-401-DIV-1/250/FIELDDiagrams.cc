
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


const int MAX = 32;
typedef long long int LL;
LL g_arr[MAX][MAX];
class FIELDDiagrams
{
public:
    void fillArray() {
        REP(i, MAX) {
            REP(j, MAX) {
                g_arr[i][j] = 0;
            }
        }
    }

	long long countDiagrams(int fieldOrder)
	{
        REP(i, fieldOrder+1) {
            g_arr[fieldOrder][i] = 1;
        }
        for (int i = fieldOrder; i >=0; i--) {
            for (int j = 0; j <= min())
        }
        
	}
};

