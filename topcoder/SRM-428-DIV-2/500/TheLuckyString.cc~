
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

class TheLuckyString
{
public:
    bool isLucky(string& s) {
        REP(i, s.size() -1) {if (s[i] == s[i+1]) return false;}
        return true;
    }
	int count(string s)
	{
        int count = 0;
        sort(ALL(s));
        do {
            if (isLucky(s)) count++;
        } while (next_permutation(ALL(s)));
		return count;
	}
};

