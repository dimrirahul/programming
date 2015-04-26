#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>

#define REP(I, N) for (int I = 0; I < (N); ++I)

using namespace std;
const int SZ = 100;
const int W = 10;
class Rmq {
    public:
        int table[SZ][W];
        int values[SZ];
        int items;

        int findLog(int v) {
            int res = 0;
            while (v > 1) {
                res++;
                v /= 2;
            }
            return res;
        }
        void buildTable(int (&values)[SZ]) {
            for (int i = 0; i < items; i++) {
                int logLen = 0;
                while ( (1 << logLen) + i <= items ) {
                    if (logLen == 0) {
                        table[i][logLen] = values[i];
                    } else {
                        int start = 1 << (logLen -1);
                        int end = 1 << logLen;
                        printf("i=%d, logLen=%d, start=%d, end=%d\n", i, logLen, start, end);
                        for (int k = start; k < end; k++) {
                            table[i][logLen] = max(max(table[i][logLen], table[i][logLen-1]), values[i + k]);
                        }
                    }
                    logLen++;
                }
            }
        }
        void printTable() {
            REP (i, items) printf("%2d ", values[i]);
            printf("\n");
            REP (i, items) {
                REP (j, W) {
                    printf("%2d ", table[i][j]);
                }
                printf("\n");
            }
        }

        int query(int start, int end) {
            int l = findLog(end - start);
            printf("start=%d end=%d l=%d v1=%d v2=%d\n", start, end, l, table[start][l], table[end - (1 << l)][l]);
            return max(table[start][l], table[end - (1 << l)][l]);
        }
        int start() {
            memset(table, 0, sizeof(int) * SZ * W);
            items = 0;
            int v;
            cin >> v;
            REP (i, v) {
                int t;
                cin >> t;
                values[items++] = t;
            }
            buildTable(values); 
            printTable();
            int q;
            cin >> q;
            REP (i, q) {
                int x, y;
                cin >> x >> y;
                printf("x=%d, y=%d ans=%d\n", x, y, query(x, y));
            }
            return 0;
        }
};

Rmq rmq;
int main(int argc, char **argv) {
    rmq.start();
    return 0;
}
