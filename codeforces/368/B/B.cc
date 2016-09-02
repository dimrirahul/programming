#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;
using PI = pair<int, int>; //node, distance;
using VI = vector<PI>;
using MVI = map<int, VI>;

MVI adjList;
set<int> storage;

const int MAX_LEN = (int)1e9 + 999;

void insertNeighbor(int src, int neighbor, int len) {
    PI p = make_pair(neighbor, len);
    auto it = adjList.find(src);
    if (it != adjList.end()) {
        it->second.push_back(p);
    } else {
        VI v;
        v.push_back(p);
        adjList.insert(make_pair(src, v));
    }
}

void makeTree(int m) {
    for (int i = 0; i < m;  i++) {
        int u, v, l;
        cin >> u >> v >> l;
        insertNeighbor(u, v, l);
        insertNeighbor(v, u, l);
    }
}

void updateStorage(int k) {
    for (int i = 0 ; i < k ; i++) {
        int t;
        cin >> t;
        storage.insert(t);
    }
}

int getClosestCity(int s) {
    int res = MAX_LEN;
    auto it = adjList.find(s);
    if (it == adjList.end()) return res;
    for (auto& children : it->second) {
        if (storage.count(children.first) != 0) continue;
        res = min(res, children.second);
    }
    return res;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    makeTree(m);
    updateStorage(k);
    int res = MAX_LEN;
    for (auto& it : storage) {
        res = min(res, getClosestCity(it));
    }
    cout << (res == MAX_LEN ? -1 : res) << "\n";
    return 0;
}
