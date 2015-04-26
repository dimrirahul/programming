#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>

using namespace  std;

const int MAX_SIZE = 100001;
const int MAX_WIDTH = 18;
class drazilTree
{
public:
    int N, M;
    int up[MAX_SIZE], down[MAX_SIZE];
    int rmqUp[MAX_SIZE][MAX_WIDTH], rmqDown[MAX_SIZE][MAX_WIDTH];
    map<int, int> logCache;

    int findLog(int k) {
        if (k == 1) return 0;
        if (logCache.count(k) > 0) {
            return logCache[k];
        }
        logCache[k] = 1 + findLog(k/2);
        return logCache[k];
    }
    void buildRmqTable(int (&table)[MAX_SIZE][MAX_WIDTH], int R, int C, int (&data)[MAX_SIZE]) {
        memset(table, 0, sizeof(int) * MAX_SIZE * MAX_WIDTH);
        for (int i = 0; i < R; ++i) {
            for (int j = 1 ; i + j <= R; j++) {
                int l = findLog(j);
                if (l == 0) {
                    table[i][l] = data[i];
                } else {
                    int v = max (table[i][l], table[i][l-1]);
                    table[i][l] = max (v, data[i + j - 1]);
                }
            }
        }
    }

    void queryTable(int (&table)[MAX_SIZE][MAX_WIDTH], int start, int end) {
        int l = findLog(end - start);
        return max(table[start][l], table[end - (1 << l)][l]);
    }
    void start() {
        cin >> N >> M;
        for (int i = 0; i < N; ++i) {
            int d;
            cin >> d;
            up[i] = down[i] = d;
            if (i > 0) {
                up[i] += up[i-1];
                down[i] += down[i-1];
            }
        }
        for (int i = 0; i < N; ++i) {
            int h;
            cin >> h;
            up[i] += 2 * h;
            down[i] = 2 * h - down[i];
        }
        buildRmqTable(rmqUp, N, M, up);
        buildRmqTable(rmqDown, N, M, down);
        REP (i, M) {
            int a, b;
            cin >> a >> b;
            int res = 0;
            if (a < b) {
                res = queryTable(rmqDown, 0, a) + queryTable(rmqUp, b, N); 
            } else if (a > b) {
                
            }
        }
    }
};

drazilTree dt;
int main(int argc, char const *argv[])
{
    dt.start();
    return 0;
}
