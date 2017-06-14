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
    }
}

int countConnectedComponents(MVI& adjList, int numCities) {
    int res = 0;
    set<int> visited;
    stack<int> stk;
    for (int i = 1; i <= numCities; i++) {
        if (visited.count(i) > 0) continue;
        pair<int, int> citiesAndEdgesTuple {0, 0};
        stk.push(i);
        citiesAndEdgesTuple.first++;
        while (!stk.empty()) {
            int v = stk.top();
            stk.pop();
            visited.insert(v);
            if (visited.count(v) > 0 || adjList.count(v) == 0) continue;
            const VI& neighbors = adjList[v];
            for_each(ALL(neighbors), [&stk, &citiesAndEdgesTuple](const int& t1){stk.push(t1); citiesAndEdgesTuple});
        }
    }
    return res;
}

int getResult(int numCities, int numRoads, int cl, int cr) {
    MVI adjList;
    populateAdjList(numRoads, adjList);
    int cc = countConnectedComponents(adjList, numCities);
    return cl + (cc - 1) * (min(cl, cr));
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
