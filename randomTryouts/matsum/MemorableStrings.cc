#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int SZ = 21;
const int INF = (int)1e9;
class E {
    public:

        int N, M;
        vector <string> matrix;
        int cost[SZ][SZ], subValues[SZ][SZ], masks[SZ][SZ];
        int dp[1 << SZ];


    
        void populateSubValues() {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    int maxSubCost = 0;
                    for (int k = 0; k < N; k++) {
                        if (matrix[k][j] == matrix[i][j]) {
                            masks[i][j] |= 1 << k;
                            subValues[i][j] += cost[k][j];
                            maxSubCost = max(maxSubCost, cost[k][j]);
                        }
                    }
                    subValues[i][j] -= maxSubCost;
                }
            }
        }

        int getLowBit(int x) {
            int res = 0;
            while ((x & 1) == 0 && res <= M) {
                x = x >> 1;
                res++;
            }
            if (res == M) res = 0;
            return res;
        }

        void start() {
            memset(subValues, 0, sizeof(int) * SZ * SZ);
            memset(masks, 0, sizeof(int) * SZ * SZ);
            cin >> N >> M;
            for (int i = 0; i < N; i++) {
                string s;
                cin >> s;
                matrix.push_back(s);
            }
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    cin >> cost[i][j];
                }
            }

            populateSubValues();
            
            for (int i = 0; i < (1 << N); i++) dp[i] = INF;
            dp[0] = 0;
            for (int i = 1; i < (1 << N); i++) {
                int lowBit = getLowBit(i);
                for (int j = 0; j < M; j++) {
                    dp[i] = min (dp[i], dp[i & (i ^ masks[lowBit][j])] + subValues[lowBit][j]);
                    dp[i] = min (dp[i], dp[i ^ (1 << lowBit)] + cost[lowBit][j]);
                }
            }
            printf("%d\n", dp[(1 << N) -1]);

        }
};


E e;
int main(int argc, char **argv) {
    e.start();
    return 0;
}
