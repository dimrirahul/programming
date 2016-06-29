#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <array>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;
const int MAX_ITEMS = ((int)1e5) + 15;
const int NO_PARENT = -1;
using SI = vector<int>;
using MSI = map<int, SI>;
using LL = long long;
using STK = stack<int>;
const bool dbg = !true;

#define REP(I, N) for (int (I) = 0; (I) < (N); (I)++)
struct C {
    int parent[MAX_ITEMS], nValues[MAX_ITEMS], edgeCost[MAX_ITEMS], childNodes[MAX_ITEMS] ;
    LL dFromRoot[MAX_ITEMS], maxD[MAX_ITEMS];
    SI tree[MAX_ITEMS];

    int n;
    C() {
        REP (i, MAX_ITEMS) {
            parent[i] = NO_PARENT;
            dFromRoot[i] = NO_PARENT;
            nValues[i] = NO_PARENT;
            edgeCost[i] = NO_PARENT;
            maxD[i] = childNodes[i] = NO_PARENT;
        }
        maxD[1] = 0;
    }

    /*
    LL getDistanceFromRoot(int node) {
        if (dFromRoot[node] != NO_PARENT) return dFromRoot[node];
        dFromRoot[node] = (node == 1) ? 1 : edgeCost[node] + getDistanceFromRoot(parent[node]);
        return dFromRoot[node];
    }

    void populateDistanceFromRoot() {
        for (int i = 1; i <= n; i++) {
            getDistanceFromRoot(i);
        }
    }
    */

    int augmentTree(int node) {
        if (childNodes[node] != NO_PARENT) return childNodes[node];
        int res = 1;
        for (auto& it : tree[node]) {
            res += augmentTree(it);
        }
        childNodes[node] = res;
        return res;
    }

    void printDistanceFromRoot() {
        REP(i, n) {
            cout << "Index: " << i+1 << " had distance " << dFromRoot[i+1] << "\n";
        }
    }

    void printAugmentedTree() {
        REP(i, n) {
            cout << "Index: " << i+1 << " has chilren " << childNodes[i+1] << "\n";
        }
    }

    bool makesParentSad(int node) {
        if (node == 1) {
            return false;
        }
        int p = parent[node];
        maxD[node] = max(maxD[p] + edgeCost[node], (LL)0);

        if (maxD[node] > nValues[node]) {
            if (dbg) {
                cout << "Node: " << node << " is sad becuse it has some parent too far away \n";
            }
            return true;
        }
        return false;
    }

    void start() {
        cin >> n;
        REP(i, n) {
            int t; cin >> t;
            nValues[i+1] = t;
        }
        REP(i, n-1) {
            int t1, t2;
            cin >> t1 >> t2;
            parent[i+2] = t1;
            edgeCost[i+2] = t2;
            tree[t1].push_back(i + 2);
        }
        //populateDistanceFromRoot();
        //if (dbg) printDistanceFromRoot();
        augmentTree(1);
        if (dbg) printAugmentedTree();
        int res = 0;
        STK stk;
        stk.push(1);
        while (!stk.empty()) {
            int node = stk.top();
            stk.pop();
            if (makesParentSad(node)) {
                res += childNodes[node];
            } else {
                for (auto& it: tree[node])
                    stk.push(it);
            }
        }
        cout << res << "\n";
    }
};

C c;
int main() {
    c.start();
    return 0;
}

