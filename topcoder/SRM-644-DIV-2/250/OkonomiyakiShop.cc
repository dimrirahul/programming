
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

const int SZ = 10001;
class OkonomiyakiShop
{
public:
    int store[SZ];
    vector <int> ov;

    int findBound(int start, int end, int value, bool upperBound) {
        while (start < end) {
            int mid = (start + end ) / 2;
            if (upperBound) {
                if (value >= ov[mid]) {
                    start = mid + 1;
                } else {
                    end = mid;
                }
            } else {
                if (ov[mid] < value) {
                    start = mid + 1;
                } else {
                    end = mid;
                }
            }
        }
        return start;
    }

	int count(vector <int> o, int K)
	{
        REP (i, SZ) store[i] = 0;
        REP(i, o.size()) {
            store[o[i]]++;
        }
        REP(i, SZ) {
            if (store[i] > 0) {
                ov.push_back(i);
            }
        }
        
        int res = 0;
	    for (int i = 0; i < ov.size(); i++)	{
            int _max = ov[i] + K;
            int ub = findBound(i+1, ov.size(), _max, true);
            ub = min(ub, (int)ov.size()-1);
            if (ov[ub] > _max) ub--;
            printf("i =%d _max=%d ub=%d ov[i]=%d\n", i, _max, ub, ov[i]);
            res += ((ub - i) * store[ub] * store[i]); 
            printf("res = %d\n", res);
        }

        return res;
	}

};

