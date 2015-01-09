
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

class ShoppingSurveyDiv2
{
public:
	int minValue(int N, vector <int> s)
	{
        if (s.size() == 1) {
            return s[0];
        }
        int i = 0;
        for (; i < N; i++) {
            sort(ALL(s));
            if (s[0] == 0) {
                return 0;
            }
            bool allEqual = true;
            for (int j = s.size() - 1; j > 0; j--) {
                if (s[j] != s[j-1]) {
                    allEqual = false;
                }
                s[j]--;
            } 

            if (allEqual && s[0] == N - i ) {
                return N - i;
            }
        }
		return 0;
	}
};

