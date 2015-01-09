
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

typedef pair <int , int > PI;

const int INF = 1000000000;
const int SZ = 51;
class TheKingsTree
{
public:
    map < int, PI > dpMap;
    int matrix[SZ][SZ];
    set<int> chNodes;
    set<int> pNodes;
    int totNodes;
    bool isRed[SZ];

    void populateMatrix(vector<int> & p) {
        REP (i, SZ) {
            REP (j, SZ) {
                matrix[i][j] = INF;
            }
            isRed[i] = false;
        }
        REP (i, p.size()) {
            matrix[p[i]][i+1] = matrix[i+1][p[i]] = 1;
        }
        for (int i = 0; i <= p.size(); i++) {
            bool isLeaf = true;
            REP( j, p.size()) {
                if (p[j] == i) {
                    isLeaf = false;
                    break;
                }
            }
            if (isLeaf) {
                dpMap[i] = make_pair(0, 1);
                isRed[i] = true;
                chNodes.insert(i);
            }
        }

        REP (i, totNodes) {
            REP (j, totNodes) {
                printf("%d ", matrix[i][j]);
            }
            cout << "\n";
        }
    }

    void populatePNodes() {
        pNodes.clear();
        for (set<int>::iterator it = chNodes.begin(); it != chNodes.end(); it++) {
            if (*it == 0) continue;
            REP (j, totNodes) {
                if (matrix[*it][j] == 1) {
                    pNodes.insert(j);
                    break;
                }
            }
        }
        printf("Pnodes\n");
        for (set<int>::iterator it = pNodes.begin(); it != pNodes.end(); it++) {
            printf("%d ", *it);
        }
        printf("\n");
    }

    void optimize() {
        for (set<int>::iterator it =  pNodes.begin(); it != pNodes.end(); it++) {
            int g = 0, r = 0, s = 0;
            REP (j, totNodes) {
                if (matrix[*it][j] == 1) {
                    PI p = dpMap[j];
                    g += p.first;
                    r += p.second;
                }
            }
            if ( g > r ) {
                dpMap[*it] = make_pair(g, r+1);
                isRed[*it] = true;
            } else {
                dpMap[*it] = make_pair(g +1, r);
                isRed[*it] = false;
            }
        }
    }
	
    int getNumber(vector <int> parent)
	{
        totNodes = parent.size() + 1;
        populateMatrix(parent);
        populatePNodes();
        int count = 0;
        while (pNodes.size() > 0 ) {
            optimize();
            chNodes.clear();
            chNodes.insert(ALL(pNodes));
            populatePNodes();
        }
        for (map<int, PI>::iterator it = dpMap.begin(); it != dpMap.end(); it++) {
            PI p = it->second;
            printf("Index =%d gree=%d, red=%d\n", it->first, p.first, p.second);
            count +=  isRed[it->first] ? p.second : p.first;
        }
		return count;
	}
};

