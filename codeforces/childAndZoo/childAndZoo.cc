#include<bits/stdc++.h>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

typedef pair <int, int> PI;
typedef vector <int> VI;
typedef vector <string> VS;

typedef long long LL;

const int SZ = ((int) 1e5 ) + 1;
class Comp {
public:
    bool operator()(pair <int, int> x1, pair <int, int> x2) const {
        if (x1.second != x2.second) return x1.second > x2.second;
        return x1.first > x2.first;
    }
};
class childAndZoo {
public:
    vector < pair <int, int> > areas;
    map<int, vector <int> > adjList;
    map<int, vector <int> > nodesInTree;
    map<pair <int, int>, int> resMap;
    int parent[SZ];
    int rank[SZ];
    int weight[SZ];
    int N, M;
    void addEdge(int a, int b) {
        if (adjList.count(a) == 0 ) adjList[a] = vector<int>();
        if (adjList.count(b) == 0) adjList[b] = vector<int>();
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    void createNode(int n) {
        parent[n] = n;
        rank[n] = 1;
        vector <int> v;
        v.push_back(n);
        nodesInTree[n] = v;
    }

    int find(int n) {
        while (parent[n] != n) n = parent[n];
        return n;
    }

    void merge(int r1, int r2) {
        if (rank[r1] < rank[r2]) swap(r1, r2);
        else if (rank[r1] == rank[r2]) rank[r1]++;
        parent[r2] = r1;
        rank[r2] = -1;
        nodesInTree[r1].insert(ALL(nodesInTree[r2]));
        nodesInTree.erase(r2);
    }
    bool hasParent(int n) {
        return parent[n] != -1;
    }
    void calculateValues() {
        for (int i = 0; i < areas.size(); i++) {
            pair <int, int> &node = areas[i];
            if (hasParent(node.first)) continue;
            createNode(node.first);
            vector <int> &neighs = adjList[node.first];
            for (int j = 0; j < neighs.size(); j++) {
                int mySet = find(node.first);
                if (!hasParent(neighs[j])) {
                    createNode(neighs[j]);
                    resMap[make_pair(min(node.first, neighs[j]), max(node.first, neighs[j]))] = min(node.second, weight[neighs[j]]);
                    merge(find(node.first), find(neighs[j]));
                    continue;
                }
                int neighSet = find(neighs[j]);
                if (mySet != neighSet) {
                    vector <int> &v1 = nodesInTree[mySet];
                    vector <int> &v2 = nodesInTree[neighSet];
                    
                }
            }
        }
    }
    void start() {
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
            rank[i] = parent[i] = -1;
            int t;
            cin >> t;
            weight[i] = t;
            areas.push_back(make_pair(i, t));
        }
        for (int i = 0; i < M; i++) {
            int t, t1;
            cin >> t >> t1;
            t--; t1--;
            addEdge(t, t1);
        }
        Comp comp;
        sort(ALL(areas), comp);
        long long t = 0;
        calculateValues();
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
            }
        }



    }    
};

childAndZoo t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
