#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <array>
#include <queue>
#include <stack>

using namespace std;
using PI = pair<int, int>;
using VI = vector<int>;
using VPI = vector<PI>;
const int MX_SZ = ((int)1e5) + 10;
const int NO_PARENT = -1;
using LL = long long;
using PL = pair<int, LL>;

array<int, MX_SZ> pTree;
array<int, MX_SZ> nValue;
array<int, MX_SZ> eValue;

//set<PI> nodesToDelete;

using SPI = set<PI>;
map<int, SPI> tree;
array<int, MX_SZ> nodesInTree;
const bool dbg = !true;

set<int> deletedNodes;

void findNodesToDelete(int node, set<int>& nodesToDelete) {
    LL ec = 0;
    set<int> visited;
    stack<PL> stk;

    stk.push(make_pair(node, ec));
    while (!stk.empty()) {
        PL p = stk.top();
        stk.pop();
        if (visited.count(p.first)) continue;
        visited.insert(p.first);
        auto it = tree.find(p.first);
        if (it == tree.end()) continue;
        for (const auto& it1 : it->second) {
            if (visited.count(it1.first) || deletedNodes.count(it1.first)) continue;
            PL p1 = make_pair(it1.first, p.second + it1.second);
            if ((p.second + it1.second) > nValue[it1.first]) {
                nodesToDelete.insert(it1.first);
            } else {
                stk.push(p1);
            }
        }
    }

}

int augmentTree(int node) {
    if (node == NO_PARENT) return 0;
    if (nodesInTree[node] != -1) return nodesInTree[node];
    auto it = tree.find(node);
    int res = 1;
    if (it != tree.end()) {
        for (auto& it1 : it->second) {
            res += augmentTree(it1.first);
        }
    }
    nodesInTree[node] = res;
    return res;
}

void printAugmentedTree(int n) {
    for (int i = 1; i <= n; i++)
        cout << "Node: " << i << " has total of " << nodesInTree[i] << " children \n";
}

void printNodesToDelete(int i, set<int>& nodesToDelete) {
    bool first = true;
    for (auto it: nodesToDelete) {
        if (first) {
            cout << "Node: " << i << " offending nodes: " << it;
            first = false;
        } else {
            cout << " " << it;
        }
    }
    cout << "\n";
}

void fixUp(int node) {
    int cnt = augmentTree(node);
    deletedNodes.insert(node);
    while (node != NO_PARENT) {
        nodesInTree[node] -= cnt;
        node = pTree[node];
    }
}

int main() {
    int n; cin >> n;
    pTree.fill(NO_PARENT);
    int res = 0;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        nValue[i+1] = t;
    }
    for (int i = 0; i < n-1; i++) {
        int t1, t2; cin >> t1 >> t2;
        auto it = tree.find(t1);
        pTree[i+2] = t1;
        PI ch = make_pair(i + 2, t2);
        if (it == tree.end()) {
            SPI spi;
            spi.insert(ch);
            tree.emplace(make_pair(t1, move(spi)));
        } else {
            it->second.insert(ch);
        }
    }
    nodesInTree.fill(NO_PARENT);
    augmentTree(1);
    if (dbg) printAugmentedTree(n);
    stack<int> stk;
    set<int> visited;
    stk.push(1);
    while (!stk.empty()) {
        int node = stk.top();
        stk.pop();
        if (visited.count(node) || deletedNodes.count(node)) continue;
        visited.insert(node);
        set<int> nodesToDelete;
        findNodesToDelete(node, nodesToDelete);
        for (auto& it: nodesToDelete) {
            if (dbg) cout << " Adding elements: " << augmentTree(it) << "\n";
            res += augmentTree(it);
            fixUp(it);
        }
        auto it = tree.find(node);
        if (it == tree.end()) continue;
        for (auto& it1 : it->second) {
            if (visited.count(it1.first) || deletedNodes.count(it1.first)) continue;
            stk.push(it1.first);
        }
    }

    /*
    for (int i = 1; i <= n; i++) {
        if (deletedNodes.count(i)) continue;
        set<int> nodesToDelete;
        findNodesToDelete(i, nodesToDelete);
        if (dbg) printNodesToDelete(i, nodesToDelete);
        for (auto& it: nodesToDelete) {
            if (dbg) cout << " Adding elements: " << augmentTree(it) << "\n";
            res += augmentTree(it);
            fixUp(it);
        }
    }
    */
    cout << res << "\n";
    return 0;
}

