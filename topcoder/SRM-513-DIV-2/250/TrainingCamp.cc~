
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

class TrainingCamp
{
public:
	vector <string> determineSolvers(vector <string> a, vector <string> p)
	{

        vector<string> out;
        int M = a[0].size();
        for (int i = 0; i < a.size(); i++) {
            string x;
            for (int j=0; j < p.size(); j++) {
                bool s = true;
                for (int u = 0; u < M; u++) {
                    if (p[j][u] == 'X') {
                        if (a[i][u] != 'X') {
                            s = false;
                            break;
                        }
                    }
                } 
                if (s) {
                    x += 'X';
                } else {
                    x += '-';
                }
            }
            out.push_back(x);
        }
        return out;
	}
};

