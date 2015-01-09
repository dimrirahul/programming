
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

class LinearPolyominoCovering
{
public:
	string findCovering(string region)
	{
        string res("");
        string impossible("impossible");
        int pos = 0;
        while (pos < region.size()) {
            if (region[pos] == '.') { res += '.'; pos++;}
            else {
                int len = 0;
                while (region[pos + len] == 'X') len++;
                if (len % 2 == 1) return impossible;
                int aCount = len / 4;
                int bCount = len % 4;
                bCount /= 2;
                REP(i, aCount) { res += "AAAA";}
                REP(i, bCount) { res += "BB"; }
                pos += len;
            }
        }
		return res;
	}
};

