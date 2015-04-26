
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

class TaroJiroDividing
{
public:
    set<int> findSet(int a) {
        set<int> res;
        while ( a % 2 == 0) {
            res.insert(a);
            a /= 2;
        }
        res.insert(a);
        return res;
    }
	int getNumber(int A, int B)
	{
        set<int> s1 = findSet(A);
        set<int> s2 = findSet(B);
        int res = 0;
        for (set<int>::const_iterator it = s1.begin(); it != s1.end(); it++) {
            if (s2.count(*it)) res++;
        }
		return res;
	}
};

