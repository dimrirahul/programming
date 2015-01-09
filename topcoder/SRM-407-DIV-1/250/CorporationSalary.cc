
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
#include <stdio.h>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

// }}}

typedef long long UL;
class CorporationSalary
{
public:

    bool isRoot (vector<string>& r, int pos) { 
        REP(i, r.size()) {
            if (r[i][pos] == 'Y') {
                return false;
            }
        }
        return true;
    }

    UL findSum(int nodeId, vector<string>& relations) {
        printf(" Findsum for nodeId=%d\n", nodeId);
        bool isLeaf = true;
        UL sum = 0;
        REP(i, relations[nodeId].size()) {
            if (relations[nodeId][i] == 'Y') {
                sum += findSum(i, relations);
                isLeaf = false;
            }
        }

        if(isLeaf) {
            sum = 1;
        }
        printf("Sum = %lld\n", sum);
        return sum;
    }
	long long totalSalary(vector <string> relations)
	{
        UL sum = 0;
        REP(i, relations.size()) {
            if (isRoot(relations, i)) {
                printf("Root Index = %d", i);
                sum += findSum(i, relations);
            }
        }
        return sum;
	}
};

