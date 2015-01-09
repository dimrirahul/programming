
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

class Embassy
{
public:
	int visaApplication(vector <int> forms, int dayLength, int openTime)
	{
        int sum = forms[0];
        int tnow = 0;
        int tfin;
        int tLast = 0;
        for (int i = 1; i < forms.size(); i++) {
            tfin = tnow + forms[i];
            if (tfin >= openTime) {
                break;
            } else {
                tnow += forms[i];
                tLast = forms[i];
            }
        }

        tfin -= tLast;


        sum -= tfin;
        tnow = tfin;
        for (int i = 1; i < forms.size(); i++) {
            tfin = tnow + forms[i];
            if (tfin <= openTime) {
                sum += forms[i];
                tnow += forms[i];
            } else {
                while (tfin > dayLength) {
                    sum += dayLength;
                    tfin -= dayLength;
                }
                sum += dayLength - tnow;
                tnow = 0;
            }
        }
		return sum;
	}
};

