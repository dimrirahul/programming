#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <sstream>
#include <stack>

using namespace std;
const int SZ = 101;
class Triple {
    public:
        int f, s, t;
        Triple() {f = s = t = -1;}
        Triple(int _f, int _s, int _t) {
            f = _f;
            s = _s;
            t = _t;
        }
        bool operator<(Triple o) const {
            if (f != o.f) return f < o.f;
            if (s != o.s) return s < o.s;
            return t < o.t;
        }
};
class Scc {
    public:
        int N;
        bool matrix[SZ][SZ];
        Triple visited[SZ];
        int idx;
        int compId;
        stack<int> s;
        bool isInStack[SZ];
        void populateMatrix() {
            memset(matrix, 0, sizeof(bool) * SZ * SZ);
            memset(isInStack, 0, sizeof(bool) * SZ);
            string inp;
            idx = compId = 0;
            int r = 0;
            while(cin >> inp) {
                N = inp.size();
                for (int i = 0; i < inp.size(); i++) {
                    if (inp[i] == '1') matrix[r][i] = true;
                }
                r++;
            }
        }
        void findScc() {
            for (int i = 0; i < N; i++) {
                if (visited[i].f == -1) {
                    cout << "Node id = " << i << " has not yet been visited\n";
                    addNode(i);
                }
            }
        }

        void addNode(int nodeId) {
            cout << " Adding nodeid = " << nodeId << "\n";
            visited[nodeId].f = visited[nodeId].s = idx++;
            s.push(nodeId);
            isInStack[nodeId] = true;
            for (int j = 0 ;j < N; j++) {
                if (matrix[nodeId][j]) {
                    if (visited[j].f == -1) {
                        addNode(j);
                        visited[nodeId].s = min(visited[nodeId].s, visited[j].s);
                    } else if (isInStack[j]){
                        visited[nodeId].s = min(visited[nodeId].s, visited[j].f);
                    }
                }
            }
            if (visited[nodeId].s == visited[nodeId].f) {
                stringstream ss; 
                ss << "Component = " << compId++ << " "; 
                int n;
                do {
                    n = s.top();
                    s.pop();
                    isInStack[n] = false;
                    ss << " " << n + 1 ;
                } while (n != nodeId);

                cout << ss.str() << "\n";
            }
        }
};
Scc c;
int main(int argc, char **Argv) {
    c.populateMatrix();
    c.findScc();
    return 0;
}
