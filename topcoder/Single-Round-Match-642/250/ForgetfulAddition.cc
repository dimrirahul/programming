
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

class ForgetfulAddition
{
public:
	int minNumber(string expression)
	{
        int res = 999999999;
        for (int len = 1; len < expression.size(); len++) {
            string s1 = expression.substr(0, len);
            string s2 = expression.substr(len);
            int x = atoi(s1.c_str());
            int y = atoi(s2.c_str());
            res = min(res, x+y);
        }
		return res;
	}
};

