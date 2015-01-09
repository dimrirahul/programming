
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
#include <string.h>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

// }}}

const int ML = 11;
class Comp {
    public:
        bool operator ()(int lhs, int rhs) const {return rhs < lhs;}
};
class DistinctDigits
{
public:
    int getLargestNumber(int num) {
        int buffer[ML];
        int res = 0;
        memset(buffer, 0, sizeof(int) * ML);
        while (num != 0) {
            buffer[num%10]++;
            num = num/10;
        }
        int mult = 1;
        for(int i = 0; i < ML; i++) {
            while(buffer[i] != 0) {
                res += i * mult;
                mult = mult * 10;
                buffer[i]--;
            }
        }
        return res;
    }
	int count(int low, int high)
	{
        int res = 0;
        Comp c;
        for (int i = low; i <= high; i++) {
            int var = getLargestNumber(i);
            printf("i=%d, var=%d\n", i, var);
            bool inRange = var <= high && var >= low;
            if (inRange) {
               if (var <= i) res++;     
            } else {
                res++;
            }
        }
		return res;
	}
};

