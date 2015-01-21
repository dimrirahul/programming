#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <cstring>


using namespace std;
const int MAX_E = 101;
class PM {
    public:
        int adjMatrix[MAX_E][MAX_E][MAX_E];
        int res[MAX_E][MAX_E];
        int nV, nE;
        int maxC;
        vector<pair <int, int> > queries;

        void start() {
            memset(adjMatrix, 0, sizeof(adjMatrix[0][0][0]) * MAX_E * MAX_E * MAX_E);
            memset(res, 0, sizeof(res[0][0]) * MAX_E * MAX_E);
            scanf("%d %d\n", &nV, &nE);
            maxC = 0;
            for (int i = 0; i < nE; i++) {
                int a, b, c;
                scanf("%d %d %d\n", &a, &b, &c);
                adjMatrix[a][b][c]++;
                adjMatrix[b][a][c]++;
                maxC = max(maxC, c);
            }
            int temp;
            scanf("%d\n", &temp);
            for (int i = 0; i < temp; i++) {
                int a, b;
                scanf("%d %d\n", &a, &b);
                queries.push_back(make_pair(a, b));
            }
            solve();
        }

        void solve() {
            for (int i = 0; i < queries.size(); i++) {
                pair <int, int> p = queries[i];
                if (res[p.first][p.second] == 0) {
                    for (int j = 1; j <= nE; j++) {
                        //printf("Source=%d, Dest=%d, color=%d\n", p.first, p.second, j);
                        queue<int> q;
                        set<int> visited;
                        q.push(p.first);
                        while (!q.empty()) {
                            int n = q.front();
                            //printf("Extracting %d from q\n", n);
                            q.pop();
                            if (n == p.second) {
                               // printf("Match found source=%d dest=%d\n", p.first, p.second);
                                res[p.first][p.second]++;
                                res[p.second][p.first]++;
                                break;
                            }
                            if (visited.count(n) > 0) continue;
                            visited.insert(n);
                            for (int k = 1; k <= nV; k++) {
                                if (adjMatrix[n][k][j] && (visited.count(k) == 0)) {
                                    //printf("pushing  %d neighbor of source %d in q\n", k, n);
                                    q.push(k);
                                }
                            } 
                        }
                    }
                }
                printf("%d\n", res[p.first][p.second]);
            }
        }
};
PM pm;
int main(int argc, char **Argv) {
    pm.start();
    return 0;
}
