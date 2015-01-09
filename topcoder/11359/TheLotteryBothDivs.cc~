
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


bool cmp(string a, string b) {
    return a.size() < b.size();
}

class TheLotteryBothDivs
{
public:

    set<string> m_prevSet;
    void createStringVector(vector<string> input, vector<string>& out) {
        for (int i = 0; i < input.size(); i++) {
            reverse(input[i].begin(), input[i].end());
            out.push_back(input[i]);
        }
        sort(out.begin(), out.end(), cmp);
    }

    double find(vector <string> goodSuffixes)
    {
        stringstream ss;
        double totProb = (double) 0;
        vector<string> sortedVector;
        createStringVector(goodSuffixes, sortedVector);
        for (int i = 0; i < sortedVector.size(); i++) {
            ss.str("");
            bool prefixFound = false;
            for ( int j = 0 ; j < sortedVector[i].size(); j++) {
                ss << sortedVector[i][j];
                if (m_prevSet.count(ss.str()) == 1) {
                    prefixFound = true;
                    break;
                }
            }

            if (prefixFound) {
                continue;
            }

            totProb += (double)1 / (pow(10, sortedVector[i].size()));
            m_prevSet.insert(sortedVector[i]);
        }

        return totProb;
    }
};

