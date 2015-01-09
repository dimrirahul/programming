
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

class MultiNumber
{
public:
	string check(int number)
	{
        char buffer[100];
        sprintf(buffer, "%d", number);
        int len = 0;
        while (buffer[len] <= '9' && buffer[len] >= '0') {
            len++;
        }
        if (len == 1) return "NO";
        bool matchFound = false;
        for (int i = 1; i < len; i++) {
            int left = 1;
            int right = 1;
            for (int j = 0; j < len; j++ ) {
                if (j < i) {
                    left *= (buffer[j] - '0');
                } else {
                    right *= (buffer[j] - '0');
                }
            }
            if (left == right) {
                matchFound = true;
                break;
            }
        }
		return (matchFound) ? "YES" : "NO";
	}
};

