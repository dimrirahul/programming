
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
#include <cstring>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

// }}}
const int SZ = 21;
class Fragile2
{
    public:
        int aM[SZ][SZ];
        int N;
        int oldComp[SZ];
        int newComp[SZ];
        vector<string> om;
        set< vector<int> > compSet;
        void doBfs() {
            memset(newComp, 0, sizeof(int) * SZ);
            int comp = 0;
            bool v[SZ];
            memset(v, 0,sizeof(bool) * SZ);
            REP (i, N) {
                if (!v[i]) {
                    queue<int> q;
                    q.push(i);
                    while(!q.empty()) {
                        int f = q.front();
                        q.pop();
                        if (v[f]) continue;
                        v[f] = true;
                        newComp[f] = comp;
                        REP (j, N) {
                            if (aM[f][j] > 0 && !v[j]){
                                q.push(j); 
                            }
                        }
                    }
                    comp++;
                }
            }
        }

        void populateAM() {
            memset(aM, 0, sizeof(int) * SZ * SZ);
            REP(i, om.size()) {
                REP(j, om[i].size()) {
                    if (om[i][j] == 'Y') aM[i][j] = 1;
                }
            }
        }

        void printAM() {
            printf("THIS IS AM\n");
            REP(i, N) {
                REP(j, N) {
                    printf("%d ", aM[i][j]);
                }
                cout << "\n";
            }
            cout << "\n";
        }

        vector<int> compToV() {
            vector<int> res;
            REP(i, N) {
                res.push_back(newComp[i]);
            }
            return res;
        }

        void printComp() {
            REP (i, N) {
                printf("new [%d]= [%d]\n", i, newComp[i]);
            }
            cout << "\n";
        }
        void printVectorV(vector<int> v) {
            REP(i, v.size()) cout << v[i] << "  ";
            cout << "\n";
        }
        int countPairs(vector<string> graph) {
            om = graph;
            N = om.size();
            populateAM();
            printAM();
            doBfs();
            vector<int> t;
            t = compToV();
            printVectorV(t);
            compSet.insert(t);
            int res = 0;
            REP (i, N) {
                for (int j = i+1; j < N; j++) {
                    populateAM();
                    REP(k, N) {
                        aM[i][k] = 0;
                        aM[k][i] = 0;
                        aM[j][k] = 0;
                        aM[k][j] = 0;
                    }
                    doBfs();
                    t = compToV();
                    printComp();
                    printVectorV(t);
                    if (compSet.find(t) == compSet.end()) {
                        cout << "Inserting into set vector\n";
                        printVectorV(t);
                        res++;
                        compSet.insert(t);
                    }
                }
            }
            return res;
            
        }
};

