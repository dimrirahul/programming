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
const int SZ = 109;
class B {
public:
    int island[SZ][SZ];
    int n, k;
    bool isPossible(int i, int j) {
        return checkCell(i-1, j) && checkCell(i+1, j) && checkCell(i, j-1) && checkCell(i, j+1);
    }

    bool checkCell(int i, int j) {
        if ( i < 0 || j < 0 || i == n || j == n) return true;
        return island[i][j] != 1;
    }
    void start() {
        memset(island, 0, sizeof(int) * SZ * SZ);
        cin >> n >> k;
        int countIsland = 0;
        for (int i = 0; i < n && countIsland != k; i++) {
            for (int j = 0; j < n && countIsland != k; j++) {
                if (isPossible(i, j)) {
                    island[i][j] = 1;
                    countIsland++;
                }
            }
        }
        if (countIsland != k) {
            cout << "NO\n";
            return;
        }
        cout << "YES\n";
        REP(i, n) {
            REP(j, n) {
                if (island[i][j] == 1) {
                    cout << "L";
                } else {
                    cout << "S";
                }
            }
            cout << "\n";
        }
    }    
};

B t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
