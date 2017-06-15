#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>

using namespace std;
using VI = vector<int>;
using MVI = unordered_map<int, VI>;

#define FORN(I,N) for (int (I) = 0; (I) < (N); (I)++)
#define ALL(X) (X).begin(), (X).end()

const bool dbg = !true;

void addEdge(MVI& adjList, int v1, int v2) {
    auto it = adjList.find(v1);
    if (it != adjList.end()) it->second.push_back(v2);
    else {
        VI vi;
        vi.push_back(v2);
        adjList.emplace(make_pair(v1, vi));
    }
}

void populateAdjList(int numRoads, MVI& adjList) {
    FORN (i, numRoads) {
        int v1, v2;
        cin >> v1 >> v2;
        addEdge(adjList, v1, v2);
        addEdge(adjList, v2, v1);
    }
}

VI countConnectedComponents(MVI& adjList, int numCities) {
    VI res;
    set<int> visited;
    stack<int> stk;
    for (int i = 1; i <= numCities; i++) {
        if (visited.count(i) > 0) continue;
        int countCities = 0;
        stk.push(i);
        while (!stk.empty()) {
            int v = stk.top();
            stk.pop();
            if (visited.count(v) > 0) continue;
            countCities++;
            visited.insert(v);
            const VI& neighbors = adjList[v];
            for_each(ALL(neighbors),
                    [&stk](const int& t1){
                        stk.push(t1);
                    }
            );

        }
        res.push_back(countCities);

    }
    return res;
}

long long getResult(int numCities, int numRoads, int cl, int cr) {
    MVI adjList;
    populateAdjList(numRoads, adjList);
    VI vi = countConnectedComponents(adjList, numCities);
    long long res = 0;
    for (auto it : vi) {
        if (dbg) cout << it << ',';
        res += cl + (it -1) * min(cl, cr);
    }
    if (dbg) cout << "\n";
    return res;
}
int main() {
    int t;
    cin >> t;
    FORN (i, t) {
        int numCities, numRoads, cr, cl;
        cin >> numCities >> numRoads >> cl >> cr;
        cout << getResult(numCities, numRoads, cl, cr) << "\n";
    }
    return 0;
}
