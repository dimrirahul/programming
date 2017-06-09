#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <array>
#include <stack>
#include <set>

using namespace std;
using VI = vector<int>;
using PI = pair<int, int>;

#define FORN(I, N) for (int (I) = 0; (I) < (N); (I)++)

const int MX_VERTEX = (2 * 10000) + 10;
const int MX_EDGES = (int) (1e5 + 10);

struct Vertex {
    map<int, int> edgesToNeighbor;
    int numWaysToDest;
    int dfsParent;

    void addNeighbor(int neighbor) {
        auto it = edgesToNeighbor.find(neighbor);
        if (it != edgesToNeighbor.end()) it->second++;
        else edgesToNeighbor.insert(make_pair(neighbor, 1));
    }

    set<int> getNeighbors() {
        set<int> neighbors;
        for (auto it : edgesToNeighbor) neighbors.insert(it.first);
        return neighbors;
    }

    Vertex() : numWaysToDest(0), dfsParent(-1) {}

};

struct A {
    array<Vertex, MX_VERTEX> vArr;

    int N, M;

    void readInput() {
        cin >> N >> M;
        FORN (i, M) {
            int t1, t2;
            cin >> t1 >> t2;
            vArr[t1].addNeighbor(t2);
        }
    }

    void doDfs() {
        stack<PI> stk;
        stk.push(make_pair(1, 0));
        vv[1].dfsParent = 0;
        set<int> visited;
        while (!stk.empty()) {
            PI p = stk.pop();
            set<int> neighbors = vv[p.first].getNeighbors();
        }

    }

    void start() {
        readInput();
        doDfs();
    }
    
};

A a;

int main(int argc, char **argv) {
    a.start();
    return 0;
}
