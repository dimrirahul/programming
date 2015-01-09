
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

class TheAlmostLuckyNumbersDivTwo
{
public:

    int getLength(int n) {
        char buffer[100];
        sprintf(buffer, "%d", n);
        int len = 0;
        while(len != NULL) {
            len++;
        }
        return len;
    }

    int numAtPos(int a, int pos) {
        return (a / (int) pow (10, pos)) % 10;
    }

    bool isLucky(int a) {
        int luck = 0;
        int len = getLength(a);
        for (int i = 0; i < len; i++) {
            int d = numAtPos(a, i);
            if (d != 7 && d != 4) {
                luck++;
            }
        }
        return luck < 2;
    }

	int find(int a, int b)
	{
        int s = to_string(a);
        int sum = 0;
        for (int i  = a; i <= b; i++){
            if(isLucky(i)) {
                sum++;
            }
        }
        return sum;

	}
};

