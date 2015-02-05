#include<bits/stdc++.h>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

typedef pair <int, int> PI;
typedef vector <int> VI;
typedef vector <string> VS;

typedef long long LL;
const int SZ = 51;

class Node {
    public:
        int c, px, py;
        Node() {
            c = px = py = -1;
        }
};
class foxAndDots {
    public:
        Node matrix[SZ][SZ];
        int N, M;
        bool visited[SZ][SZ];

        bool insertNeighbors(PI t, queue<PI> &q) {
            vector <PI> neigh;
            neigh.push_back(make_pair(t.first, t.second -1));
            neigh.push_back(make_pair(t.first, t.second +1));
            neigh.push_back(make_pair(t.first -1, t.second));
            neigh.push_back(make_pair(t.first +1, t.second));
            REP (i, neigh.size()) {
                PI p = neigh[i];
                if (p.first < 0 || p.second < 0 || p.first >= N || p.second >= M || (matrix[p.first][p.second].c != matrix[t.first][t.second].c) ) continue;
                if (matrix[t.first][t.second].px == p.first && matrix[t.first][t.second].py == p.second) continue;
                if (visited[p.first][p.second]) return true;
                matrix[p.first][p.second].px = t.first;
                matrix[p.first][p.second].py = t.second;
                q.push(p);
            }
            return false;
        }

        void start() {
            cin >> N >> M;
            REP (i, N) {
                string s;
                cin >> s;
                REP (j, M) {
                    matrix[i][j].c = s[j];
                }
            }
            REP (i, N) {
                REP (j, M) {
                    memset(visited, 0, sizeof(bool) * SZ * SZ);
                    queue <PI> q;
                    q.push(make_pair(i, j));
                    PI last;
                    while (!q.empty()) {
                        PI t = q.front();
                        q.pop();
                        if (visited[t.first][t.second]) continue;
                        last = t;
                        visited[t.first][t.second] = true;
                        if(insertNeighbors(t, q)) {
                            cout << "Yes\n";
                            return;
                        }
                    }
                }
            }
            cout << "No\n";
        }    
};

foxAndDots t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
