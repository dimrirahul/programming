#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstring>

using namespace std;
const int SZ = 100;
class UnDirectedGraphCycleFinder {
    public:
        bool mat[SZ][SZ];
        int parent[SZ];
        bool visited[SZ];

        int N;
        void start() {
            memset(mat, 0, sizeof(bool) * SZ * SZ);
            for (int i = 0 ;i < SZ; i++) {
                parent[i] = -1;
                visited[i] = false;
            }
            string inp;
            int id = 0;
            while(cin >> inp) {
                N = inp.size();
                for (int i = 0; i < N; i++) {
                    if (inp[i] == '1') mat[id][i] = true;
                }
                id++;
            }

            for (int i = 0; i < N; i++) {
                if (!visited[i]) {
                    if (hasCycles(i)) {
                        cout << "has cycles\n";
                        return;
                    }
                }
            }
            cout << "No Cycles\n";
        }

        bool hasCycles(int id) {
            queue<int> q;
            q.push(id);
            while (!q.empty()) {
                int n = q.front();
                q.pop();
                if (visited[n]) continue;
                visited[n] = true;
                for (int i = 0; i < N; i++) {
                    if (mat[n][i]) {
                        if (visited[i]) {
                            if (parent[n] != i) return true;
                        } else {
                            parent[i] = n;
                            q.push(i);
                        }
                    }
                }
            }
            return false;
        }
};
 UnDirectedGraphCycleFinder udf;
 int main() {
    udf.start();
    return 0;
 }
