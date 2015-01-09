
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

class MountainRanges
{
public:
	int countPeaks(vector <int> heights)
	{
        int count = 0;
        if (heights.size() == 1) {
            return 1;
        }
        for (int i = 1; i <= heights.size()-2; i++) {
            if (heights[i-1] < heights[i] && heights[i+1] < heights[i]) {
                count++;
            }
        }

        if (heights[0] > heights[1]) {
            count++;
        }
        if (heights[heights.size() - 1] > heights[heights.size() - 2]) {
            count++;
        }
        return count;

    }
};

