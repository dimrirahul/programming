
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

class KnockoutTourney
{
public:
	int meetRival(int N, int you, int rival)
	{
        if ( N % 2 == 1 ) N++;
        if (you % 2 == 1) you++;
        if (rival % 2 == 1) rival++;
        if (you/2 == rival/2) {
            return 1;
        } else {
            return 1 + meetRival(N/2, you/2, rival/2);
        }
	}

};

