
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

class SortishDiv2
{
public:

    int countSortedness(vector<int>& v) {
        int ret = 0;
        for (int i = 0; i < v.size(); i++) {
            for (int j = i+1; j < v.size(); j++) {
                if (v[j] > v[i]) ret++;
            }
        }
        return ret;
    }

    int ways(int sortedness, vector <int> seq)
    {
        vector<int> emptyPos;
        int nums[102];
        REP(i, 102) {
            nums[i] = i;
        }
        REP(i, seq.size()) {
            if (seq[i] == 0) {
                emptyPos.push_back(i);
            } else {
                nums[seq[i]] = -1;
            }
        }

        vector<int> missingElements;
        for (int i = 1; i <= seq.size(); i++) {
            if (nums[i] != -1) {
                missingElements.push_back(nums[i]);
            }
        }

        sort(ALL(emptyPos));
        int validSeq = 0;

        do {
            vector<int> copy = seq;
            REP(i, emptyPos.size()) {
                copy[emptyPos[i]] = missingElements[i];
            }
            if (countSortedness(copy) == sortedness) {
                validSeq++;
            }

        } while (next_permutation(ALL(emptyPos)));

        return validSeq;
    }
};

