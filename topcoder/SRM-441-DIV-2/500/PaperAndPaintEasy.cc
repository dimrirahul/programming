
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

typedef long long LL;
class PaperAndPaintEasy
{
    public:
        long long computeArea(int width, int height, int xfold, int cnt, int x1, int y1, int x2, int y2)
        {
            long long res = 0;
            int minx = min(x1, x2);
            int maxx = max(x1, x2);
            int miny = min(y1, y2);
            int maxy = max(y1, y2);

            bool perfectOverlap = (width  == 2 * xfold);
            if (!perfectOverlap) {
                int commonBoundary = 0;

                if (width < 2*xfold) {
                    commonBoundary = width - xfold;
                } else {
                    commonBoundary = xfold;
                }
                printf("commonBoundary =%d \n", commonBoundary);
                if (commonBoundary <= minx) {
                    res = ((LL)(maxx - minx)) * (maxy -miny) * (cnt + 1);
                    printf("Case where commonBoundary(%d) < minx(%d) result = %lld\n", commonBoundary, minx, res);
                } else if (commonBoundary <= maxx && commonBoundary > minx) {
                    res += ((LL)(commonBoundary - minx)) * (maxy - miny) * (cnt + 1) * 2;
                    res += ((LL)(maxx - commonBoundary)) * (maxy - miny) * (cnt + 1);
                    printf("Case where commonBoundary(%d) > minx(%d) and < maxx(%d)result = %lld\n", commonBoundary, minx, maxx, res);
                } else if (commonBoundary > maxx) {
                    res = ((LL)(maxx - minx)) * (maxy - miny) * (cnt +1) * 2;
                    printf("Case where commonBoundary(%d) > maxx(%d) result = %lld\n", commonBoundary, maxx, res);
                }
            } else {
                res = ((LL)(maxx - minx)) * (maxy - miny) * (cnt +1) * 2;
                printf("Perfect match   width(%d) result = %lld\n", width, res);
            }
            long long maxArea = ((long long ) width) * height;
            return maxArea - res;
        }
};

