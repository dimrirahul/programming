
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


typedef int T;
typedef vector<T> VT;

const int MAX_INT = 100001;
class CubeRoll
{
public:


    int binSearch(VT &v, T value, bool isLb, int start, int end) {
        if (v[start] > value) {
            return isLb ? -1: start;
        }

        if (v[end -1] < value) {
            return isLb ? end -1: -1;
        }

        int pos = -1;
        while (start < end) {
            int mid = (start + end) / 2;
            if (v[mid] == value) {
                pos = mid;
                break;
            } else if (v[mid] > value) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }

        if (pos != -1) {
            while (pos > start && v[pos] == v[pos -1]) {
                pos--;
            }
            return pos;
        }

        if (isLb) {
            return v[start] > v[end -1] ? start:end -1;
        } else {
            return v[start] > v[end -1] ? start: end -1;
        }
    }
    int getM2 (int initPos, int goalPos, vector<int>& holePos) {
        int lbIndex = binSearch(holePos, goalPos, true, 0, holePos.size()); 
        int ubIndex = binSearch(holePos, goalPos, false, 0, holePos.size()); 

        int lb = MAX_INT * -1;
        int ub = MAX_INT; 

        printf("LbIndex = %d, ubIndex = %d initPos=%d, goalPos=%d\n", lbIndex, ubIndex, initPos, goalPos);
        if (lbIndex != -1) {
            lb = holePos[lbIndex];
        }

        if (ubIndex != -1) {
            ub = holePos[ubIndex];
        }

        printf("Lbvalue = %d, ub Value = %d \n", lb, ub);
        if (goalPos <= lb || goalPos >= ub) {
            return -1;
        }

        int res = MAX_INT;
        bool b1 = true; bool b2 = true;
        for ( int i = 1; (b1 || b2) && i < 102  ; i++) {
            printf("looping with i = %d, b1 =%d, b2=%d\n", i, b1, b2);
            if (b1) {
                b1 = initPos + (i * i) < ub;
            }

            if (b2) {
                b2 = initPos - (i * i) > lb;
            }
            printf("after evaluating   b1 =%d, b2=%d\n", b1, b2);

            int r1 = -1;
            int r2 = -1;
            if (b1) {
                r1 = getMinimumSteps(initPos + (i * i), goalPos, holePos);
                printf("r1 = %d\n", r1);
            }

            if (b2) {
                r2 = getMinimumSteps(initPos - (i * i), goalPos, holePos);
                printf("r2 = %d\n", r2);
            }

            if ( r1 != -1) {
                res = min(res, r1);
            }

            if ( r2 != -1) {
                res = min( res, r2);
            }
            printf("res = %d\n", res);
        }

        if (res != MAX_INT) { 
            printf("returning  %d\n", res +1);
            return 1 + res;
        } else {
            printf("returning  %d\n", -1);
            return -1;
        }
    }

	int getMinimumSteps(int initPos, int goalPos, vector <int> holePos)
	{
        sort(holePos.begin(), holePos.end());
        return getM2(initPos, goalPos, holePos);
	}
};

