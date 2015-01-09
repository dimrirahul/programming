
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

const int SIZE = 110;
const int invalidStamp = 10000;
typedef pair <int, int> PI;
class StampsCollection
{
public:
    int matrix[SIZE][SIZE];
    bool visited[SIZE];
    int dummyNodes;

    map <int, PI > costMap;

    void init() {
        REP(i, SIZE) {
            REP(j, SIZE) {
                matrix[i][j] = 0;
            }
            visited[i] = false;
        }
    }

    void populateMatrix(int n, vector<string>& demand, vector<int>& price) {
        REP(i, demand.size()) {
            int r, c, num;
            stringstream ss (demand[i]);
            if (ss >> num) {
                r = c = num;
            }
            if (ss >> num) {
                c = num;
            } else {
                c = dummyNodes++;
            }
            matrix[r][c] = matrix[c][r] = max(matrix[r][c], price[i]);
        }
    }

    void printMatrix(int n) {
        REP(i, n) {
            REP(j, n) {
                cout << matrix[i][j] << "  ";
            }
            cout << "\n";
        }
    }

    pair<int, int> getNeighbors(int root, int n) {
        PI res = make_pair(-1, -1);
        bool first = false;
        REP(i, n) {
            if (matrix[root][i] != 0) {
                if (!first) {
                    res.first = i;
                    first = true;
                } else {
                    res.second = i;
                    break;
                }
            }
        }
        return res;
    }

    void solveNeighbor(int node, int n, int parent, int *res) {
        if (visited[node]) { 
            res[0] = 0;
            res[1] = matrix[parent][node];
          //  printf("node=%d, parent=%d, res[0]=%d, res[1]=%d\n", node, parent, res[0], res[1]);
            return;
        } 
        visited[node] = true;
        PI t = getNeighbors(node, n);
        int otherNode = (t.first == parent) ? t.second : t.first;
        if (otherNode != -1) {
            int res2[2];
            solveNeighbor(otherNode, n, node, res2);
            bool isLastEdgeUsed = !(res2[0] == res2[1]);
            if (!isLastEdgeUsed) {
                res[0] = res2[1];
                res[1] = matrix[parent][node] + res[0];
            } else {
                if (res2[0] + matrix[parent][node] > res2[1]) {
                    res[1] = res2[0] + matrix[parent][node];
                    res[0] = res2[1];
                } else {
                    res[0] = res[1] = res2[1];
                }
            }
        } else {
            res[0] = 0;
            res[1] = matrix[parent][node];
        }
        //printf("node=%d, parent=%d, res[0]=%d, res[1]=%d\n", node, parent, res[0], res[1]);
    }

    int getCost(int node, int n) {
        if (visited[node]) return 0;
        visited[node] = true;
        PI t = getNeighbors(node, n);
        int res1[2], res2[2];
        if (t.first == -1) return 0;
        solveNeighbor(t.first, n, node, res1);
        bool cycles = visited[t.second];
        int cost = 0;
        if (t.second != -1) {
            solveNeighbor(t.second, n, node, res2);
            bool isLastEdgeUsedFirst = !(res1[1] == res1[0]);
            bool isLastEdgeUsedSecond = !(res2[1] == res2[0]);
            if (cycles) { 
                if (isLastEdgeUsedFirst) {
                    res1[1] = res1[0];
                }
                if (isLastEdgeUsedSecond) {
                    res2[1] = res2[0];
                }
                return max(max(res1[0], res1[1]), max(res2[0], res2[1]));
            }
            if (isLastEdgeUsedFirst && isLastEdgeUsedSecond) {
                //printf("node=%d, res1[0]=%d, res1[1]=%d, res2[0]=%d, res2[1]=%d\n", node, res1[0], res1[1], res2[0], res2[1]);
                cost = max(res1[0] + res2[1], res1[1] + res2[0]);
            } else {
                cost = res1[1] + res2[1];
            }
        } else {
            cost = res1[1];
        }
        return cost;
    }



    int sell(int n, vector <string> demand, vector <int> price)
    {
        init();
        dummyNodes = n;
        populateMatrix(n, demand, price);
        n = max(n, dummyNodes);
        //printMatrix(n);
        int res = 0;
        REP(i, n) {
            if (!visited[i]) {
                int sum = getCost(i, n);
               // printf("for index = %d the sum is %d\n", i, sum);
                res += sum;
            } else {
                //cout << "index=" << i << "has already been visited" << "\n"; 
            }

        }
        return res;
    }
};

