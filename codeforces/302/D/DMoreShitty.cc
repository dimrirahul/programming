#include<bits/stdc++.h>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define FORU(I,A,B) for(unsigned int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define REPU(I,N)   FORU(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

typedef pair <int, int> PI;
typedef vector <int> VI;
typedef vector <string> VS;

typedef long long LL;
const int SZ = 3010;
const int INF = INT_MAX;
const bool dbg = !true;
class D {
public:
    int dp[SZ][SZ];
    int matrix[SZ][SZ];
    int N, M, S1, T1, L1, S2, T2, L2;


    void doBfs(int start) {
        queue<PI> q;
        q.push(make_pair(start, 0));
        unordered_set<int> visited;
        while (!q.empty()) {
            PI p = q.front();
            if (dbg) {
                cout << "Popped " << p.first << " From q, its distance = " << p.second << "\n";
            }
            q.pop();
            if (visited.count(p.first) > 0) continue;
            visited.insert(p.first);
            dp[start][p.first] = dp[p.first][start] = p.second;

            for (int i = p.first+1 ; i < N; i++) {
                if (matrix[p.first][i] == 1 && visited.count(i) == 0) {
                    if (dbg) {
                        cout << "Adding " << i << " its depth = " << p.second +1 << "\n";
                    }
                    q.push(make_pair(i, p.second+1));
                }
            }
        }
    }

    void populateAllPairShortestPaths() {
        REP(i, N) {
            doBfs(i);
        }
    }

    void printMinD() {
        REP(i, N) {
            REP(j, N) {
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }
    }

    void start() {
        REP(i, SZ) REP(j, SZ) {
            dp[i][j] = INF;
            matrix[i][j] = 0;
        }
        cin >> N >> M;
        REP (i, M) {
            int x, y;
            cin >> x >> y;
            x--; y--;
            matrix[x][y] = matrix[y][x] =1;
        }
        cin >> S1 >> T1 >> L1;
        cin >> S2 >> T2 >> L2;
        S1--; S2--; T1--; T2--;
        populateAllPairShortestPaths();
        printMinD();
        if (dp[S1][T1] > L1 || dp[S2][T2] > L2) {
            cout << "-1\n"; 
            return;
        }
        int res = M - dp[S1][T1] - dp[S2][T2];
        REP(i, N) {
            for (int j = i + 1; j < N; j++) {
                if ((dp[S1][i] + dp[T1][j] + dp[i][j] <= L1) && (dp[S2][i] + dp[T2][j] + dp[i][j] <= L2)) {
                    res = max(res, M - (dp[S1][i] + dp[S2][i] + dp[i][j] + dp[T1][j] + dp[T2][j]));
                    res = max(res, M - (dp[S1][i] + dp[S2][j] + dp[i][j] + dp[T1][j] + dp[T2][i]));
                    if (dbg) {
                        cout << "Res = " << res << "i= " << i << " j= " << j << "\n";
                    }
                }
            }
        }
        cout << res << "\n";
    }    
};

D t;
int main(int argc, char **argv) {
    t.start();
    return 0;
}

