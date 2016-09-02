#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <set>


using namespace std;
using MI = map<int, int>;
using PI = pair<int, int>;
const int SZ = 103;
const bool dbg = !true;
int dp[SZ];
MI ladders;
MI snakes;
MI parent;
MI cost;

void reset() {
    for (int i = 0; i < SZ; i++) dp[i] = -1;
    ladders.clear();
    snakes.clear();
    parent.clear();
    cost.clear();
}

void readPairs(MI& readInto) {
    int p; cin >> p;
    for (int i = 0; i < p; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        readInto.insert(make_pair(t1, t2));
    }
}

bool isSnakeOrLadder(int idx, int& value) {
    auto it1 = ladders.find(idx);
    if (it1 != ladders.end()) {
        value = it1->second;
        return true;
    }
    auto it2 = snakes.find(idx);
    if (it2 != snakes.end()) {
        value = it2->second;
        return true;
    }
    return false;
}



vector<int> getNeighbors(int idx, bool& isLadder) {
    vector<int> res;
    int value;
    isLadder = isSnakeOrLadder(idx, value);
    if (isLadder) {
        res.push_back(value);
    } else {
        auto it1 = snakes.find(idx);
        for (int i = 1; i <= 6; i++) {
            res.push_back(idx + i);
        }
    }
    return res;
}

int solve() {
    queue<PI> q;
    set<int> visited;
    q.push(make_pair(1, 0));
    while (!q.empty()) {
        PI p = q.front();
        q.pop();
        if (visited.count(p.first)) continue;
        visited.insert(p.first);
        if (dbg) cout << "Popped off : [" << p.first << "," << p.second << "]\n";
        if (p.first == 100) break;
        bool isLadder = false;
        vector<int> neighbors = getNeighbors(p.first, isLadder);
        int step = isLadder ? 0: 1;
        for (auto it : neighbors) {
            cost.insert(make_pair(it, p.second + step));
            parent.insert(make_pair(it, p.first));
            q.push(make_pair(it, p.second + step));
        }
    }
    if (dbg) {
        int n = 100;
        while (true) {
            auto it = parent.find(n);
            if (it == parent.end()) break;
            cout << "Node: " << n << " has parent: " << it->second << "\n";
            n = it->second;
        }
    }
    int res;
    if (cost.count(100)) {
        res = cost[100];
    } else {
        res = -1;
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        reset();
        readPairs(ladders);
        readPairs(snakes);
        cout << solve() << "\n";
    }
}
