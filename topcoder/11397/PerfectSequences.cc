
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

class PerfectSequences
{
public:

    string canFit(vector<int>& modSeq) {
        sort(modSeq.begin(), modSeq.end());
        int first = modSeq[0];
        int second = modSeq[1];
        int third = modSeq[2];

        for (int i = 0; i < modSeq.size() ; i++) {
            cout << modSeq[i] << " " ;
        }

        int r1;
        if (second % first == 0) { 
            r1 = second/first;
        } else {
            r1 = -1;
        }

        int r2;
        if (third % first == 0) {
            r2 = third/first;
        } else {
            r2 = -1;
        
        }

        cout << "\n r1=" <<  r1 << " r2" << r2 << "\n";
        if ( r1 == 2 && r2 == 3 ) {
            return string("No");
        } 

        if ( r1 ==2 || r2 == 2 || r1 == 3 || r2 == 3) {
            return string("Yes");
        }

        return string("No");


    }
    string fixIt(vector <int> seq)
    {
        int zero = 0;
        int one = 0;
        vector<int> modSeq;
        int numNegs = 0;
        bool res = true;
        int sum = 0;

        if (seq.size() == 1) {
            return string("Yes");
        }

        for (int i = 0; i < seq.size();i++) {
            if (seq[i] == 0) {
                zero++;
            } else if (seq[i] < 0) {
                numNegs++;
            } else if (seq[i] == 1) {
                one++;
            } else {
                modSeq.push_back(seq[i]);
            }
        }


        if (zero > 0) {
            if (zero  == seq.size()) {
                return string("Yes");
            }else {
                return string("No");
            }
        }

        if (one == seq.size() || one == 0) {
            return string("No");
        }

        if (numNegs > 1) {
            return string("No");
        }

        if (modSeq.size() > 2) {
            return string("No");
        }

        if (one > 0) {
            modSeq.push_back(one);
        } else {
            return string("No");
        }

        if (modSeq.size() == 3) {
            return canFit(modSeq);
        }else {
            if (one > 1) {
                modSeq[1]--;
                modSeq.push_back(1);
                return canFit(modSeq);
            } else {
                return string("No");
            }
        }
    }
};

