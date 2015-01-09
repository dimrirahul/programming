
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

class MagicalGirlLevelOneDivTwo
{
public:

	bool inRange(int x, int y, int d) {
		return (x <= d && y <=d);
	}
	double theMinDistance(int d, int x, int y)
	{
		x = abs(x);
		y = abs(y);
		if (inRange(x, y, d)) {
			return 0;
		}

		if ( x<=d) {
			return y-d;
		}

		if (y <= d) {
			return x-d;
		}

		return (sqrt((x-d) * (x-d) + (y-d) * (y-d)));
	}
};

