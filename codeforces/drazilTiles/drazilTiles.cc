#include<bits/stdc++.h>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

typedef pair <int, int> PI;
typedef vector <int> VI;
typedef vector <string> VS;

typedef long long LL;
const int SZ = 2001;
class drazilTiles {
    public:
        int pts[SZ][SZ];
        vector<string> res;
        int N, M;
        int rcToP(int r, int c) {
            return r * M + c;
        }

        PI pToRC(int p) {
            return make_pair(p / M, p % M);
        }
        vector<int> getNeighbors(int r, int c) {
            vector<int> res;
            int xar[] = {-1, 1, 0, 0};
            int yar[] = {0, 0, -1, 1};
            REP(i, 4) {
                int nr = r + xar[i];
                int nc = c + yar[i];
                if (nr < 0 || nr >= N || nc >= M || nc < 0) continue;
                if (pts[nr][nc] > 0) {
                    res.push_back(rcToP(nr, nc));
                } 
            }
            return res;
        }
        bool areHorizontalNeighbors(PI p1, PI p2) {
            return abs(p1.first - p2.first) == 0;
        }

        bool areHorizontalNeighbors(int p1, int p2) {
            return areHorizontalNeighbors(pToRC(p1), pToRC(p2));
        }

        void printPts() {
            cout << "===\n";
            REP(i, N) {
                REP(j, M) {
                    printf("%2d ", pts[i][j]);
                }
                printf("\n");
            }
        }
        void start() {
            cin >> N >> M;
            REP (i, N) {
                REP (j, M) {
                    pts[i][j] = 4;
                    if (i == 0) pts[i][j]--;
                    if (i == N-1) pts[i][j]--;
                    if (j == 0) pts[i][j]--;
                    if (j == M-1) pts[i][j]--;
                }
            }
            //printPts();
            REP (i, N) {
                string s;
                cin >> s;
                res.push_back(s);
                REP (j, s.size()) {
                    if (s[j] == '*') {
                        vector<int> nei = getNeighbors(i, j);
                        REP (k, nei.size()) {
                            PI p = pToRC(nei[k]);
                            pts[p.first][p.second]--;
                        }
                        pts[i][j] = 0;
                    }
                }
            }
            //printPts();
            queue<int> q;
            REP (i, N){
                REP (j, M) {
                    if (pts[i][j] == 1) q.push(rcToP(i, j));
                }
            }
            while (!q.empty()) {
                int t = q.front();
                q.pop();
                PI p = pToRC(t);
                if (pts[p.first][p.second] == 1) {
                    pts[p.first][p.second] = 0;
                    vector<int> nei = getNeighbors(p.first, p.second);
                    REP(k, nei.size()) {
                        PI p1 = pToRC(nei[k]);
                        if (areHorizontalNeighbors(t, nei[k])) {
                            int start = min(p.second, p1.second);
                            res[p.first][start] = '<';
                            res[p.first][start+1] = '>';
                        } else {
                            int start = min(p.first, p1.first);
                            res[start][p.second] = '^';
                            res[start+1][p.second] = 'v';
                        }
                        pts[p1.first][p1.second] = 0;

                        vector<int> nn = getNeighbors(p1.first, p1.second);
                        REP (l, nn.size()) {
                            PI p2 = pToRC(nn[l]);
                            pts[p2.first][p2.second]--;
                            if (pts[p2.first][p2.second] == 1) {
                                q.push(nn[l]);
                            }
                        }
                        break;
                    }
                }
            }
            //printPts();
            bool good = true;
            REP(i, res.size()) {
                REP (j, res[i].size()) {
                    if (res[i][j] == '.') {
                        good = false;
                        break;
                    }
                }
            }
            if (good) {
                REP (i, res.size()) {
                    cout << res[i] << "\n";
                }
            } else {
                cout << "Not unique\n";
            }
        }
};

drazilTiles t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
