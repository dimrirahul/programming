
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

class MarbleDecoration
{
public:
	int maxLength(int R, int G, int B)
	{
		std::vector<int> v;
		v.push_back(R);
		v.push_back(G);
		v.push_back(B);
		sort(v.begin(), v.end());
		int max = v[2];
		int max1 = v[1];

		if( max1 == 0) {
			if (max > 0) {
				return 1;
			} else {
				return 0;
			}
		}

		if (max > max1) {
			return 2 * max1 + 1;
		} else {
			return 2 * max1;
		}
	}
};

