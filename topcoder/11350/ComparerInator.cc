
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

class ComparerInator
{
public:
	int makeProgram(vector <int> A, vector <int> B, vector <int> wanted)
	{
        bool e1, e2, e3, e4;
        e1 = e2 = e3 = e4 = true;

        for (int i = 0; i < A.size(); i++) {

            if (e1) {
                e1 = (wanted[i] == A[i]);
            }

            if (e2) {
                e2 = (wanted[i] == B[i]);
            }

            if (e3) {
                e3 = (wanted[i] == min(A[i], B[i]));
            }

            if (e4) {
                e4 = (wanted[i] == max(A[i], B[i]));
            }
        }

        int retValue = 1;
        if (e1 || e2 ) {
            retValue = 1;
        }else if ( e3 || e4) {
            retValue = 7;
        } else {
            retValue = -1;
        }

		return retValue; 
	}
};
