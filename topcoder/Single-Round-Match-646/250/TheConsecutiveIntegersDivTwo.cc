
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

class TheConsecutiveIntegersDivTwo
{
public:
	int find(vector <int> numbers, int k)
	{
        if (k == 1) return 0;
        sort(ALL(numbers));
        int res = 2 * 10000000;
        for (int i = 0; i < numbers.size() - 1; i++) {
            int d = numbers[i + 1] - numbers[i];
            d--;
            res = min(res, d);
        }
		return res;
	}
};

