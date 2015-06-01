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

const int SZ = 505;
const bool dbg = false;
typedef long long LL;
class B {
public:

    int matrix[SZ][SZ];
    int n, m, q;
    int result[SZ];
    int getToklen(int r, int start) {
        int res = 0;
        while (start < m && matrix[r][start] == 1) {
            start++;
            res++;
        }
        if (dbg) printf("==> row =%d, token=%d return=%d\n", r, start, res);
        return res;
    }

    int getCount(int r) {
        int res = 0;
        int startPos = 0;
        while (startPos < m) {
            int currCount = getToklen(r, startPos);
            startPos += currCount;
            startPos++;
            res = max(res, currCount);
        }
        if (dbg) printf("row=%d, count=%d\n", r, res);
        return res;
    }

    int getMax() {
        int res = 0;
        REP(i, n) {
            res = max(res, result[i]);
        }
        return res;
    }
    void start() {
        memset(matrix, 0, sizeof(int) * SZ * SZ);
        memset(result, 0, sizeof(int) * SZ);
        cin >> n >> m >> q;
        REP(i, n) {
            REP(j, m) {
                cin >> matrix[i][j];
            }
            result[i] = getCount(i);
        }

        REP (i, q) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            matrix[a][b] = !matrix[a][b];
            result[a] = getCount(a);
            cout << getMax() << "\n";
        }
    }    
};

B t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
