#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;
//lets say that we can keep atmost 10^5 sets.
const int SZ = (int) 1e5;
class UnionFind {
    //Everything public
    public:
        int parent[SZ];
        int rank[SZ];
        //Creates a set of size one and value as 'v' and assigns the representative to itself
        void createSet(int v) {
            parent[v] = v;
            rank[v] = 1;
        }

        //Merges two sets that have representatives as r1 and r2
        //essentially merges r2 into r1.
        void merge(int r1, int r2) {
            if (rank[r1] < rank[r2]) swap(r1, r2);
            else if (rank[r1] == rank[r2]) rank[r1]++;
            rank[r2] = -1;
            parent[r2] = r1;
        }

        //Returns the representative of the set.
        int find(int v1) {
            while (parent[v1] != v1) v1 = parent[v1];
            return v1;
        }
        void printParents() {
            cout << "===========\n";
            for (int i = 0; i < SZ; i++) {
                if (parent[i] != -1) {
                    printf("element, parent, rank = [%d, %d, %d]\n", i, parent[i], rank[i]);
                }
            }
        }

        UnionFind() {
            for (int i = 0; i < SZ; i++) {
                parent[i] = rank[i] = -1;
            }
        }
};

UnionFind uf;

vector < pair <int, int> > getLinks() {
    vector < pair <int, int> > vpi;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int x, y;
        cin >> x >> y;
        vpi.push_back(make_pair(x, y));
    }
    return vpi;
}
vector<int> getInputs() {
    vector<int> v;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int u;
        cin >> u;
        v.push_back(u);
    }
    return v;
}
int main(int argc, const char *argv[]) {

    vector <int> v = getInputs();
    for (int i = 0; i < v.size(); i++) {
        uf.createSet(v[i]);
    }
    uf.printParents();
    vector < pair <int, int> > vpi = getLinks();
    for (int i = 0; i < vpi.size(); i++) {
        uf.merge(uf.find(vpi[i].first), uf.find(vpi[i].second));
    }
    uf.printParents();
    return 0;
}
