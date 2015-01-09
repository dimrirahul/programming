
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

bool cmp (int a, int b) {
    return !(a < b);
}

class Jumping
{
public:
	string ableToGet(int x, int y, vector <int> jumpLengths)
	{
        sort(jumpLengths.begin(), jumpLengths.end(), cmp);
        int maxSum = jumpLengths[0];
        int minSum = jumpLengths[0];
        for (int i = 1; i < jumpLengths.size(); i++) {
            maxSum += jumpLengths[i];
            minSum -= jumpLengths[i];
        }
        int d =  x *x + y * y;
        if ( d <= (maxSum * maxSum)  && d >= (minSum * minSum)) {
            return "Able";
        } else {
            return "Not able";
        }
	}
};

