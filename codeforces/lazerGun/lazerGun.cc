#include<bits/stdc++.h>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

typedef pair <int, int> PI;
typedef vector <int> VI;
typedef vector <string> VS;

typedef long long LL;
const int SZ = 1000;
class lazerGun {
public:
    bool visited[SZ];
    PI vertex[SZ];
    void start() {
        int n, p, q;
        memset(visited, 0, sizeof(bool) * SZ);
        cin >> n >> p >> q;
        REP (i, n) {
            int r, s;
            cin >> r >> s;
            vertex[i] = make_pair(r- p, s - q);
        }
        
        int res = 0;
        for (int  i = 0; i < n; i++) {
            if (visited[i]) continue;
            PI c = vertex[i];
            res++;
            visited[i] = true;
            for (int j = i + 1; j < n; j++) {
                if (visited[j]) continue;
                PI d = vertex[j];
                if (d.second * c.first == d.first * c.second) {
                    visited[j] = true;
                }
            }
        }
        cout << res << "\n";
    }    
};

lazerGun t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
