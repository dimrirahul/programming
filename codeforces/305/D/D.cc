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
const int SZ = (int) (2e5 + 10);
const int WD = 19; 
const int INF = (int) (1e10);
const bool dbg = !true;
class D {
    public:
        int table[SZ][WD];
        VI heights;

        void updateQueryTable() {
            for (int i = 0; (1 << i) < heights.size(); i++) {
                int len = (1 << i);
                for (int j = 0; j < heights.size(); j++) {
                    if (i == 0) {
                        table[j][0] = heights[j];
                    } else {
                        if (j + len > heights.size()) continue;
                        int range = 1 << (i-1);
                        table[j][i] = min(table[j][i-1], table[j + range][i-1]);
                    }
                }
            }
        }

        int logBase2(int num) {
            int res = 0;
            while (num > 1) { 
                num = num >> 1;
                res++;
            }
            return res;
        }
        bool isPowerOf2(int v) {
            for (int i = 0; (1 << i) <= v; i++) {
                if ((1 << i) == v) return true;
            }
            return false;
        }
        int queryTable(int pos, int len) {
            if (len == 1) return table[pos][0];
            int logLen = logBase2(len);
            //logLen /= 2;
            if (isPowerOf2(len)) return table[pos][logLen];
            return min(table[pos][logLen], table[pos + len - (1 << logLen)][logLen]);
        }
        void printQueryTable() {
            REP(i, heights.size()) {
                for (int j = 0; j < WD; j++) {
                    if (table[i][j] != INF) cout << table[i][j] << " ";
                    else {
                        cout << "\n";
                        break;
                    }
                }
            }
        }

        void printResult() {
            for( int i = 1; i <= heights.size(); i++) {
                int res = 0;
                for( int j = 0; j < heights.size(); j++) {
                    if (i + j > heights.size()) break;
                    res = max(res, queryTable(j, i));
                }
                cout << res << " ";
            }
        }
        void start() {
            int t;
            cin >> t;
            REP(i, SZ) REP(j, WD) table[i][j] = INF;
            REP(i, t) {
                int u; cin >> u;
                heights.push_back(u);
            }
            updateQueryTable();
            if (dbg)  printQueryTable();
            printResult();
            //cout << "\n" << queryTable(2, 4) << "\n";
        }    
};

D t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
