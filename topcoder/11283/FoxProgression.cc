
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

class FoxProgression
{
public:

    bool isAp(int a, int b, int d) {
        cout << "a = " << a << " b = " << b << "d = " << d << "\n";
        return (a -b == d);
    }

    int getRatio(int a, int b) {
        if (a % b == 0) {
            return (a/b);
        } else {
            return 0;
        }
    }
    bool isGp(int a, int b, int r) {
        if ( r== 0) {
            return false;
        }

        return (getRatio(a, b) == r);
    }

	int theCount(vector <int> seq)
	{
        if (seq.size() == 1) {
            return -1;
        }
        bool ap, gp;
        ap = gp = true;
        int d = seq[1] - seq[0];
        int r = getRatio(seq[1], seq[0]); 

        
        for (int i = 0; i < seq.size() - 1; i++) {
            cout << "Index = " << i << "\n";
            if (ap) {
                ap = isAp(seq[i + 1], seq[i], d);
                cout << "Ap = " << ap << "\n";
            } 
            if (gp) {
                gp = isGp(seq[i + 1], seq[i], r);
                cout << "Gp = " << gp << "\n";
            }
            if (!ap && !gp) {
                break;
            }
        }

        if (seq.size() == 2 ) {
            int nextAp, nextGp;
            nextAp = seq[seq.size() - 1] + d;
            nextGp = 0;
            if (gp) {
                nextGp = seq[seq.size() - 1] * r;
            }
            if (gp && nextAp == nextGp) {
                return 1;
            }
            if (gp) {
                return 2;
            }
            return 1;
        }

        if (ap || gp) {
            cout << " THis is where we return ap= " << ap << " GP = " << gp << "\n";
            return 1;
        } else {
            return 0;
        }

	}
};

