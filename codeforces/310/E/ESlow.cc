#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
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
#include <string>
#include <utility>
#include <vector>
#include <stdio.h>
#include <unordered_map>


#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

using PI = pair <int, int>;
using VI = vector <int>;
using VS = vector <string>;
using LL = long long;
using SI = set<int>;
using VPI = vector<PI>;

const bool dbg = !true;
const int N = (int)1e9;
const PI limit = make_pair(1, N);

struct Node {
    PI range;
    int left, right;
    VPI storedIntervals;
    Node(PI _range, int parent): range(_range) { 
        left = parent << 1;
        right = (parent << 1) +1;
    }
};

struct Segtree {
    PI range;
    int root;
    unordered_map<int, Node> nodeById;

    Segtree(PI _range): range(_range), root(1) {};

    bool isLeafNode(PI p) { return (p.second - p.first) == 1;}

    bool isRangeContainedByInterval(PI interval, PI range) {
        return interval.first <= range.first && interval.second >= range.second;
    }

    int addInterval(PI interval, PI range, int curr) {
        auto nodeByIdIter = nodeById.find(curr);
        if (nodeByIdIter == nodeById.end()) { 
            nodeByIdIter = nodeById.emplace(curr, Node(range, curr)).first;
        }
        Node& node = nodeByIdIter->second;

        if (isLeafNode(range) || isRangeContainedByInterval(interval, range)) {
            node.storedIntervals.push_back(interval);
            return curr;
        }

        auto mid = (range.first + range.second) >> 1;
        if (interval.first < mid) addInterval(interval, make_pair(range.first, mid), node.left);
        if (interval.second > mid) addInterval(interval, make_pair(mid, range.second), node.right);
        return curr;
    }

    void addInterval(PI interval) {
        addInterval(interval, range, root);
    }

    void findOverlappingIntervals(int key, VPI& out, int curr) {
        auto nodeByIdIter = nodeById.find(curr);
        if (nodeByIdIter != nodeById.end()) {
            Node& node = nodeByIdIter->second;
            out.insert(end(out), begin(node.storedIntervals), end(node.storedIntervals));
            if ( key < (node.range.first + node.range.second) / 2) {
                findOverlappingIntervals(key, out, node.left);
            } else {
                findOverlappingIntervals(key, out, node.right);
            }
        }
    }

    void findOverlappingIntervals(int key, VPI& out) {
        findOverlappingIntervals(key, out, root);
    }

};

Segtree upTree(limit);
Segtree leftTree(limit);
set <PI> upVisited;
set <PI> leftVisited;
struct E {

    int sz;

    int solveForCount(Segtree &lookupTree, Segtree &insertTree, int value, int other, bool isVertical) {
        PI key = make_pair(value, other);
        if (isVertical) {
            auto iter = upVisited.find(key);
            if (iter != upVisited.end()) return 0;
        } else {
            auto iter = leftVisited.find(key);
            if (iter != leftVisited.end()) return 0;
        }
        VPI out;
        lookupTree.findOverlappingIntervals(value, out);
        int closest = 0;
        for (auto &i: out) {
            if (dbg) printf("[%d, %d] ", i.first, i.second);
            int t = i.second - 1;
            int row = sz + 1 - t;
            closest = max(closest, row);
        }
        int res = other - closest;
        if (isVertical) {
            upVisited.insert(key);
        } else {
            leftVisited.insert(key);
        }
        if (dbg) printf("Inserting [%d, %d]\n", closest + 1, other + 1);
        insertTree.addInterval(make_pair(closest + 1, other + 1));
        return res;
    }
    void start() {
        int q;
        cin >> sz >> q;
        REP(i, q) {
            int c, r; char dir; cin >> c>> r>> dir;
            int res;
            if (dir == 'U') {
                res = solveForCount(leftTree, upTree, c, r, true);
            } else {
                res = solveForCount(upTree, leftTree, r, c, false);
            }
            cout << res << "\n";
        }
    }    
};

E t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
