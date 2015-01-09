
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

typedef long long LL;
const int MAX_SIZE = 20;
class TwoLotteryGames
{
public:
    LL factArray[MAX_SIZE];
    void populateFactArray( int n ) {
        factArray[0] = 1;
        for(int i = 1; i <= n; i++) {
            factArray[i] = factArray[i-1] * i;
        }
    }

    LL nCr(int n, int r) {
        return factArray[n] / (factArray[r] * factArray[n-r]);
    }

    double getProbality(int n, int m, int p) {
        LL a = nCr(m, p);
        LL b = nCr(n-m, m-p);
        LL c = nCr(n, m);
        return (double) (a *b)/(double) c;
    }
	double getHigherChanceGame(int n, int m, int k)
	{
        populateFactArray(19);
        double result = 0;
        for (int i = k; i <= m; i++) {
            if (n-i >= m-i) {
                result += getProbality(n, m, i);
            }
        }
        return result;
	}
};
