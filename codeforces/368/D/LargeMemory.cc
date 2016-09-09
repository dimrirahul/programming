#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <bitset>
#include <stack>

using namespace std;
using PI = pair<int, int>;
using VPI = vector<PI>;
using VI = vector<int>;

map<int, VI> tree;
map<int, int> parentNodes;

const int MAX_NODE = 1001;
const int MAX_QUERIES = ((int)1e5) + 2;

struct Op;

int res[MAX_QUERIES];

struct Op {
    Op() {init();}
    int ot, r, c, id;

    void init() {
        ot = r = c = -1;
    }

    void read() {
        cin >> ot;
        if (ot == 1 || ot == 2) {
            cin >> r >> c;
        } else if (ot == 3 || ot == 4) {
            cin >> r;
        }
    }
};

struct Matrix {
    Matrix() {
    }

    int getIdx(int r, int c) { return r * MAX_NODE + c; }

    bool isSet(int r, int c) { return store.test(getIdx(r, c));}

    void setIdx(int r, int c, bool value = true) {
        store.set(getIdx(r, c), value);
    }

    bitset<MAX_NODE * MAX_NODE> store;
};

Op operations[MAX_QUERIES];
struct State {
    State() {
        init();
    }

    State(int inpR, int inpC) : r(inpR), c(inpC) {init();}

    void init() {
        for (int i = 0; i < MAX_NODE; i++) {
            rowSum[i] = 0;
        }
        totSum = 0;
    }

    void update(const Op& op) {
        if (op.ot == 1) {
            if (!flipped[op.r] && matrix.isSet(op.r, op.c)) return;
            if (flipped[op.r] && !matrix.isSet(op.r, op.c)) return;

            matrix.setIdx(op.r,op.c, !flipped[op.r]);
            rowSum[op.r]++;
            totSum++;
        } else if (op.ot == 2) {
            if (!flipped[op.r] && !matrix.isSet(op.r, op.c)) return;
            if (flipped[op.r] && matrix.isSet(op.r, op.c)) return;

            matrix.setIdx(op.r,op.c, flipped[op.r]);
            rowSum[op.r]--;
            totSum--;
        } else if (op.ot == 3) {
            flipped.set(op.r, !flipped[op.r]);
            int v1 = rowSum[op.r];
            int v2 = c - v1;
            rowSum[op.r] = v2;
            totSum -= v1;
            totSum += v2;
        }
    }

    int r, c;
    Matrix matrix;
    bitset<MAX_NODE> flipped;
    int rowSum[MAX_NODE];
    int totSum;

};

void insertIntoTree(int p, const Op& op) {
    auto it = tree.find(p);
    if (it == tree.end()) {
        VI v;
        v.push_back(op.id);
        tree.insert(make_pair(p, v));
    } else {
        it->second.push_back(op.id);
    }
}

void makeTree(int n, int m, int q) {
    int currNode = 0;
    for (int i = 1; i <= q; i++) {
        Op& op = operations[i];
        op.read();
        if (op.ot == 4) {
            int parent = op.r;
            auto it = parentNodes.find(parent);
            if (it != parentNodes.end()) {
                parent = it->second;
            }
            parentNodes.insert(make_pair(i, parent));
            currNode = parent;
        }
        insertIntoTree(currNode, op);
        currNode = i;
    }
}

void init() {
    for (int i = 0; i < MAX_QUERIES; i++) {
        res[i] = -1;
        operations[i].id = i;
    }
}

/*
void doDfs(int nodeId, int n, int m, State& state) {
    if (tree.count(nodeId) == 0) return;
    VI& children = tree[nodeId];
    if (children.empty()) return;
    if (children.size() == 1) {
        int child = *children.begin();
        state.update(operations[child]);
        res[child] = state.totSum;
        doDfs(child, n, m, state);
        return;
    }
    State stateCopy(state);
    for (auto it : children) {
        state.update(operations[it]);
        res[it] = state.totSum;
        doDfs(it, n, m, state);
        state = stateCopy;
    }
}
*/

using PS = pair<int, State>;
stack<PS> stk;
void doDfs(int n, int m) {
    State state(n, m);
    stk.push(make_pair(0, state));
    while (!stk.empty()) {
        PS t = stk.top();
        stk.pop();
        State& ls = t.second;
        if (tree.count(t.first) == 0) continue;
        VI& children = tree[t.first];
        if (children.empty()) continue;
        while (children.size() == 1) {
            int child = children[0];
            ls.update(operations[child]);
            res[child] = ls.totSum;
            if (tree.count(child) == 0) children.clear();
            else children = tree[child];
        }
        for (auto it : children) {
            State stateCopy(ls);
            stateCopy.update(operations[it]);
            res[it] = stateCopy.totSum;
            stk.push(make_pair(it, stateCopy));
        }
    }
}
void printResult(int q) {
    for (int i = 1; i <= q; i++) {
        if (res[i] == -1) {
            res[i] = res[parentNodes[i]];
        }
        cout << res[i] << "\n";
    }
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    init();
    makeTree(n, m, q);
    //State state(n, m);
    //doDfs(0, n, m, state);
    doDfs(n, m);
    printResult(q);
    return 0;
}
